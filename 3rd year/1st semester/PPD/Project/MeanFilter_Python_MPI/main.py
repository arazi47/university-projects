import os

from PIL import Image
from mpi4py import MPI

image = Image.open('test.jpg')
pixels = image.load()
width, height = image.size

comm = MPI.COMM_WORLD
size = comm.Get_size()
print('size = ', size)


def master(rank):
    chunk_size = (height + size - 1) // size  # Each thread will do chunk_size rows

    # 0 is master
    # Send from 1 to n - 1 the data
    for i in range(1, size):
        # https://stackoverflow.com/a/36689048
        start = i * chunk_size
        end = min(start + chunk_size, height)
        comm.send((start, end), dest=i)

    start = 0 * chunk_size
    end = min(start + chunk_size, height)
    print("Master with rank {} has to do from {} to {}".format(rank, start, end))

    for v in range(1, width):
        for u in range(1, end):
            sumr = sumg = sumb = 0
            for j in range(-1, 1 + 1):
                for i in range(-1, 1 + 1):
                    if u + j < height and v + i < width:
                        pixel = image.getpixel((v + i, u + j))
                        rr = pixel[0]
                        rg = pixel[1]
                        rb = pixel[2]
                        sumr += rr
                        sumg += rg
                        sumb += rb

            # 3x3 kernel, value for each cell is 1/9
            sumr //= 9
            sumg //= 9
            sumb //= 9
            image.putpixel((v, u), (sumr, sumg, sumb))

    # Wait for all threads to finish and gather their data
    for i in range(1, size):
        pixels_to_put = comm.recv(source=i)
        for e in pixels_to_put:
            image.putpixel((e[0], e[1]), (e[2], e[3], e[4]))

    # Save the output
    image.save('out.jpg')
    print("Finished!")


def worker(rank):
    data = comm.recv(source=0)
    print("Worker with rank {} has to do from {} to {}".format(rank, data[0], data[1]))

    pixels_to_put = []

    for v in range(1, width):
        for u in range(data[0], data[1]):
            sumr = sumg = sumb = 0
            for j in range(-1, 1 + 1):
                for i in range(-1, 1 + 1):
                    if u + j < height and v + i < width:
                        pixel = image.getpixel((v + i, u + j))
                        rr = pixel[0]
                        rg = pixel[1]
                        rb = pixel[2]
                        sumr += rr
                        sumg += rg
                        sumb += rb

            # 3x3 kernel, value for each cell is 1/9
            sumr //= 9
            sumg //= 9
            sumb //= 9
            pixels_to_put.append((v, u, sumr, sumg, sumb))

    comm.send(pixels_to_put, dest=0)


def main():
    rank = comm.Get_rank()
    if rank == 0:
        master(rank)
    else:
        worker(rank)


# Usage: mpiexec -n 2 py main.py
if __name__ == '__main__':
    main()

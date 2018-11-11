import socket

IP_ADDR = "127.0.0.1"
PORT = 1234

# client socket
cs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def send_msg(msg):
    cs.sendto(msg.encode(), (IP_ADDR, PORT))

while True:
    target_num = input("Input number: ")
    send_msg(target_num)

    data, addr = cs.recvfrom(1)
    print("Got message {}".format(data.decode()))

    if data.decode() == "W":
        cs.close()
        break

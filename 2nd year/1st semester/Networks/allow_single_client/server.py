import socket

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    s.bind(('127.0.0.1', 1234))
    s.listen(1)
    conn, addr = s.accept()
    print("CONNECTION ACCEPTED")

    while True:
        a = input("INPUT A: ")
        b = input("INPUT B: ")
        conn.send(a.encode())
        conn.send(b.encode())

        if int(a) == -1 and int(b) == -1:
            break

    s.close()


if __name__ == '__main__':
    main()
import socket

IP_ADDR = "127.0.0.1"
PORT = 1234

# server socket
ss = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ss.bind((IP_ADDR, PORT))


def send_msg(msg, addr = (IP_ADDR, PORT)):
    ss.sendto(msg.encode(), addr)


target_num = 34
print("target_num = {}".format(target_num))

while True:
    data, addr = ss.recvfrom(1024)
    print("Got message: {}".format(data.decode()))

    if int(data.decode()) < target_num:
        send_msg("H", addr)
    elif int(data.decode()) > target_num:
        send_msg("L", addr)
    else:
        send_msg("W", addr)
        ss.close()
        break

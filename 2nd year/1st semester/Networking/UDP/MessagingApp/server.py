import socket
import threading

IP_ADDR = "127.0.0.1"
PORT = 1234

# server socket
ss = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ss.bind((IP_ADDR, PORT))

data, client_address = ss.recvfrom(5)
print(data.decode())

def run_thread():
    while True:
        data, addr = ss.recvfrom(1024)
        print("\nClient: {}".format(data.decode()))
        print(">>> [SERVER] Send message: ",)

threading.Thread(target=run_thread).start()


def send_msg(msg, addr = (IP_ADDR, PORT)):
    ss.sendto(msg.encode(), addr)


while True:
    print(">>> [SERVER] Send message:",)
    txt = input()
    send_msg(txt, client_address)


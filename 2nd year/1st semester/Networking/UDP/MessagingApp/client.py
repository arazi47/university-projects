import socket
import threading

IP_ADDR = "127.0.0.1"
PORT = 1234

# client socket
cs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def send_msg(msg):
    cs.sendto(msg.encode(), (IP_ADDR, PORT))

send_msg("START")

def run_thread():
    while True:
        data, addr = cs.recvfrom(1024)
        print("\nServer: {}".format(data.decode()))
        print(">>> [CLIENT] Send message: ",)


threading.Thread(target = run_thread).start()

while True:
    print(">>> [CLIENT] Send message: ",)
    txt = input()
    send_msg(txt)


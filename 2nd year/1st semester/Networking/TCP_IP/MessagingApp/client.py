import socket
import threading

IP_ADDR = "127.0.0.1"
PORT = 1234

# client socket
cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cs.connect((IP_ADDR, PORT))

def send_msg(msg):
    cs.send(msg.encode())

#send_msg("START")

def run_thread():
    while True:
        data = cs.recv(1024).decode()
        print("\nServer: {}".format(data))
        print(">>> [CLIENT] Send message: ",)


threading.Thread(target = run_thread).start()

while True:
    print(">>> [CLIENT] Send message: ",)
    txt = input()
    send_msg(txt)


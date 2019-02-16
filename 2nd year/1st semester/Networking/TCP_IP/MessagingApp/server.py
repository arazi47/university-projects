import socket
import threading

IP_ADDR = "127.0.0.1"
PORT = 1234

# server socket
ss = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ss.bind((IP_ADDR, PORT))
ss.listen(1)

conn, client_address = ss.accept()

def run_thread():
    while True:
        data = conn.recv(1024).decode()
        print("\nClient: {}".format(data))
        print(">>> [SERVER] Send message: ",)

threading.Thread(target=run_thread).start()


def send_msg(msg):
    conn.send(msg.encode())


while True:
    print(">>> [SERVER] Send message:",)
    txt = input()
    send_msg(txt)


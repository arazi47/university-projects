__author__ = 'dadi'

import socket
import threading
import random
import struct
import sys
import time

#random.seed()
#start=1; stop=2**17-1
#my_num= random.randint(start,stop)
#print('Server number: ',my_num)
mylock = threading.Lock()
client_guessed=False
winner_thread=0
e = threading.Event()
e.clear()
threads = []
client_count=0

def worker(cs):
    global mylock, client_guessed, my_num, winner_thread, client_count,e

    my_idcount = client_count

    print('client #',client_count,'from: ',cs.getpeername(), cs )
    message='Hello client #'+str(client_count)+'! Da-i cu spanzuratoarea'
    cs.sendall(message.encode())

    secret_word = "paianjen"
    from collections import Counter
    counts = Counter(secret_word)
    #for i in secret_word:
    #    print(i, counts[i])

    letters_to_guess = len(secret_word)

    cs.sendall(str(letters_to_guess).encode())

    guessed_word = ['_'] * letters_to_guess
    lives = 3

    while not client_guessed:
        try:
            recv_str = cs.recv(1024).decode()
            print("RECEIVED STR = {}".format(recv_str))

            print("Lives: {}.".format(lives))

            recv_str = recv_str.lower()
            if counts[recv_str] == 0:
                lives -= 1

            if lives == 0:
                cs.sendall(str(lives).encode())
                e.set()
                cs.close()

            letters_to_guess = letters_to_guess - counts[recv_str]
            counts[recv_str] = 0
            print("LETTERS TO GUESS IS NOW {}".format(letters_to_guess))

            cs.sendall(str(lives).encode())

            for i in range(len(secret_word)):
                if secret_word[i] == recv_str:
                    guessed_word[i] = recv_str

                    # p a i a n j e n
                    # _ a _ a _ _ _ _

            print("GUESSED WORD IS NOW {}".format(guessed_word))
            print("_____________")

            for i in range(len(guessed_word)):
                cs.sendall(guessed_word[i].encode())
                #time.sleep(0.25)

            if letters_to_guess == 0:
                print("SOMEBODY WON")
                mylock.acquire()
                client_guessed=True
                winner_thread=threading.get_ident()
                mylock.release()
                cs.sendall("1".encode())
            else:
                cs.sendall("0".encode())

        except socket.error as msg:
            print('Error:',msg.strerror)
            break

    #print("ASDFG")
    if client_guessed:
        if threading.get_ident() == winner_thread:
            cs.sendall("WIN".encode())
            print('We have a winner', cs.getpeername())
            print("Thread ",my_idcount," winner")
            e.set()
        else:
            # How to do this?
            #cs.sendall("LOS".encode())
            print("Thread ",my_idcount," loser")
    #else:
        #print("AJG")
        # game continues
        #cs.sendall("c".encode())

    time.sleep(1)
    cs.close()
    print("Worker Thread ",my_idcount, " end")


def resetSrv():
    global mylock, client_guessed, winner_thread, my_num, threads,e, client_count
    while True:
        e.wait()
        for t in threads:
            t.join()
        print("all threads are finished now")
        e.clear()
        mylock.acquire()
        threads = []
        client_guessed = False
        winner_thread=-1
        client_count = 0
        #my_num = random.randint(start,stop)
        #print('Server number: ',my_num)
        mylock.release()


if __name__=='__main__':
    try:
        rs=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rs.bind( ('0.0.0.0',1234) )
        rs.listen(5)
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)
    t=threading.Thread(target=resetSrv, daemon=True)
    t.start()
    while True:
        client_socket,addrc = rs.accept()
        t = threading.Thread(target=worker, args=(client_socket,) )
        threads.append(t)
        client_count+=1
        t.start()
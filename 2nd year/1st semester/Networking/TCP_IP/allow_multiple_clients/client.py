__author__ = 'dadi'
import socket, struct, random,sys, time


if __name__ == '__main__':
    try:
        s = socket.create_connection( ('localhost',1234))
    except socket.error as msg:
        print("Error: ",msg.strerror)
        exit(-1)

    finished = False
    data = s.recv(1024).decode()
    print(data)

    word_len = int(s.recv(1).decode())
    print("GOT WORD LEN = {}".format(word_len))
    current_guessed_word = ['_'] * word_len
    print("Current guessed word: {}.".format(current_guessed_word))

    while not finished:
        try:
            secretstr = input("Input letter: ")
            s.sendall(secretstr.encode())

            lives = int(s.recv(1).decode())
            print("You got {} lives left.".format(lives))
            if lives == 0:
                break

            current_guessed_word = []
            for i in range(word_len):
                current_guessed_word.append(s.recv(1).decode())

            print("Current guessed word: {}.".format(current_guessed_word))

        except socket.error as msg:
            print('Error: ',msg.strerror)
            s.close()
            exit(-2)

        won_or_not = s.recv(1).decode()
        #print("GOT WON OR NOT = {}".format(won_or_not))
        if won_or_not == "1":
            finished = True
            print("Done! The word was {}.".format(''.join(current_guessed_word)))

            end_game_text = s.recv(3).decode()
            print(end_game_text)

        time.sleep(0.25)

    s.close()
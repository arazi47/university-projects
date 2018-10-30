# import socket for all socket related primitives
import socket
# we need struct in order to be able to pack data in
# a stream of bytes so that we can actually send
# an integer as a binary four byte sequence - instead
# of a string
import struct

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# input return actually a string and we need an int
#a = int(input('a='))
#b = int(input('b='))

# The obscure struct_addr is elegantly replaced by
# a simple pair - very convenient. Replace the IP Address with
# the one of your server
s.connect(("127.0.0.1", 1234))

# pack the value of a as a short int (16 bits) in network representation
#res = s.send(struct.pack("!H", a))
#res = s.send(struct.pack('!H', b))

while True:
    a = s.recv(4).decode()
    b = s.recv(4).decode()

    if int(a) == 3 and int(b) == 4:
        print("CORRECT")
        s.close()
        exit()

# unpack the content read from the network into a short int
# and convert from network representation back to host
#c = struct.unpack('!H', c)
#print('INVERTED STRING IS ' + c[0].__format__('d'))
#print("INVERTED STRING IS " + c)

print("a is {} and b is {}".format(int(a), int(b)))

s.close()

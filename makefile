all: clean readMessage writeMessage

readMsg: stego.c readMessage.c
	$(CC) -o readMessage stego.c readMessage.c

writeMsg: stego.c writeMsg.c
	$(CC) -o writeMessage stego.c writeMessage.c

clean:
	rm -f readMessage writeMessage out.ppm

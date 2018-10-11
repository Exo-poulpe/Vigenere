CC = gcc
OUT = Exe

compile:
	$(CC) main.c Vigenere.h -o $(OUT);

clean:
	rm -rf $(OUT);

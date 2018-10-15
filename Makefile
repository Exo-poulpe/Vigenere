CC = gcc
WIN = x86_64-w64-mingw32-gcc-win32 
OUT = Exe

linux:
	$(CC) main.c Vigenere.h -o $(OUT);

windows:
	$(WIN) main.c Vigenere.h -o Exe.exe;

compile:
	mkdir "linux";
	mkdir "windows";
	$(CC) main.c Vigenere.h -o /linux/Exe;
	$(WIN) main.c Vigenere.h -o /windows/Exe.exe;


clean:
	rm -rf $(OUT);

cleanAll:
	rm -rf linux/;
	rm -rf windows/;

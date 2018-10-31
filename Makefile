CC = gcc
OUTLIN = Exe
WIN = x86_64-w64-mingw32-gcc-win32
WIN32 = i686-w64-mingw32-gcc-win32
OUTWIN = Exe.exe
64 = -m64
32 = -m32
HH = sha1sum
HNAME = sha1Hash
ANDROID = aarch64-linux-gnu-gcc
OUTAND = Exe

linux:
	$(CC) main.c Vigenere.h -o $(OUTLIN);

windows:
	$(WIN) main.c Vigenere.h -o $(OUTWIN);

compile:
	mkdir "linux";
	mkdir "windows";
	mkdir "windows/32";
	mkdir "windows/64";
	$(CC) main.c Vigenere.h -o linux/$(OUTLIN);
	$(WIN) $(64) main.c Vigenere.h -o windows/64/$(OUTWIN);
	$(WIN32) $(32) main.c Vigenere.h -o windows/32/$(OUTWIN);

hash:
	$(HH) -b linux/Exe > $(HNAME);
	$(HH) -b windows/32/$(OUTWIN) >> $(HNAME);
	$(HH) -b windows/64/$(OUTWIN) >> $(HNAME);

clean:
	rm -rf $(OUTLIN);
	rm -rf $(OUTWIN);


cleanAll:
	rm -rf linux/;
	rm -rf windows/;
	rm -rf $(HNAME);

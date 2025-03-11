CFLAGS = -ffreestanding -nostdlib -m32
LDFLAGS = -T linker.ld -melf_i386

all: kernel.bin

boot.o: src/boot.asm
	nasm -f elf32 src/boot.asm -o boot.o

kernel.o: src/kernel.c
	gcc $(CFLAGS) -c src/kernel.c -o kernel.o

screen.o: src/screen.c
	gcc $(CFLAGS) -c src/screen.c -o screen.o

io.o: src/io.c
	gcc $(CFLAGS) -c src/io.c -o io.o

keyboard.o: src/keyboard.c
	gcc $(CFLAGS) -c src/keyboard.c -o keyboard.o

kernel.bin: boot.o kernel.o screen.o io.o keyboard.o
	ld $(LDFLAGS) -o kernel.bin boot.o kernel.o screen.o io.o keyboard.o

run: kernel.bin
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f *.o kernel.bin

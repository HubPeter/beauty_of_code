all:	hello
hello:	hello.o
		ld -o hello hello.o
hello.o:hello.asm
		nasm -f elf hello.asm
clean:	
		rm hello hello.o

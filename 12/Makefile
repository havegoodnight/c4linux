main.out: main.o cprint.o print.o
	gcc -o main.out main.o cprint.o print.o
main.o:main.c main.h
	gcc -c main.c
cprint.o:cprint.c cprint.h
	gcc -c cprint.c
print.o:print.c print.h
	gcc -c print.c
clean:
	rm main.o cprint.o print.o
	rm main.out

main.out:main.o print.o
	gcc -o main.out main.o print.o
main.o:main.c main.h
	gcc -c main.c
print.o:print.c print.h
	gcc -c print.c
clean:
	rm main.o print.o
	rm main.out

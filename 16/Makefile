main.out:main.o print.o
	gcc -o main.out main.o print.o --verbose
main.o:main.c main.h
	gcc -c main.c --verbose
print.o:print.c print.h
	gcc -c print.c --verbose
clean:
	rm ./*.i ./*.s ./*.o
	rm main.out

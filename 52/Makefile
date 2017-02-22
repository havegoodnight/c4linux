filename=search
$(filename):$(filename).o
	gcc -o $(filename) $(filename).o
$(filename).o:$(filename).c
	gcc -c $(filename).c
clean:
	rm ./$(filename).o
	rm ./$(filename)

cc=gcc
filename=search

$(filename):$(filename).o
	$(cc) -o $(filename) $(filename).o
$(filename).o:$(filename).c
	$(cc) -c $(filename).c
clean:
	rm ./$(filename).o
	rm ./$(filename)

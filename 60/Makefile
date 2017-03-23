objects = linkedlist.o main.o
cc = gcc
bin = main

$(bin) : $(objects)
	$(cc) -g -o $(bin) $(objects)

$(objects):linkedlist.h main.h

.PHONY:clean
clean:
	-rm -rf $(objects)
	-rm -rf $(bin)

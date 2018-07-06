
CFLAGS = -Wall

list.o : list.h

check_list.o : check_list.c
	cc -c -Wall -lcheck check_list.c

list.check : check_list.o list.o
	cc -Wall -lcheck -o list.check check_list.o list.o

check : list.check
	./list.check


.PHONY : clean
clean :
	rm -f *.check *.o

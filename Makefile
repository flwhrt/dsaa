
list.o : list.c list.h
	cc -c -Wall list.c

check_list.o : check_list.c
	cc -c -Wall -lcheck check_list.c

list.check : check_list.o list.o
	cc -Wall -lcheck -o list.check check_list.o list.o

check : list.check
	./list.check


.PHONY : clean
clean :
	rm -f *.check *.o

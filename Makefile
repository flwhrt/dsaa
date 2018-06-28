
list.o : list.c list.h
	cc -c -Wall list.c

check : 
	rm -f *.check
	cc -Wall -lcheck -o list.check check_list.c
	./list.check

.PHONY : clean
clean :
	rm -f *.check *.o

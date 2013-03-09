edit : main.o read_line.o
	gcc -o edit main.o read_line.o

main.o : main.c read_line.h
	gcc -c main.c -g
read_line.o : read_line.c read_line.h
	gcc -c read_line.c -g

clean :
	rm edit main.o read_line.o

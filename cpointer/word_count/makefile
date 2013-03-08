edit : main.o initialize.o add_word.o dump_word.o finalize.o get_word.o get_word_count.o
	gcc -o edit main.o add_word.o initialize.o dump_word.o\
	    finalize.o get_word.o get_word_count.o

main.o : main.c get_word.h word_manage_p.h
	gcc -c main.c
initialize.o : initialize.c word_manage_p.h
	gcc -c initialize.c 
add_word.o : add_word.c word_manage_p.h
	gcc -c add_word.c
dump_word.o : dump_word.c word_manage_p.h
	gcc -c dump_word.c
finalize.o : finalize.c word_manage_p.h
	gcc -c finalize.c
get_word.o : get_word.h get_word.c
	gcc -c get_word.c
get_word_count.o : get_word_count.c word_manage_p.h
	gcc -c get_word_count.c
clean : 
	rm edit main.o add_word.o initialize.o dump_word.o \
	    finalize.o get_word.o get_word_count.o

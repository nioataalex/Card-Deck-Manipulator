#Copyright Nioata Alexandra 312CAa 2021-2022


build: 
	gcc -Wall -Wextra -std=c99 functions.c main.c check_read.c list_implementation.c free_print.c -o tema1
	
clean:
	rm -rf tema1

CC=gcc
CFLAGS=

projectOne:
	$(CC) $(CFLAGS) -o matrix matrix.c
clean:
	rm matrix; rm -rf matrix.dSYM

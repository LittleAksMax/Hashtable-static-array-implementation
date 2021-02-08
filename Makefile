CC=gcc

hashtable.exe: hashtable.o main.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $<

clean:
	rm *.o *.exe

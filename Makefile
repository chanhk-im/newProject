CC = gcc
CFLAG = -g -Wall
TARGET = main
OBJECT = main.c credit.o
.SUFFIXES = .c .o

main_debug : $(TARGET)

main_debug : DEBUGOPTION = -DDEBUG

$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) $(DEBUGOPTION) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $(DEBUGOPTION) -c $<

clean:
	rm *.o $(TARGET)

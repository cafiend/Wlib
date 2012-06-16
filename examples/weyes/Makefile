PROJECT = weyes

CC = gcc 
INCLUDE = ../../
HLIB = ../../wlib.a
CFLAGS = -Wall -g -I$(INCLUDE)

OBJECTS = weyes.o

all : $(PROJECT)

.c.o :
	$(CC) -c $(CFLAGS) $<

$(PROJECT) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECT) $(HLIB) -lm


clean:
	rm -f *.o $(PROJECT)

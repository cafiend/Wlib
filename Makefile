PROJECT = wlib.a

CC = gcc 
CFLAGS = -Wall -g 


OBJECTS = socket.o command.o event.o callback.o wlib.o 

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	ar rcs $(PROJECT) $(OBJECTS)

socket.o: socket.h
command.o: command.h
event.o: event.h
callback.o : callback.h
wlib.o: socket.h command.h event.h callback.h wlib.h 

.PHONY : clean
clean :
	rm $(PROJECT) $(OBJECTS)


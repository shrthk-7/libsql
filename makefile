CC 			= gcc
CFLAGS 	= 

SOURCES 		= main.c buffer.c
OBJECTS 		= dist/main.o dist/buffer.o
EXECUTABLE 	= output.exe

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

dist/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

dist/buffer.o: buffer.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
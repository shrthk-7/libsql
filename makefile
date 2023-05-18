CC 			= gcc
CFLAGS 	= 

SOURCES 		= main.c buffer.c statement.c
OBJECTS 		= dist/main.o dist/buffer.o dist/statement.o
EXECUTABLE 	= output.exe

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

dist/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

dist/buffer.o: buffer.c
	$(CC) $(CFLAGS) -c $< -o $@

dist/statement.o: statement.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
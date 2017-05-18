CC=g++
CC_FLAGS=-Wall -ansi
EXEC=calculator
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cc
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS) 

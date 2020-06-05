CC=g++
CFLAGS=-c -Wall -Wextra -pedantic -std=c++11
LDFLAGS=
LIBFLAGS=
SOURCES=main.cpp Product.cpp Shopcart.cpp Database.cpp Menu.cpp Manager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=projekt

__start__: all
	

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)


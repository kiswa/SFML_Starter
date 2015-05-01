CC=g++
CFLAGS=-c -Wall -std=c++11 -g

LDFLAGS=
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=$(wildcard src/*.cpp)
OBJDIR=obj
OBJECTS=$(patsubst src/%.cpp,obj/%.o,$(SOURCES))

EXECUTABLE=sfml

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

obj/%.o: src/%.cpp | $(OBJDIR)
		$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		rm -rf $(OBJDIR) $(EXECUTABLE)

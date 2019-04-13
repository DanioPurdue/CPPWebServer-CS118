CC = g++
CFLAGS = -Wall -Werror -std=c++14
SOURCES = src/Server_Main.cpp src/RequestParser.cpp src/ResponsePrep.cpp
OBJFILES = Server_Main.o RequestParser.o ResponsePrep.o
TARGET = server

all:$(TARGET)

# combine all hte makefile to a single target
$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES)

Server_Main.o: src/Server_Main.cpp RequestParser.o
	$(CC) $(CFLAGS) -c src/Server_Main.cpp 

RequestParser.o: src/RequestParser.cpp
	$(CC) $(CFLAGS) -c src/RequestParser.cpp

ResponsePrep.o: src/ResponsePrep.cpp
	$(CC) $(CFLAGS) -c src/ResponsePrep.cpp

clean:
	rm -f $(OBJFILES) $(TARGET) *~
BIN=../bin
SRC=../src
CC=clang++
CFLAGS=--std=c++11 -g -I$(SRC)



spp		: spp.o rnx.o format.o

spp.o	: spp.cpp
	$(CC) $(CFLAGS) -c spp.cpp 

rnx.o	: $(SRC)/rnx.cpp
	$(CC) $(CFLAGS) -c $(SRC)/rnx.cpp 

format.o: $(SRC)/format.cpp
	$(CC) $(CFLAGS) -c $(SRC)/format.cpp

spp.o	: $(SRC)/rnx.h
rnx.o	: $(SRC)/rnx.h $(SRC)/format.h

clean	:
	rm *.o 

install	:
	cp spp $(BIN)
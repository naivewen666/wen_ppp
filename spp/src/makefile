CC=gcc
CFLAGS=-g

spp: spp.cpp rnx.o
	$(CC) $(CFLAGS) spp.cpp rnx.o -o ../bin/spp

rnx.o: rnx.cpp
	$(CC) $(CFLAGS) -c rnx.cpp


clean:
	rm *.o ../bin/spp
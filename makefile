CC = g++
FLAGS = -std=c++11

all: huffman.out clean

Heap.o: Heap.cpp
	    ${CC} ${FLAGS} -c Heap.cpp

HNode.o: HNode.cpp
	    ${CC} ${FLAGS} -c HNode.cpp

Huffman.o: Huffman.cpp
		${CC} ${FLAGS} -c Huffman.cpp

huffman.out: Heap.o HNode.o Huffman.o test_huffman.cpp
		${CC} ${FLAGS} test_huffman.cpp *.o -o huffman.out

clean:
	rm -f *.o
	rm -f *~
	rm -f \#*

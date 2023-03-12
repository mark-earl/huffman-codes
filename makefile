CC = g++
FLAGS = -std=c++11

all: huffman.out clean

Heap.o: Heap.cpp
	    @${CC} ${FLAGS} -c Heap.cpp
		@echo [25%]\  Successfully created Heap object file.

HNode.o: HNode.cpp
	    @${CC} ${FLAGS} -c HNode.cpp
		@echo [50%]\  Successfully created HNode object file.

Huffman.o: Huffman.cpp
		@${CC} ${FLAGS} -c Huffman.cpp
		@echo [75%]\  Successfully created Huffman object file.

huffman.out: Heap.o HNode.o Huffman.o test_huffman.cpp
		@echo [83%]\  Linking object files.
		@${CC} ${FLAGS} test_huffman.cpp *.o -o huffman.out
		@echo [100%] Successfully built huffman.out.

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f *~
	@rm -f \#*

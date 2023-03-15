# Changes Log

This file documents the changes related to makefile and the program output

## makefile

Here is the contents of the original makefile:

    all:
	    g++ -std=c++11 -c *.cpp
	    g++ -std=c++11 *.o -o huffman.out

This works fine, but I desired an integrated clean target that was automatically run when the `make` command was run.

So here is the updated makefile I made:

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

Here is the expected output:

    [25%]  Successfully created Heap object file.
    [50%]  Successfully created HNode object file.
    [75%]  Successfully created Huffman object file.
    [83%]  Linking object files.
    [100%] Successfully built huffman.out.
    Cleaning up...

No matter which version of the make file you run, both will produce the `huffman.out` executable.

## test_huffman.cpp

The contents of test_huffman.cpp include a number of assertions and other relevant output. This is just to make grading the project easier.

Here is the expected output:

    Huffman Code Test (1/2)

    Input: MISSISSIPPI

    Generated Codes:
            'I'->0
            'M'->100
            'P'->101
            'S'->11

    Encoded String  : 100011110111101011010
    Serialized Tree : *I//**M//P//S//

    Testing Encoded String...       PASSED
    Testing Serialized Tree...      PASSED

    Huffman Code Test (2/2)

    Input: A man a plan, a canal, Panama!

    Generated Codes:
            ' '->00
            '!'->01100
            ','->0111
            'A'->01010
            'P'->01011
            'a'->11
            'c'->0100
            'l'->1010
            'm'->1011
            'n'->100
            'p'->01101

    Encoded String  : 010100010111110000110001101101011100011100110001001110011101001110001011111001110111101100
    Serialized Tree : ** //**c//*A//P//**!//p//,//**n//*l//m//a//

    Testing Encoded String...       PASSED
    Testing Serialized Tree...      PASSED

    All Tests Passed

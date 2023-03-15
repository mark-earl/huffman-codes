// test_huffman.cpp
// c. 2015 A. Deeter

#include <iostream>
#include <cassert>
#include "Huffman.hpp"

int main() {
    Huffman h;

    std::cout << "Huffman Code Test (1/2)\n\n";

    std::cout << "Input: MISSISSIPPI\n\n";
    Encoded e = h.encode("MISSISSIPPI");
    std::cout << "Encoded String  : " << e.encoded_string << std::endl;
    std::cout << "Serialized Tree : " << e.serialized_tree << "\n\n";

    std::cout << "Testing Encoded String...";
    assert(e.encoded_string == "100011110111101011010");
    std::cout << "\tPASSED\n";

    std::cout << "Testing Serialized Tree...";
    assert(e.serialized_tree == "*I//**M//P//S//");
    std::cout << "\tPASSED\n";

    std::cout << "\nHuffman Code Test (2/2)\n\n";

    std::cout << "Input: A man a plan, a canal, Panama!\n\n";
    Encoded a = h.encode("A man a plan, a canal, Panama!");
    std::cout << "Encoded String  : " << a.encoded_string << std::endl;
    std::cout << "Serialized Tree : " << a.serialized_tree << "\n\n";

    std::cout << "Testing Encoded String...";
    assert(a.encoded_string == "010100010111110000110001101101011100011100110001001110011101001110001011111001110111101100");
    std::cout << "\tPASSED\n";

    std::cout << "Testing Serialized Tree...";
    assert(a.serialized_tree == "** //**c//*A//P//**!//p//,//**n//*l//m//a//");
    std::cout << "\tPASSED\n";

    std::cout << "\nAll Tests Passed\n\n";

    return 0;
}

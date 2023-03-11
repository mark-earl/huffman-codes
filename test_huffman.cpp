// test_huffman.cpp
// c. 2015 A. Deeter

#include <iostream>
#include "Huffman.hpp"

int main() {
    std::cout << "Initializing Huffman Object...";
    Huffman h;
    std::cout << "\t✅\n\n";

    std::cout << "Initializing Encoded Object:\n";
    Encoded e = h.encode("MISSISSIPPI");
    std::cout << "\t✅\n";

    std::cout << "Input: MISSISSIPPI" << std::endl;
    std::cout << e.encoded_string << std::endl;
    std::cout << e.serialized_tree << std::endl;

    std::cout << "Input: A man a plan, a canal, Panama!" << std::endl;
    Encoded a = h.encode("A man a plan, a canal, Panama!");
    std::cout << a.encoded_string << std::endl;
    std::cout << a.serialized_tree << std::endl;

}

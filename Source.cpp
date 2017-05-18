#include "Huffman.h"
#include <iostream>

using namespace std;


int main()
{
	//Huffman a(0, /*"Helloooooo beep"*/ "itismystriiiiing!!!!");
	Huffman b(1, "1.doc");
	b.encode();
	b.decode();

	std::cout << std::endl;
	b.print_codes();
	std::cout << std::endl;
	b.print_tree();
	std::cout << std::endl;

//	b.print_encoded();
	std::cout << std::endl;
	std::cout << std::endl;
	
	
}
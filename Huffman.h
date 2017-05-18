#pragma once
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <string>

class Node
{
public:
	int a;
	char c;
	Node *left, *right;

	Node()
	{
		left = NULL;
		right = NULL;
	}

	Node(Node *L, Node *R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}
};


class Huffman {
public:
	Huffman() {}
	Huffman(int mode, char *t); //mode = 1 from file, mode = 0 text

	void print_codes();
	void print_encoded();
	void decode();
	void print_tree();
	void encode();

private:
	std::map<char, int> symbols_frequency;
	Node* root;
	char * source_text;  //It may be either text or name of file
protected:
	void frequency(char * t);   //calculus and fill map<char, int>
	void encode_text(char * t);
	void encode_file(char * f);
	void create_tree();
	void print_helper(Node* root, unsigned int k);

	void BuildTable(Node * ptr);
	std::map<char, std::string> table;
	std::string code = "";
};


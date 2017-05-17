#include "Huffman.h"



Huffman::Huffman(int mode, char* t)
{
	source_text = t;  
	if (mode)
	{
		encode_file(t);
	}
	else
	{
		std::cout << "Source text:\n";
		int i = 0;
		while (t[i] != NULL)
		{
			std::cout << t[i];
			i++;
		}
		encode_text(t);
	}
}

void Huffman::frequency(char * t)
{
	while (*t != NULL)
	{
		symbols_frequency[*t]++;
		t++;
	}
}

void Huffman::encode_text(char * t)
{
	frequency(t);
	create_tree();
	BuildTable(root);
}

struct compare_list
{
	bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};

void Huffman::create_tree()
{
	//std::multimap<int, char> m; //create multimap for sorting with freq.
	//for (auto it = symbols_frequency.begin(); it != symbols_frequency.end(); ++it) //filling the multimap 
	//	m.insert(std::make_pair(it->second, it->first));


	std::list<Node*> t;  //filling the list
	for (auto it = symbols_frequency.begin(); it != symbols_frequency.end(); ++it)
	{
		Node *p = new Node;
		p->c = it->first;
		p->a = it->second;
		t.push_back(p);
	}

	while (t.size() != 1)
	{
		t.sort(compare_list());

		Node *Left = t.front();
		t.pop_front();
		Node *Right = t.front();
		t.pop_front();

		Node *parent = new Node(Left, Right);
		t.push_back(parent);
	}

	root = new Node(t.front()->left, t.front()->right);
}

void Huffman::BuildTable(Node *ptr)
{
	if (ptr->left != NULL)
	{
		code+="0";
		BuildTable(ptr->left);
	}

	if (ptr->right != NULL)
	{
		code += "1";
		BuildTable(ptr->right);
	}

	if (ptr->c) table[ptr->c] = code;


	//if (code.size() != 0)
		//code.pop_back();
	if (code.size() != 0)
	code.erase(code.size() - 1, 1);
}

void Huffman::print_encoded()
{
	int i = 0;
	int count = 0; char buf = 0;
	while (source_text[i] != NULL)
	{
		char c = source_text[i];
		std::string x = table[c];
		for (int n = 0; n<x.size(); n++)
		{
			buf = buf | x[n] << (7 - count);
			count++;
			if (count == 8) { count = 0;   std::cout << buf; buf = 0; }
		}
		i++;
	}
}

void Huffman::print_codes()
{
		for (auto it = table.begin(); it != table.end(); ++it)
		{
			std::cout << it->first << " | "<<it->second;
			/*for (auto itr = it->second.begin(); itr != it->second.end(); itr++)
			{
				std::cout << *itr;
			}*/
			std::cout << std::endl;
		}
}

void Huffman::print_helper(Node *root, unsigned int k = 0)   //FOR TEST. It's prints the tree
{
	if (root != NULL)
	{
		print_helper(root->left, k + 3);

		for (unsigned i = 0; i < k; i++)
		{
			std::cout << "   ";
		}

		if (root->c) std::cout << root->a << " (" << root->c << ")" << std::endl;
		else std::cout << root->a << std::endl;
		print_helper(root->right, k + 3);
	}
}  

void Huffman::print_tree()
{
	print_helper(root);
}

void Huffman::encode_file(char * f)
{
	std::ifstream file(f, std::ifstream::binary);
	file.seekg(0, file.end);
	long long file_size = file.tellg();
	file.seekg(0, file.beg);
	while (file.tellg() < file_size)
	{
		unsigned char tmp;
		file.read((char *)&tmp, sizeof(tmp));
		++symbols_frequency[tmp];
	}
	create_tree();
	BuildTable(root);
	file.close();
}

void Huffman::encode()
{

	std::ifstream file(source_text, std::ifstream::binary); //SOURCE FILE
	file.seekg(0, file.end);
	long long file_size = file.tellg();
	file.seekg(0, file.beg);
	
	std::ofstream ef(std::string(source_text)+".huff", std::ifstream::binary); //output file
	std::string output_bits = "";
	while (file.tellg() < file_size)
	{
		unsigned char tmp;
		file.read((char *)&tmp, sizeof(tmp));
		output_bits += table[tmp];
		while (output_bits.length() > 7u)
		{
			unsigned char tmp = 0u;
			for (unsigned char i = 0u; i < 8u; ++i)
				if (output_bits[i] == '1')
					tmp |= 1u << (7u - i);
			output_bits.erase(0, 8);
			ef.write((char *)&tmp, sizeof(tmp));
		}
	}

		if (!output_bits.empty())
		{
			unsigned char tmp = 0u;
			for (unsigned char i = 0u; i < output_bits.length(); ++i)
				if (output_bits[i] == '1')
					tmp |= 1u << (7u - i);
			ef.write((char *)&tmp, sizeof(tmp));
		}

	file.close();
	ef.close();
}

void Huffman::decode()
{

}
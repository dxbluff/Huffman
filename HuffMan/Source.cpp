#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Node
{
	int a;
	char c;
	Node *left, *right;
};

int main()
{
	string a("Hello it's test text");
	map<char, int> myMap;
	myMap['c'] = 5;
	cout << myMap['c'];
	
	for (int i = 0; i < a.length(); i++)
	{
		myMap[a[i]]++;
	}


	map<char, int>::iterator it;

	for (it = myMap.begin(); it != myMap.end(); ++it)
	{
		cout << "[" << it->first << "]->" << it->second << endl;
	}

	cout << endl;
	return 0;
}
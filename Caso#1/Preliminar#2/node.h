#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class node {
	public:
		node(string newsTitle);


	private:
		node* siguiente;
		node* anterior;
        string newsTitle;

		friend class linkedList;
};
typedef node* nodeList;
#endif
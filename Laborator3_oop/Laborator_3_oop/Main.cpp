#include <iostream>
#include "Tree.h"
#include "Knoten.h"
using namespace std;

int main()
{
	Tree* tree = new Tree;//creaza o variabila tree de tipu clasei Tree
	Knoten* k = new Knoten;
	tree->insert(4);//aici inseram in arbore urmatoarele noduri,4 fiind radacina lui
	tree->insert(6);
	tree->insert(8);
	tree->insert(3);
	tree->insert(2);
	//tree->delete1(8);
	tree->inorder_print();
	tree->postorder_print();
	tree->preorder_print();
	cout << "Ce nod vrei sa stergi";
	cin >> k->val;
	tree->delete1(8,4);
	//cout <<"Inaltimea: "<< tree->Height() << endl;
	//cout <<"Numarul de noduri: "<< tree->CountNod() << endl;
	//cout <<"Numarul de muchii: " <<tree->CountMuchi() << endl;
};
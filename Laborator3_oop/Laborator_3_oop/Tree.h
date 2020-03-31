#pragma once
#include <vector>
#include "Knoten.h"
#include <string>
using namespace std;


class Tree: public Knoten
{
private:
	Knoten* tree_head;//asta va fi radainca
public:
	//Knoten* tree_head;//asta va fi radainca
	void set_head(Knoten* cap);
	Knoten* get_head();
	Tree();//constructoru default pentru radacina
	Tree(Knoten* cap);//constructoru default pentru radacina
	void insert(int v,Knoten *Tree);
	void insert(int v);
	Knoten* delete1(int key,Knoten* tree_head);
	void inorder_print();
	void inorder_print(Knoten* Tree);
	void postorder_print();
	void postorder_print(Knoten* Tree);
	void preorder_print();
	void preorder_print(Knoten* Tree);
	int Height();
	int Height(Knoten* Tree);
	int CountNod();
	int CountNod(Knoten* Tree);
	int CountMuchi();
	int CountMuchi(Knoten* Tree);
};

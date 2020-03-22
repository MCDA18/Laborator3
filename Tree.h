#pragma once
#include <vector>
#include "Knoten.h"
using namespace std;


class Tree: public Knoten
{
private:
	Knoten* tree_head;//asta va fi radainca
public:
	Tree();//constructoru default pentru radacina
	void insert(int v,Knoten *Tree);
	void insert(int v);
	Knoten* search(int v, Knoten* Tree);
	Knoten* delete1(int v, Knoten* Tree);
	Knoten* search(int v);
	Knoten* delete1(int v);
};

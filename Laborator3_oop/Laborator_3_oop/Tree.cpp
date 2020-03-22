#include <iostream>
#include "Tree.h"
#include "Knoten.h"

//instantam adresa radacinii arborelui cu 0 la inceput
Tree::Tree()
{
	tree_head = NULL;
}
//functia de inserare a unui nod
void Tree::insert(int key, Knoten* frunze)
{
    //key ii valoarea data de utilizator..nodul
    //frunze ii o variabila pe care va trebui sa o punem ori in dreapta ori in stanga
    if (key < frunze->val)//verifica daca nodul dat de utilizator ii mai mic decat valoarea frunzei
    {
        if (frunze->left_son != NULL)//mai in jos ai vazut ca la inceput am creat left_son si right_son cu NULL
            insert(key, frunze->left_son);
        else//daca nu ii NULL creaza unu nou de tipu KNOTEN,adica nod si si nodu asta va avea 2 fii,ambii NULL
        {
            frunze->left_son = new Knoten;
            frunze->left_son->val = key;
            frunze->left_son->left_son = NULL;
            frunze->left_son->right_son = NULL;
        }
    }
    else
        if (key >= frunze->val)
            if (frunze->right_son != NULL)
                insert(key, frunze->right_son);
            else
            {
                frunze->right_son = new Knoten;
                frunze->right_son->val = key;
                frunze->right_son->right_son = NULL;
                frunze->right_son->left_son = NULL;
            }

}
//inserarea care verifica la inceput daca este primul nod introdus, va merge la ramura de else,altfel dupa fiecare data va intra pe ramura de if
void Tree::insert(int key)//key ii valoarea data de utilizator(nodul)
{
    if (tree_head != NULL)
        insert(key, tree_head);//asta se va folosi mereu dupa introducerea primului nod
    else//pe ramura asta va intra numa la inceput cand tree_headul(radacina) este la inceput NULL
    {
        tree_head = new Knoten;//creaza un nod de tipu KNOTEN,pe romana nod..Feier:))
        tree_head->val = key;//asta cu sageata se foloseste pentru a folosi valoarea de la adresa...lucram cu pointeri
        tree_head->left_son = NULL;//facem nodu dreapta si nodu stanga cu NULL ca inca n am primit o valoare pentru ele
        tree_head->right_son = NULL;
    }
}
Knoten* Tree::delete1(int key, Knoten* frunze)
{
    if (frunze != NULL)
    {
        //merge recursiv inapoi pana gaseste,daca exista
        if (key == frunze->val)
        {
            delete frunze;
        }
        if (key < frunze->val)
        {
            return Tree::delete1(key, frunze->left_son);
        }
        else
        {
            return Tree::delete1(key, frunze->right_son);
        }
    }
    else
        return NULL;//asta returneaza daca nu exista,nu poate fi sters

}
Knoten* Tree::delete1(int key)
{
    return delete1(key, tree_head);
}
//functia search care va returna locatia unde se afla un nod...in cazu in care exista
Knoten *Tree::search(int key, Knoten* frunze)
{
    if (frunze != NULL)
        {
        //merge recursiv inapoi pana gaseste,daca exista
            if (key == frunze->val) 
            {
                return frunze;
            }
            if (key < frunze->val)
            {
                return Tree::search(key, frunze->left_son);
            }
            else 
            {
            return Tree::search(key, frunze->right_son);
            }
        }
    else 
        return NULL;//asta returneaza daca nu este in arbore nodul dat de utilizator

}
Knoten* Tree::search(int key) 
{
    return search(key,tree_head);
}
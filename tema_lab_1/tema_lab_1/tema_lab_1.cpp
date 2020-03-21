// tema_lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//calculeaza cu algoritmu lu euclid cmmdc
int relativ_prim(int x,int y)
{
    if (x != y)
        while (x != y)
            if (x > y)
                x = x - y;
            else
                y = y - x;
    return x;
}
//verifica daca 2 numere consecutive sunt prime si afiseaza cea mai mare secventa cu numere prime consecutive
void verificare_numere_prime(int v[],int n)
{
    int smax = 0;
    int ctmax = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (relativ_prim(v[i], v[i + 1]) == 1)
            ctmax = ctmax + 1;

        else
            ctmax = 0;
        if (ctmax>smax)
            smax = ctmax;
    }
     std::cout << smax;
}
//calculeaza x la puterea lui n
void x_putere_n(double x, int n)
{
    int y = x;
    while (n>1)
    {
        x = x * y;
        n--;
    }
    std::cout << x;

}
//calculeaza cea mi mare secventa de numere care au numere de semn diferit
void secventa_numere_diferite(int v[], int n)
{
    int ctmax = 0;
    int smax = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] < 0 && v[i + 1]>0) || (v[i + 1] < 0 && v[i] > 0))
            ctmax += 1;
        else
            ctmax = 0;
        if (ctmax > smax)
            smax = ctmax;
    }
    std::cout << smax;
}
//calculeaza descompunerea in factori primi si verifica de cate ori apare numarul n ca factor prim in x
void nr_prim_exponent_n(int x, int n)
{
    int p;
    int d = 2;
    int vec_nou[100] = {0};
    int m = 0;
    while (x > 1)
    {
        p = 0;
        while (x % d == 0)
        {
            x = x / d;
            p++;
        }
        if (p > 0)
        {
            vec_nou[m++] = d;
            vec_nou[m++] = p;
        }
        d++;
    }
    int i = 0;
    int ok = 0;
    while (i < m)
    {

        if (vec_nou[i] == n)
        {
            std::cout <<"Numarul p apare de "<< vec_nou[i + 1]<<" ori in descompunerea in factori primi ai numarului n";
            ok = 1;
        }
        i += 2;
    }
    if (ok == 0)
        std::cout << "Numaru p nu este prezent in exponentii numarului n!";
}
int main()
{
    int v[] = { 7,11,3,4,6,5,23,31 }; 
    int v1[] = { -1,2,-3,4,-5,-6,5,4,-7,-8 };
    int n;
    int m;
    m = sizeof(v1) / sizeof(v1[0]);
    n = sizeof(v)/sizeof(v[0]);
    //verificare_numere_prime(v, n);
    //x_putere_n(2, 5);
    secventa_numere_diferite(v1, m);
    //nr_prim_exponent_n(24, 2);


}

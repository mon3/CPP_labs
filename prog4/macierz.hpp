#ifndef _macierz_hpp_
#define _macierz_hpp_

#include <iostream>


typedef std::pair <int, int> RozmiarMacierzy;
typedef std::pair <int, int> Polozenie;



class Macierz
{
public:
Macierz (std::istream &is);
// tworzy macierz na podstawie strumienia
Macierz (int n, int m);
// tworzy pustą (niezainicjowaną) macierz n x m
~Macierz ();
int element (int i, int j) const; // zwraca element macierzy (kopia przez wartość)
int &element (int i, int j); // zwraca ref. (można modyfikować!) do el. macierzy
RozmiarMacierzy rozmiar () const;
// zwraca rozmiar macierzy
private:
mutable int n_;
mutable int m_;
int *mac_ = nullptr;

void init(int n, int m);

friend std::ostream &operator<< (std::ostream &os, const Macierz &m);
};

#endif
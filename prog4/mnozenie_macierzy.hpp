#ifndef _mnozenie_macierzy_hpp_
#define _mnozenie_macierzy_hpp_

#include "macierz.hpp"
#include <boost/optional.hpp>
#include <mutex>
#include <memory>

#include <iostream>
#include <mutex>

// Kontroluje proces mnożenia macierzy (obiekt współdzielony)
class KontrolerMnozenia
{
public:
// Inicjuje skladowe klasy
KontrolerMnozenia (const Macierz &m1, const Macierz &m2, Macierz &m3);
inline const Macierz &czynnik1 () const {return m1_;}
inline const Macierz &czynnik2 () const {return m2_;}
inline Macierz &wynik () const {return m3_;}
// Zwraca współrzędne najbliższego elementu do obliczen
// lub kontener niezainicjowany, gdy obliczenia dobiegły końca
boost::optional <Polozenie> coMamLiczyc ();
private:
std::mutex blokada_;
const Macierz &m1_;
const Macierz &m2_;
Macierz &m3_;
};


// Funkcja mnożąca macierze m1 i m2 w p wątkach
std::auto_ptr<Macierz> mnozenie_macierzy (const Macierz &m1, const Macierz &m2, int p);
class MnozycielMacierzy
// funktor wykorzystywany w wątkach mnożących macierze
{
public:
MnozycielMacierzy (KontrolerMnozenia &km);
// inicjuje składowe klasy
void operator() ();
// metoda wywoływana przy utworzeniu wątku
private:
KontrolerMnozenia &km_;
const Macierz *m1_;
const Macierz *m2_;
Macierz *m3_;
};


#endif
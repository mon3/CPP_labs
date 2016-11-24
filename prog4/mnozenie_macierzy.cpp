#include "mnozenie_macierzy.hpp"


KontrolerMnozenia::KontrolerMnozenia (const Macierz &m1, const Macierz &m2, Macierz &m3):m1_(m1),m2_(m2),m3_(m3)
{}


boost::optional <Polozenie> KontrolerMnozenia::coMamLiczyc ()
{
	blokada_.lock();
	// cos robimy
	blokada_.unlock();
}


MnozycielMacierzy::MnozycielMacierzy (KontrolerMnozenia &km):km_(km)
{}

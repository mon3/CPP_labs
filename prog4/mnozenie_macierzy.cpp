#include "mnozenie_macierzy.hpp"


KontrolerMnozenia::KontrolerMnozenia (const Macierz &m1, const Macierz &m2, Macierz &m3):m1_(m1),m2_(m2),m3_(m3)
{}


// boost::optional <Polozenie> KontrolerMnozenia::coMamLiczyc ()
// {
// 	blokada_.lock();
// 	// cos robimy
// 	blokada_.unlock();
// }


MnozycielMacierzy::MnozycielMacierzy (KontrolerMnozenia &km):km_(km)
{}

std::unique_ptr<Macierz> mnozenie_macierzy (const Macierz &mat1, const Macierz &mat2, int p)
{
	std::pair<int,int> rozmiar_m1;
	rozmiar_m1 = mat1.rozmiar();

	std::pair<int,int> rozmiar_m2;
	rozmiar_m2 = mat2.rozmiar();

	int n1 = rozmiar_m1.first;
	int m1 = rozmiar_m1.second;
	int m2 = rozmiar_m2.second;

	std::unique_ptr<Macierz> mult (new Macierz(n1,m2)); //macierz wynikowa
	    for(int i = 0; i < n1; ++i)
        for(int j = 0; j < m2; ++j)
            for(int k = 0; k < m1; ++k)
            {
            	int& element = mult->element(i,j);
                element += mat1.element(i,k) * mat2.element(k,j);
            }

    return mult;
}

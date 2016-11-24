#include "macierz.hpp"
#include "mnozenie_macierzy.hpp"

#include <boost/thread.hpp>
#include <boost/optional.hpp>
#include <mutex>
#include <memory>


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>



double interwal(timespec start, timespec koniec)
{
	return koniec.tv_sec - start.tv_sec +(koniec.tv_nsec - start.tv_nsec) / 1000000000. ;
}

std::ostream& operator<<(std::ostream& os, Macierz& mac) {
	std::pair<int,int> rozmiar ;
	rozmiar = mac.rozmiar();
	std::cout<< "rozmiar 1 " <<rozmiar.first<< std::endl;
	std::cout<< "rozmiar 2 " <<rozmiar.second<< std::endl;


	for (int i=0;i<rozmiar.first;i++){
	for (int j=0;j<rozmiar.second;j++){
		os<<"element = " <<mac.element(i,j)<<" ";
	}
	os<<std::endl;
	}

return os;
}



	int main (int argc, char *arg [])
	{
		const clockid_t ZegarID = CLOCK_REALTIME;
	timespec start, koniec; // Struktury przechowujące czas
	// std::cout << "Mnozenie macierzy...";
	// std::cout.flush ();
	clock_gettime (ZegarID, &start); // Zapisuje czas początku mnożenia
	if (argc != 3)		// Sprawdzenie ilosci argumentow
	{
		std::cerr << "Program wymaga podania nazw pliku z programem jako pierwszego parametru!" << std::endl;
		return 1;
	}
	std::ifstream plik_z_programem (arg [1]);
	std::ifstream plik_z_programem2 (arg [2]);

	// Macierz a (std::cin);
	Macierz a (plik_z_programem);
	std::cout << a;

	std::pair<int,int> rozmiar_a;
	rozmiar_a = a.rozmiar();

	Macierz b (plik_z_programem2);
	std::cout << b;

	// std::pair<int,int> rozmiar_b;
	// rozmiar_b = b.rozmiar();

	// int n1 = rozmiar_a.first;
	// int m2 = rozmiar_b.second;

	// Macierz c (n1, m2);
	// std::cout << c;

	int p = 2; // p -liczba wątków
	// macierz dzielimy na wątki jako n1*m2/p

	


	// Mnoży macierze a i b (liczba oznacza liczbę równoległych wątków)
	std::unique_ptr<Macierz> wynik = mnozenie_macierzy (a, b, 2);
	std::cout << *wynik;

	clock_gettime (ZegarID, &koniec); // Zapisuje czas końca mnożenia
	std::cout << " zajelo " << interwal (start, koniec) << " s" << std::endl;

	return 0;
	}
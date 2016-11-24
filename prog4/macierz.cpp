#include "macierz.hpp"


//tworzy pusta macierz n*m
Macierz::Macierz(int n, int m):n_(n), m_(m)
{
	init(n,m);
}

void Macierz::init(int n, int m)
{
	mac_ = new int[n_*m_];	
}

int& Macierz::element (int i, int j) 
{
	return mac_[i*m_+j];
}

int Macierz::element (int i, int j) const
{
	// return (mac_[i*n_+j]);
		return mac_[i*m_+j];

}

RozmiarMacierzy Macierz::rozmiar () const
{
	std::pair<int,int> rozmiar;
	rozmiar.first = n_;
	rozmiar.second = m_;

	return rozmiar;
}

Macierz::~Macierz()
{
	if (mac_)
	delete [] mac_;
	mac_ = nullptr;
}



Macierz::Macierz (std::istream &is)
{
	

	is >> n_>>m_;
	init(n_, m_);

	for (int i=0; i<n_; i++){

		for (int j=0; j<m_; j++)
		{
			// int tmp;
			int &element2 = element(i,j);
			is >> element2;
		}
		}


}





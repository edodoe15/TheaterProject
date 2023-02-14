#pragma once
#include <iostream>
class Projekcija
{
public:
	std::string naziv;
	int brUlaznica;
	int cijena;
	int ID;
	long int vrijeme;
	Projekcija();
	void setNaziv();
	void setBrUlaznica();
	void setCijena();
	void setVrijeme();
	std::string getNaziv() const;
	int getBrUlaznica() const;
	int getCijena() const;
	int getVrijeme() const;
	virtual void print()
	{
		std::cout << "Dobrodosli u pozoriste!" << std::endl;
	}
	~Projekcija() = default;
};


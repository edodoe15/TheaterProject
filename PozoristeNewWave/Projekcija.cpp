#include "Projekcija.h"
#include <iostream>
#include <string>

Projekcija::Projekcija()
{
}

void Projekcija::setNaziv()
{
    std::cout << "Unesite naziv projekcije:";
    std::getline(std::cin, this->naziv);
    std::cin.ignore();
}

void Projekcija::setBrUlaznica()
{
    std::cout << "Unesite broj ulaznica: ";
    std::cin >> this->brUlaznica;
}

void Projekcija::setCijena()
{
    std::cout << "Unesite cijenu jedne ulaznice: ";
    std::cin >> this->cijena;
    std::cin.ignore();
}

void Projekcija::setVrijeme()
{
    std::cout << "Unesite vrijeme trajanja projekcije (min): ";
    std::cin >> this->vrijeme;
}

std::string Projekcija::getNaziv() const
{
    return this->naziv;
}

int Projekcija::getBrUlaznica() const
{
    return this->brUlaznica;
}

int Projekcija::getCijena() const
{
    return this->cijena;
}

int Projekcija::getVrijeme() const
{
    return this->vrijeme;
}


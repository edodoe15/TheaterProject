#ifndef FILM_H
#define FILM_H

#include "Projekcija.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum class vrsta { dvaD = 0, triD, četiriDX };

class Film :
    public Projekcija
{
private:
    vrsta v;
    std::string zanr;
public:
    Film() : v{ vrsta::dvaD } {};

    // Setteri
    void setZanr(const std::string& zanr) { this->zanr = zanr; };
    void setVrsta(const vrsta& v) { this->v = v; };

    // Getteri
    std::string getZanr() const noexcept { return this->zanr; }
    vrsta getVrsta() const noexcept { return this->v; }

    ~Film() = default;

    // Unos iz konzole
    friend std::istream& operator>>(std::istream& is, Film& film);

    // Ispis informacija o filmu u konzolu
    friend std::ostream& operator<<(std::ostream& is, const Film& film);

    // Unos iz fajla
    friend std::ifstream& operator>>(std::ifstream& ifs, Film& film);

    // Ispis u fajl
    friend std::ofstream& operator<<(std::ofstream& ofs, const Film& film);

    void print()
    {
        std::cout << "Dobrodosli na film!" << std::endl;
    }

};


#endif

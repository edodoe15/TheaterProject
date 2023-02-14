#ifndef PREDSTAVA_H
#define PREDSTAVA_H

#include "Projekcija.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum vrsta1 {djeca=0, odrasli};

class Predstava :
    public Projekcija
{
private:
    vrsta1 v1;
    std::string tip;
public:
    Predstava() : v1{ vrsta1::djeca } {};

    // Setteri
    void setTip(const std::string& tip) { this->tip = tip; };
    void setVrsta(const vrsta1& v1) { this->v1 = v1; };

    // Getteri
    std::string getTip() const noexcept { return this->tip; }
    vrsta1 getVrsta() const noexcept { return this->v1; }

    ~Predstava() = default;

    // Unos iz konzole
    friend std::istream& operator>>(std::istream & is, Predstava & predstava);

    // Ispis informacija o filmu u konzolu
    friend std::ostream& operator<<(std::ostream & is, const Predstava& predstava);

    // Unos iz fajla
    friend std::ifstream& operator>>(std::ifstream & ifs, Predstava& predstava);

    // Ispis u fajl
    friend std::ofstream& operator<<(std::ofstream & ofs, const Predstava& predstava);

    void print()
    {
        std::cout << "Dobrodosli na predstavu!" << std::endl;
    }

};


#endif


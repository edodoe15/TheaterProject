#include "Film.h"
#include <iostream>

std::istream& operator>>(std::istream& tok, Film& film) {
    std::cout << "Unesite naziv projekcije [primjer: rijec1_rijec2_..._rijecn]: ";
    std::getline(tok, film.naziv);

    std::cout << "Unesite broj ulaznica: ";
    tok >> film.brUlaznica;

    std::cout << "Unesite cijenu jedne ulaznice: ";
    tok >> film.cijena;

    std::cout << "Unesite vrijeme trajanja projekcije (min): ";
    tok >> film.vrijeme;

    std::cout << "Unesite vrstu filma: ";
    std::cout << "2D[0], 3D[1] ili 4DX[2] -> ";
    int tmpVrsta{ 0 };
    tok >> tmpVrsta;
    film.v = static_cast<vrsta>(tmpVrsta);
    tok.ignore();

    std::cout << "Unesite zanr filma: ";
    std::getline(tok, film.zanr);

    return tok;
}

std::ostream& operator<<(std::ostream& os, const Film& f) {
    os << "\tNaziv: " << f.getNaziv() << std::endl;
    os << "\tBroj ulaznica: " << f.getBrUlaznica() << std::endl;
    os << "\tCijena ulaznice: " << f.getCijena() << std::endl;
    os << "\tVrijeme trajanja: " << f.getVrijeme() << std::endl;
    os << "\tVrsta: " << static_cast<int>(f.getVrsta()) << " - 0[2D] 1[3D] 2[4DX] " << std::endl;
    return os << "\tZanr: " << f.getZanr() << std::endl;
}

std::ofstream& operator<<(std::ofstream& ofs, const Film& film) {
    ofs << film.getNaziv() << std::endl;
    ofs << film.getBrUlaznica() << " "
        << film.getCijena() << " "
        << film.getVrijeme() << " "
        << static_cast<int>(film.getVrsta()) << std::endl;
    ofs << film.getZanr() << std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Film& film) {
    char pHolder;
    std::getline(ifs, film.naziv);
    int tmpVrsta{ 0 };
    ifs >> film.brUlaznica
        >> film.cijena
        >> film.vrijeme
        >> tmpVrsta;
    film.v = static_cast<vrsta>(tmpVrsta);
    pHolder = ifs.get();
    std::getline(ifs, film.zanr);
    return ifs;
}



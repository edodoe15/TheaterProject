#include "Predstava.h"
#include <iostream>

std::istream& operator>>(std::istream& tok, Predstava& predstava) {
    std::cout << "Unesite naziv projekcije [primjer: rijec1_rijec2_..._rijecn]: ";
    std::getline(tok, predstava.naziv);

    std::cout << "Unesite broj ulaznica: ";
    tok >> predstava.brUlaznica;

    std::cout << "Unesite cijenu jedne ulaznice: ";
    tok >> predstava.cijena;

    std::cout << "Unesite vrijeme trajanja projekcije (min): ";
    tok >> predstava.vrijeme;

    std::cout << "Unesite vrstu predstave: ";
    std::cout << "djeca[0], odrasli[1] -> ";
    int tmpVrsta{ 0 };
    tok >> tmpVrsta;
    predstava.v1 = static_cast<vrsta1>(tmpVrsta);
    tok.ignore();

    std::cout << "Unesite tip predstave: ";
    std::getline(tok, predstava.tip);

    return tok;
}

std::ostream& operator<<(std::ostream& os, const Predstava& p) {
    os << "\tNaziv: " << p.getNaziv() << std::endl;
    os << "\tBroj ulaznica: " << p.getBrUlaznica() << std::endl;
    os << "\tCijena ulaznice: " << p.getCijena() << std::endl;
    os << "\tVrijeme trajanja: " << p.getVrijeme() << std::endl;
    os << "\tVrsta: " << static_cast<int>(p.getVrsta()) << " - djeca[0] odrasli[1]" << std::endl;
    return os << "\tTip: " << p.getTip() << std::endl;
}

std::ofstream& operator<<(std::ofstream& ofs, const Predstava& predstava) {
    ofs << predstava.getNaziv() << std::endl;
    ofs << predstava.getBrUlaznica() << " "
        << predstava.getCijena() << " "
        << predstava.getVrijeme() << " "
        << static_cast<int>(predstava.getVrsta()) << std::endl;
    ofs << predstava.getTip() << std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Predstava& predstava) {
    char pHolder;
    std::getline(ifs, predstava.naziv);
    int tmpVrsta{ 0 };
    ifs >> predstava.brUlaznica
        >> predstava.cijena
        >> predstava.vrijeme
        >> tmpVrsta;
    predstava.v1 = static_cast<vrsta1>(tmpVrsta);
    pHolder = ifs.get();
    std::getline(ifs, predstava.tip);
    return ifs;
}

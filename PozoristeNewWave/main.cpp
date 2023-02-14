#include <iostream>
#include <vector>
#include "Film.h"
#include "Predstava.h"
#include "Projekcija.h"

// Naslovna stranica
void naslov()
{
	std::cout << "\t\t\t\t\t\tPozoriste NEW WAVE" << std::endl;
	std::cout << "\t\t\t\t -----------------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|\tPravi izbor za ljubitelje umjetnosti\t|" << std::endl;
	std::cout << "\t\t\t\t -----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t\t Odaberite jednu od ponudenih opcija za nastavak " << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t\t -----------------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|\t\t | \t\t\t\t|" << std::endl;
	std::cout << "\t\t\t\t|\t\t |  1. Pregledaj projekcije\t| " << std::endl;
	std::cout << "\t\t\t\t|     NEW  \t |  2. Kupi kartu\t\t| " << std::endl;
	std::cout << "\t\t\t\t|     WAVE  \t |  3. Dodaj projekciju\t\t| " << std::endl;
	std::cout << "\t\t\t\t|\t\t |  4. Izlaz\t\t\t| " << std::endl;
	std::cout << "\t\t\t\t|\t\t | \t\t\t\t|" << std::endl;
	std::cout << "\t\t\t\t -----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

// Trazi ulaz za film i ispisuje ga u fajl
void UnesiNoviFilm() {
	std::cin.ignore();
	Film film;
	std::cin >> film;
	std::ofstream izlaz("./filmovi.txt", std::ios_base::app | std::ios_base::out);
	izlaz << film;
}

// Trazi ulaz za predstavu i ispisuje je u fajl
void UnesiNovuPredstavu() {
	std::cin.ignore();
	Predstava predstava;
	std::cin >> predstava;
	std::ofstream izlaz1("./predstave.txt", std::ios_base::app | std::ios_base::out);
	izlaz1 << predstava;
}

// Vraca sve filmove iz filmovi.txt datoteke
std::vector<Film> DajFilmove() {
	std::ifstream ulaz("./filmovi.txt");

	if (!ulaz)
		throw std::logic_error("Datoteka filmovi.txt ne postoji");

	std::vector<Film> filmovi;
	auto tempFilm = std::make_shared<Film>();
	while (ulaz >> *tempFilm) {
		filmovi.push_back(*tempFilm);
	}

	if (!ulaz.eof())
		throw std::logic_error("Problem pri citanju datoteke filmovi.txt");

	return filmovi;
}

// Vraca sve predstave iz predstav.txt datoteke
std::vector<Predstava> DajPredstave() {
	std::ifstream ulaz1("./predstave.txt");

	if (!ulaz1)
		throw std::logic_error("Datoteka predstave.txt ne postoji");

	std::vector<Predstava> predstava;
	Predstava tempPredstava;

	while (ulaz1 >> tempPredstava) {
		predstava.push_back(tempPredstava);
	}

	if (!ulaz1.eof())
		throw std::logic_error("Problem pri citanju datoteke predstave.txt");

	return predstava;
}

// Ispisuje sve filmove
void IspisiSveFilmove() {
	std::vector<Film> filmovi = DajFilmove();
	std::cout << "\tPrikaz svih filmova iz fajla:" << std::endl;
	std::cout << std::endl;
	std::cout << "\t*****************************" << std::endl;
	for (const Film& film : filmovi) {
		std::cout << film;
		std::cout << "\t-----------------------------" << std::endl;
	}
}

// Ispisuje sve predstave
void IspisiSvePredstave() {
	std::vector<Predstava> predstava = DajPredstave();
	std::cout << "\tPrikaz svih predstava iz fajla:" << std::endl;
	std::cout << std::endl;
	std::cout << "\t******************************" << std::endl;
	for (const Predstava& p : predstava) {
		std::cout << p;
		std::cout << "\t------------------------------" << std::endl;
	}
}

int main(){
	int ID;
	int a = 176;
	srand(time(NULL));
	rand();
	int b, c, d;
	c = rand() % 3 + 1;
	b = rand() % 6 + 65;
	d = rand() % 25 + 1;
	std::cout << std::endl;
	Film filmic;
	Predstava predstavica;
	Projekcija* temp = &filmic;
	Projekcija* temp2 = &predstavica;
	int opcija;
	do
	{
		naslov();
		std::cout << "\t\t\t\t\t";
		//temp->print();
		std::cout << "\tUnesite opciju: ";
		std::cin >> opcija;
		switch (opcija)
		{
		case 1:
			system("CLS");
			int izbor;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t\t\t1.Filmovi\n";
			std::cout << "\t\t\t\t\t\t2.Predstave\n";
			std::cout << "\t\t\t\t\t\tOpcija: ";
			do
			{
				std::cin >> izbor;
				switch (izbor)
				{
				case 1:
					system("cls");
					std::cout << std::endl;
					std::cout << "\t\t\t\t\t\t";
					temp->print();
					IspisiSveFilmove();
					system("pause");
					break;
				case 2:
					system("cls");
					std::cout << std::endl;
					std::cout << "\t\t\t\t\t\t";
					temp2->print();
					IspisiSvePredstave();
					system("pause");
					break;
				}
			} while (izbor != 1 && izbor != 2);
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("cls");
			int choice;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t\t\t1.Filmovi\n";
			std::cout << "\t\t\t\t\t\t2.Predstave\n";
			std::cout << "\t\t\t\t\tUnesite za sto zelite kupiti ulaznicu: ";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				system("cls");
				IspisiSveFilmove();
				std::string movie;
				std::cout << std::endl;
				std::cout << "\tUnesite film za koji zelite kupiti ulaznicu: ";
				std::cin >> movie;
				int price, ulaznica;
				try {
					std::vector<Film> filmovi2 = DajFilmove();
					std::cout << std::endl;
					std::ofstream modificirani_izlaz("novi.txt", std::ios_base::trunc);
					for (int i = 0; i < filmovi2.size(); i++)
					{
						if (filmovi2[i].getNaziv() == movie)
						{
							std::cout << "\tUspjesno pretrazivanje!\n";
							int price;
							int ulaznica;
							std::cout << std::endl;
							std::cout << "\tUnesite broj ulaznica za film: ";
							std::cin >> ulaznica;
							std::cin.ignore();
							if (ulaznica > filmovi2[i].getBrUlaznica())
							{
								std::cout << "\tNema toliko ulaznica na raspolaganju! ";
								system("pause");
							}
							else
							{
								std::cout << "\tUspjesno ste kupili ulaznice za projekciju.\n";
								filmovi2[i].brUlaznica -= ulaznica;
								price = filmovi2[i].getCijena() * ulaznica;
								std::cout << "\tCijena iznosi:" << price << " KM.\n";
								system("pause");
								system("cls");
								std::cout << std::endl;
								std::cout << "\t\t\t\t _______________________________________________ \n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| Serijski broj: " << b << "\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| " << filmovi2[i].getNaziv() << "\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t| NEW\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t| WAVE\t|\n";
								std::cout << "\t\t\t\t| Februar," << d << ".\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| Cijena: " << price << " KM\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|   D" << c << "\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t ----------------------------------------------- \n";
								std::cout << std::endl;
								std::cout << "\t\t\t\t Hvala na posjeti!  \n";
								std::cout << std::endl;
								std::cout << "\t\t\t\t The play is not in the words, it is in you. Stella Adler  ";
								std::cout << std::endl;
								std::cout << std::endl;
								system("pause");
								system("cls");
							}
						}
						modificirani_izlaz << filmovi2[i];
					}
					modificirani_izlaz.close();
					if (std::remove("./filmovi.txt") == 0)
					{
						if (std::rename("./novi.txt", "./filmovi.txt") != 0)
						{
							std::cout << "Neuspjesno preimenovanje modificirane datoteke";
							return 2;
						}
					}
					else
					{
						std::cout << "Neuspjesno brisanje datoteke filmovi.txt";
						return 1;
					}
					break;
				}
				catch (std::exception& ex)
				{
					std::cout << "Greska: " << ex.what();
				}
			}
			case 2:
			{
				system("cls");
				IspisiSvePredstave();
				std::string show;
				std::cout << std::endl;
				std::cout << "\tUnesite predstavu za koju zelite kupiti ulaznicu: ";
				std::cin >> show;
				int ulaznica2, price2;
				try {
					std::vector<Predstava> predstave2 = DajPredstave();
					std::cout << std::endl;
					std::ofstream modificirani_izlaz2("novi2.txt", std::ios_base::trunc);
					for (int i = 0; i < predstave2.size(); i++)
					{
						if (predstave2[i].getNaziv() == show)
						{
							std::cout << "\tUspjesno pretrazivanje!\n";
							std::cout << std::endl;
							std::cout << "\tUnesite broj ulaznica za predstavu: ";
							std::cin >> ulaznica2;
							std::cin.ignore();
							if (ulaznica2 > predstave2[i].getBrUlaznica())
							{
								std::cout << "\tNema toliko ulaznica na raspolaganju! ";
								system("pause");
							}
							else
							{
								std::cout << "\tUspjesno ste kupili ulaznice za projekciju.\n";
								predstave2[i].brUlaznica -= ulaznica2;
								price2 = predstave2[i].getCijena() * ulaznica2;
								std::cout << "\tCijena iznosi:" << price2 << " KM.\n";
								system("pause");
								system("cls");
								std::cout << std::endl;
								std::cout << "\t\t\t\t _______________________________________________ \n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| Serijski broj: " << b << "\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| " << predstave2[i].getNaziv() << "\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t| NEW\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t| WAVE\t|\n";
								std::cout << "\t\t\t\t| Februar," << d << ".\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t| Cijena: " << price2 << " KM\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|   D" << c << "\t|\n";
								std::cout << "\t\t\t\t|\t\t\t\t\t|\t|\n";
								std::cout << "\t\t\t\t ----------------------------------------------- \n";
								std::cout << std::endl;
								std::cout << "\t\t\t\t Hvala na posjeti!  \n";
								std::cout << std::endl;
								std::cout << "\t\t\t\t The play is not in the words, it is in you. Stella Adler  ";
								std::cout << std::endl;
								std::cout << std::endl;
								system("pause");
								system("cls");
							}
						}
						modificirani_izlaz2 << predstave2[i];
					}
					modificirani_izlaz2.close();
					if (std::remove("./predstave.txt") == 0)
					{
						if (std::rename("./novi2.txt", "./predstave.txt") != 0)
						{
							std::cout << "Neuspjesno preimenovanje modificirane datoteke";
							return 2;
						}
					}
					else
					{
						std::cout << "Neuspjesno brisanje datoteke predstave2.txt";
						return 1;
					}
					break;
				}
				catch (std::exception& ex)
				{
					std::cout << "Greska: " << ex.what();
				}
			}
			}
			system("CLS");
			break;
		case 3:
			system("CLS");
			int izbor1;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t\t\tUnesite ID: ";
			std::cin >> ID;
			if (ID != a )
			{
				std::cout << "\t\t\t\t\t\tGreska! Nemate pristup!";
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\t\t\t\t\t\t1.Unos Filmova\n";
				std::cout << "\t\t\t\t\t\t2.Unos Predstava\n";
				std::cout << "\t\t\t\t\t\tOpcija: ";
				do
				{
					std::cin >> izbor1;
					switch (izbor1)
					{
					case 1:
						system("cls");
						std::cout << std::endl;
						UnesiNoviFilm();
						system("pause");
						break;
					case 2:
						system("cls");
						std::cout << std::endl;
						UnesiNovuPredstavu();
						system("pause");
						break;
					}
				} while (izbor1 != 1 && izbor1 != 2);
			}
			system("PAUSE");
			system("CLS");
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "\t\t\t\t\tKraj!\n";
			system("pause");
			break;
		default:
			std::cout << "Pogresan izbor!";
			system("pause");
			system("cls");
		}

	} while (opcija != 4);

	return 0;
}

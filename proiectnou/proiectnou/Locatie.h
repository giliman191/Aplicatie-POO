#pragma once
#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;
#pragma warning(disable:4996)
class Locatie
{
	/*
		Clasa Locatie = COMPLET
	* SETTER SI GETTER:
	char* nume_locatie; sett + gett: bifat
	int nr_zone; sett + gett: bifat
	int* nr_locuri; sett + gett : bifat
	int nr_randuri; sett + gett : bifat

	*OPERATOR
	>>, << : bifat
	++, = , [] :bifat

	*CONSTRUCTORI:fara p, cu p, de copiere : BIFAT
	*DESTRUCTOR: BIFAT
	METODE:
	- metoda care calculeaza nr total de locuri dintr-o locatie : bifat
	- metoda care calculeaza cat % din locuri sunt ocupate : bifat
	- metoda care afiseaza cat% din locuri sunt ocupate ( folosind metoda de mai sus) : bifat
	*/
private:
	char* nume_locatie;
	int nr_zone; /// cate zone sunt in total
	struct loc_ocupat
	{
		int* nr_loc;
		int nr_rand;
		int** nr_zona;
	};
	loc_ocupat* locuri_ocupate;
public:
	Locatie() /// constructor implicit
	{
		this->nume_locatie = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_locatie, "Necunoscut");
		this->nr_zone = 0;
		locuri_ocupate = nullptr;
	}


	
	Locatie(const char* nume_locatie, int nr_zone, loc_ocupat* locuri_ocupate) /// constructor cu parametri
	{
		if (nume_locatie != NULL)
		{
			this->nume_locatie = new char[strlen(nume_locatie) + 1];
			strcpy(this->nume_locatie, nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}
		this->nr_zone = nr_zone;
		
		if (this->locuri_ocupate != NULL)
		{
			for (int i = 1; i <= nr_zone; i++)
			{
				for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
				{
					delete[] locuri_ocupate[i].nr_zona[j];
				}
				delete[] locuri_ocupate[i].nr_zona;
			}
			delete[] this->locuri_ocupate;
			this->locuri_ocupate = nullptr;
		}
		else this->locuri_ocupate = nullptr;
	}


	
	Locatie(const Locatie& l) /// constructor copiere
	{
		if (l.nume_locatie != NULL) /// validare
		{
			this->nume_locatie = new char[strlen(l.nume_locatie) + 1];
			strcpy(this->nume_locatie, l.nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}
		this->nr_zone = l.nr_zone;

		if (l.locuri_ocupate != NULL)
		{
			if (this->locuri_ocupate != NULL)
			{
				for (int i = 1; i <= this->nr_zone; i++)
				{
					for (int j = 1; j <= this->locuri_ocupate[i].nr_rand; j++)
					{
						delete[] this->locuri_ocupate[i].nr_zona[j];
					}
					delete[] this->locuri_ocupate[i].nr_zona;
				}
				delete[] this->locuri_ocupate;
				this->locuri_ocupate = nullptr;
			}

			this->locuri_ocupate = new loc_ocupat[l.nr_zone + 2];
			for (int i = 1; i <= l.nr_zone; i++)
			{
				this->locuri_ocupate[i].nr_rand = l.locuri_ocupate[i].nr_rand;
				this->locuri_ocupate[i].nr_loc = new int[l.locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
				{
					this->locuri_ocupate[i].nr_loc[j] = l.locuri_ocupate[i].nr_loc[j];
				}
				this->locuri_ocupate[i].nr_zona = new int* [l.locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
				{
					this->locuri_ocupate[i].nr_zona[j] = new int[l.locuri_ocupate[i].nr_loc[j] + 2];
					for (int k = 1; k <= l.locuri_ocupate[i].nr_loc[j]; k++)
					{
						this->locuri_ocupate[i].nr_zona[j][k] = l.locuri_ocupate[i].nr_zona[j][k];
					}
				}
			}
		}
		else this->locuri_ocupate = nullptr;
	}


	
	~Locatie() /// destructor
	{
		if (this->nume_locatie != NULL)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = NULL;
		}
		if (this->locuri_ocupate != NULL)
		{
			for (int i = 1; i <= nr_zone; i++)
			{
				for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
				{
					delete[] locuri_ocupate[i].nr_zona[j];
				}
				delete[] locuri_ocupate[i].nr_zona;
			}
			delete[] this->locuri_ocupate;
			this->locuri_ocupate = NULL;
		}
	}


	
	Locatie& operator=(Locatie& l) // constructorul de copiere
	{
		
		if (this->nume_locatie != NULL)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = NULL;
		}
		if (l.nume_locatie != NULL)
		{
			this->nume_locatie = new char[strlen(l.nume_locatie) + 1];
			strcpy(this->nume_locatie, l.nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}


		this->nr_zone = l.nr_zone;
		if (l.locuri_ocupate != NULL)
		{
			if (this->locuri_ocupate != NULL)
			{
				for (int i = 1; i <= this->nr_zone; i++)
				{
					for (int j = 1; j <= this->locuri_ocupate[i].nr_rand; j++)
					{
						delete[] this->locuri_ocupate[i].nr_zona[j];
					}
					delete[] this->locuri_ocupate[i].nr_zona;
				}
				delete[] this->locuri_ocupate;
				this->locuri_ocupate = nullptr;
			}

			this->locuri_ocupate = new loc_ocupat[l.nr_zone + 2];
			for (int i = 1; i <= l.nr_zone; i++)
			{
				this->locuri_ocupate[i].nr_rand = l.locuri_ocupate[i].nr_rand;
				this->locuri_ocupate[i].nr_loc = new int[l.locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
				{
					this->locuri_ocupate[i].nr_loc[j] = l.locuri_ocupate[i].nr_loc[j];
				}
				this->locuri_ocupate[i].nr_zona = new int* [l.locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
				{
					this->locuri_ocupate[i].nr_zona[j] = new int[l.locuri_ocupate[i].nr_loc[j] + 2];
					for (int k = 1; k <= l.locuri_ocupate[i].nr_loc[j]; k++)
					{
						this->locuri_ocupate[i].nr_zona[j][k] = l.locuri_ocupate[i].nr_zona[j][k];
					}
				}
			}
		}
		else this->locuri_ocupate = nullptr;
		return *this;
	}



	friend ostream& operator<<(ostream& out, Locatie& l)
	{
		out << "Nume locatie: " << l.nume_locatie << endl;
		out << "Numar zone: " << l.nr_zone << endl;
		for (int i = 1; i <= l.nr_zone; i++)
		{
			out << "Numar randuri pe zona " << i << ": " << l.locuri_ocupate[i].nr_rand << endl;
			for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
			{
				out << "Numar locuri pe randul " << j << ": " << l.locuri_ocupate[i].nr_loc[j] << endl;
			}
			out << endl;
		}

		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Locatie& l)
	{
		int x;
		char buffer[100];
		cout << "Nume locatie: ";
		in >> ws;/// citeste spatiile before buffer
		cin.getline(buffer, 99);
		if (l.nume_locatie != NULL)
			delete[] l.nume_locatie;
		l.nume_locatie = new char[strlen(buffer) + 1];
		strcpy(l.nume_locatie, buffer);
		cout << "\n";
		cout << "Numar zone: ";
		in >> l.nr_zone;
		cout << "\n";
		if (l.locuri_ocupate != nullptr) delete[] l.locuri_ocupate;
		l.locuri_ocupate = new loc_ocupat[l.nr_zone + 2];
		for (int i = 1; i <= l.nr_zone; i++)
		{
			cout << "Introduceti numarul de randuri pentru zona " << i << ": ";
			in >> l.locuri_ocupate[i].nr_rand;
			l.locuri_ocupate[i].nr_zona = new int* [l.locuri_ocupate[i].nr_rand + 2];
			l.locuri_ocupate[i].nr_loc = new int[l.locuri_ocupate[i].nr_rand + 2];
			cout << "\n";
			for (int j = 1; j <= l.locuri_ocupate[i].nr_rand; j++)
			{
				cout << "Introduceti numarul de locuri pentru randul " << j << ": ";
				in >> x;
				l.locuri_ocupate[i].nr_loc[j] = x;
				l.locuri_ocupate[i].nr_zona[j] = new int[x+2];
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "\n";
		return in;
	}
	/// cei doi operatori
	friend Locatie operator ++(Locatie& t)
	{
		t.nr_zone++;
		return t;
	}
	friend Locatie operator++(Locatie& t, int)
	{
		Locatie copie = t;
		t.nr_zone++;
		return copie;
	}
	int& operator[](int poz)
	{
		if (poz >= 0 && poz < nr_zone)
			return locuri_ocupate[poz].nr_rand;
		else throw new exception("Nu exista aceasta zona");
	}
	
	
	int getNr_Zone()
	{
		return nr_zone;
	}
	void SetNr_Zone(int nr_zone)
	{
		this->nr_zone = nr_zone;
	}

	int getNr_Randuri(int zona)
	{
		if (locuri_ocupate != NULL and zona <= this->nr_zone) return locuri_ocupate[zona].nr_rand;
		else return 0;
	}
	loc_ocupat* getLocuri_ocupate()
	{
		if (locuri_ocupate != nullptr && nr_zone > 0) // deep copy
		{
			loc_ocupat* copie = new loc_ocupat[nr_zone + 2];

			for (int i = 1; i <= nr_zone; i++)
			{
				copie[i].nr_rand = locuri_ocupate[i].nr_rand;
				copie[i].nr_loc = new int[locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
				{
					copie[i].nr_loc[j] = locuri_ocupate[i].nr_loc[j];
				}
				copie[i].nr_zona = new int* [locuri_ocupate[i].nr_rand + 2];
				for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
				{
					copie[i].nr_zona[j] = new int[locuri_ocupate[i].nr_loc[j] + 2];
					for (int k = 1; k <= locuri_ocupate[i].nr_loc[j]; k++)
					{
						copie[i].nr_zona[j][k] = locuri_ocupate[i].nr_zona[j][k];
					}
				}
			}
			return copie;
		}
		else return nullptr;
	}


	void setNr_Locuri(int nr_zone, loc_ocupat* locuri_ocupate)
	{
		this-> nr_zone = nr_zone;
		if (this->locuri_ocupate != nullptr)
		{
			delete[] this->locuri_ocupate;
			this->locuri_ocupate = nullptr;
		}
		if (nr_zone > 0 )
		{
			this->locuri_ocupate = new loc_ocupat[nr_zone + 2];
			this->locuri_ocupate = locuri_ocupate;
		}

		else this->locuri_ocupate = nullptr;
	}
	char* getNume_Locatie()
	{
		if (nume_locatie != nullptr) /// deep copy
		{
			char* copie = new char[strlen(nume_locatie) + 1];
			strcpy(copie, nume_locatie);
			return copie;
		}
		else return nullptr;
	}
	///int** getNr_zona(int** nr_zona, int zona_curenta)

	void setNume_Locatie(const char* nume_locatie)
	{
		if (this->nume_locatie != nullptr)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = nullptr;
			if (nume_locatie != nullptr)
			{
				this->nume_locatie = new char[strlen(nume_locatie) + 1];
				strcpy(this->nume_locatie, nume_locatie);
			}
			else this->nume_locatie = nullptr;
		}
	}
	int Numar_Locuri_Totale()
	{
		int ct = 0;
		for (int i = 1; i <= this->nr_zone; i++)
		{
			for (int j = 1; j <= this->locuri_ocupate[i].nr_rand; j++)
			{
				ct += this->locuri_ocupate[i].nr_loc[j];
			}
		}
		return ct;
	}
	double Procent_Locuri_ocupate()
	{
		double ct = 0;

		for (int i = 1; i <= this->nr_zone; i++)
		{
			for (int j = 1; j <= this->locuri_ocupate[i].nr_rand; j++)
			{
				for (int k = 1; k <= this->locuri_ocupate[i].nr_loc[j]; k++)
					if (this->locuri_ocupate[i].nr_zona[j][k] == 1)
						ct++;
			}
		}
		if (ct == 0) return 0;
		return ct / Numar_Locuri_Totale();
	}
	void Afisare_Procent_Locuri_Ocupate()
	{
		cout << "Sunt ocupate " << Procent_Locuri_ocupate() << "% din locuri" << endl;
	}

	int getNrLocuriPeRand(int zona, int rand)
	{
		if (zona < 0) return 0;
		return locuri_ocupate[zona].nr_loc[rand];
	}

	void Generare_Bilete_Aleatoriu()
	{
		int ct = 0;
		for (int i = 1; i <= nr_zone; i++) // cate zone am
		{
			for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++) // cate randuri pe zona am
			{
				ct = 1 + (rand() % locuri_ocupate[i].nr_loc[j]); // nr_loc[j] reprezinta numarul de locuri pe randul j
				for (int pas = 1; pas <= ct; pas++) // merg pe fiecare rand
				{
					locuri_ocupate[i].nr_zona[j][pas] = 1000+(rand()%10000);
				}
			}
		}
	}
	void Initializare_Zone()
	{
		for (int i = 1; i <= nr_zone; i++)
		{
			for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
			{
				for (int k = 1; k <= locuri_ocupate[i].nr_loc[j]; k++)
					locuri_ocupate[i].nr_zona[j][k] = 0;
			}
		}
	}
	void Afisare_Locuri()
	{
		for (int i = 1; i <= nr_zone; i++)
		{
			for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
			{
				for (int k = 1; k <= locuri_ocupate[i].nr_loc[j]; k++)
					cout << locuri_ocupate[i].nr_zona[j][k] << " ";
				cout << "\n";
			}
			cout << "\n";
			cout << "\n";
		}
	}

	int VerificaLoc(int zona, int rand, int loc, int id)
	{
		if (locuri_ocupate[zona].nr_zona[rand][loc] == id) return 1;
		return 0;
	}
	int VerificaLoc(int zona, int rand, int loc)
	{
		if (locuri_ocupate[zona].nr_zona[rand][loc] == 0) return 1;
		return 0;
	}
	void Afisare_Locuri_Disponibile()
	{
		for (int i = 1; i <= nr_zone; i++)
		{
			for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
			{
				for (int k = 1; k <= locuri_ocupate[i].nr_loc[j]; k++)
					if (locuri_ocupate[i].nr_zona[j][k] == 0) cout << "zona= " << i << " randul= " << j << " locul=" << k << "\n";
				cout << "\n";
			}
			cout << "\n";
			cout << "\n";
		}
	}

	int Numar_Locuri_Disponibile()
	{
		int ct = 0;
		for (int i = 1; i <= nr_zone; i++)
		{
			for (int j = 1; j <= locuri_ocupate[i].nr_rand; j++)
			{
				for (int k = 1; k <= locuri_ocupate[i].nr_loc[j]; k++)
					if (locuri_ocupate[i].nr_zona[j][k] == 0) ct++;
			}

		}
		return ct;
	}

	void setLoc(int id, int zona, int rand, int loc)
	{
		locuri_ocupate[zona].nr_zona[rand][loc] = id;
	}

};
#pragma once
#include<iostream>
#include<cstring>
#include <fstream>
#include "Taxa.h"
using namespace std;
#pragma warning(disable:4996)
class Bilet : public Taxa /// derivare clasa abstracta
{
	/*
		Clasa Bilet = BIFAT
	* SETTER SI GETTER:
	const int id_bilet=0; getter: bifat
	static int contor; getter: bifat
	int nr_loc; setter si getter: bifat
	int nr_rand; setter si getter: bifat
	int nr_zona; setter si getter: bifat
	float pret; setter si getter: bifat
	char* categorie; /// VIP, etc setter si getter: bifat

	*OPERATOR
	>>, << : bifat
	==, = , != :bifat

	*CONSTRUCTORI:fara p, cu p, de copiere : BIFAT
	*DESTRUCTOR: BIFAT

	METODE:
	-functie statica PRETMAXIM: BIFAT
	-interschimba bilet: BIFAT
	-verifica bilet: BIFAT

	*/
private:
	const int id_bilet = 0;
	static int contor;
	int nr_loc;
	int nr_rand;
	int nr_zona;
	double pret;
	char* categorie; /// VIP, etc
public:
	Bilet() : id_bilet(0)
	{
		this->categorie = new char[strlen("Necunoscut") + 1];
		strcpy(this->categorie, "Necunoscut");
		this->nr_loc = 0;
		this->nr_rand = 0;
		this->nr_zona = 0;
		this->pret = 0;
	}
	Bilet(int nr_loc, int nr_rand, int nr_zona, double pret, const char* categorie) : id_bilet(++contor)
	{
		if (categorie != NULL) /// validare
		{
			this->categorie = new char[strlen(categorie) + 1];
			strcpy(this->categorie, categorie);
		}
		else
		{
			this->categorie = new char[strlen("Necunoscut") + 1];
			strcpy(this->categorie, "Necunoscut");
		}
		this->nr_loc = nr_loc;
		this->nr_rand = nr_rand;
		this->nr_zona = nr_zona;
		this->pret = pret;
	}
	
	Bilet(const Bilet& b) : id_bilet(b.id_bilet)
	{
		if (b.categorie != NULL) /// validare
		{
			this->categorie = new char[strlen(b.categorie) + 1];
			strcpy(this->categorie, b.categorie);
		}
		else
		{
			this->categorie = new char[strlen("Necunoscut") + 1];
			strcpy(this->categorie, "Necunoscut");
		}
		this->nr_loc = b.nr_loc;
		this->nr_rand = b.nr_rand;
		this->nr_zona = b.nr_zona;
		this->pret = b.pret;
	}
	Bilet operator=(Bilet b)
	{
		if (this->categorie != NULL)
			delete[] this->categorie;
		if (b.categorie != NULL) /// validare
		{
			this->categorie = new char[strlen(b.categorie) + 1];
			strcpy(this->categorie, b.categorie);
		}
		else
		{
			this->categorie = new char[strlen("Necunoscut") + 1];
			strcpy(this->categorie, "Necunoscut");
		}
		this->nr_loc = b.nr_loc;
		this->nr_rand = b.nr_rand;
		this->nr_zona = b.nr_zona;
		this->pret = b.pret;

		return *this;
	}
	double tva() 
	{
		return pret * 19 / 100;
	}

	static int getContor() /// Metoda statica
	{
		return contor;
	}
	//
	char* getCategorie()
	{
		if (this->categorie != NULL)
			return this->categorie;
		else
			return NULL;
	}
	void setCategorie(const char* categorie)
	{
		if (this->categorie != NULL)
			delete[] this->categorie;
		if (categorie != NULL) /// validare
		{
			this->categorie = new char[strlen(categorie) + 1];
			strcpy(this->categorie, categorie);
		}
		else
		{
			this->categorie = new char[strlen("Necunoscut") + 1];
			strcpy(this->categorie, "Necunoscut");
		}
	}
	// IDBILET
	static int getIdBilet()
	{
		return contor;
	}
	//NR.LOC
	int getNrLoc()
	{
		return this->nr_loc;
	}
	void setNrLoc(int nr_loc)
	{
		this->nr_loc = nr_loc;
	}
	// NR.RAND
	int getNrRand()
	{
		return this->nr_rand;
	}
	void setNrRand(int nr_rand)
	{
		this->nr_rand = nr_rand;
	}
	// ZONA
	int getNrZona()
	{
		return this->nr_zona;
	}
	void setNrZona(int nr_zona)
	{
		this->nr_zona = nr_zona;
	}
	// PRET
	double getPret()
	{
		return this->pret;
	}
	void setPret(double pret)
	{
		this->pret = pret;
	}
	//
	bool operator ==(Bilet b) /// supraincarcare operator ==
	{
		if (this->id_bilet == b.id_bilet)
			return true;
		else
			return false;
	}
	bool operator !=(Bilet b) /// supraincarcare operator !=
	{
		if (this->categorie != b.categorie)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, Bilet b)
	{
		out << "Id bilet: " << b.id_bilet << endl;
		out << "Numar loc: " << b.nr_loc << endl;
		out << "Numar rand: " << b.nr_rand << endl;
		out << "Numar zona: " << b.nr_zona << endl;
		out << "Pret: " << b.pret << endl;
		out << "Categorie: " << b.categorie << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Bilet& b)
	{
		char buffer[100]; ///
		cout << "Categorie la care este biletul dumneavoastra este : ";
		in >> ws;
		in.getline(buffer,99);
		if (b.categorie != NULL)
			delete[] b.categorie;
		if (buffer != NULL) /// validare
			{
			b.categorie = new char[strlen(buffer) + 1];
			strcpy(b.categorie, buffer);
			}
		else
		{
			b.categorie = new char[strlen("Necunoscut") + 1];
			strcpy(b.categorie, "Necunoscut");
		}
		cout << "\n";
		cout << "Numar loc: ";
		in >> b.nr_loc;
		cout << "\n";
		cout << "Numar rand: ";
		in >> b.nr_rand;
		cout << "\n";
		cout << "Numar zona: ";
		in >> b.nr_zona;
		cout << "\n";
		cout << "Pret: ";
		
		double ct = 1;
		if (b.nr_zona == 1) ct *= 50;
		else if (b.nr_zona > 1 && b.nr_zona <= 3) ct *= 25;

		if (b.nr_rand >= 1 && b.nr_rand <= 3) ct *= 2;
		else if (b.nr_rand > 3) ct *= 1.5;

		if (b.nr_loc >= 1 && b.nr_loc <= 5) ct *= 1.2;
		else if (b.nr_loc >= 6 && b.nr_loc <= 9) ct *= 1.5;
		else if (b.nr_loc >= 10) ct *= 1.2;
		b.pret = ct;
		cout << b.pret;
		cout << "\n";
		return in;
	}
	/// metodele generice

	void InterschimbaScaun(Bilet& b) /// o functie
	{
		int aux;
		aux = this->nr_loc;
		this->nr_loc = b.nr_loc;
		b.nr_loc = aux;
		aux = this->nr_rand;
		this->nr_rand = b.nr_rand;
		b.nr_rand = aux;
		aux = this->nr_zona;
		this->nr_zona = b.nr_zona;
		b.nr_zona = aux;
	}
	int VerificaBilet() // a doua functie
	{
		if (this->nr_loc < 0 || this->nr_loc>100)
			return 0;
		if (this->nr_rand < 0 || this->nr_rand>100)
			return 0;
		if (this->nr_zona < 0 || this->nr_zona>100)
			return 0;
		if (this->pret < 0)
			return 0;
		return 1;
	}
	static int PretMaxim(Bilet* bilete, int nr_bilete) /// o functie statica ce returneaza id ul biletului cu pretul maxim
	{
		int id_max = 0;
		double pret_max = 0;
		for (int i = 0; i < nr_bilete; i++)
		{
			if (bilete[i].pret > pret_max)
			{
				pret_max = bilete[i].pret;
				id_max = bilete[i].id_bilet;
			}
		}
		return bilete[id_max].id_bilet;
	}
	~Bilet() /// destructor
	{
		if (this->categorie != NULL)
		{
			delete[] this->categorie;
			this->categorie = NULL;
		}
	}
	
	void Write_binary()
	{
		
			ofstream f("bilet.bin", ios::out | ios::binary);
			f.write((char*)&this->id_bilet, sizeof(this->id_bilet));
			f.write((char*)&this->nr_loc, sizeof(this->nr_loc));
			f.write((char*)&this->nr_rand, sizeof(this->nr_rand));
			f.write((char*)&this->nr_zona, sizeof(this->nr_zona));
			f.write((char*)&this->pret, sizeof(this->pret));
			f.write((char*)&this->categorie, sizeof(this->categorie));
			f.close();
		
	}
};
int Bilet::contor = 0;
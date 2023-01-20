#pragma once
#include<iostream>
#include<cstring>
#include <fstream>
#include "Eveniment.h"
using namespace std;
#pragma warning(disable:4996)
class Invitat : public Eveniment
{
private:
	char* nume;
	char* prenume;
public:
	Invitat()
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->prenume = new char[strlen("Necunoscut") + 1];
		strcpy(this->prenume, "Necunoscut");
	}
	Invitat(char* nume, char* prenume, const char* nume_eveniment, int zi, int luna, int an, int ora, int minut) :Eveniment(nume_eveniment, zi, luna, an, ora, minut)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (prenume != nullptr)
		{
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else
		{
			this->prenume = new char[strlen("Necunoscut") + 1];
			strcpy(this->prenume, "Necunoscut");
		}
	}
	Invitat(const Invitat& l) :Eveniment(l)
	{
		if (l.nume != nullptr)
		{
			this->nume = new char[strlen(l.nume) + 1];
			strcpy(this->nume, l.nume);
		}
		else
		{
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		
		if (l.prenume != nullptr)
		{
			this->prenume = new char[strlen(l.prenume) + 1];
			strcpy(this->prenume, l.prenume);
		}
		else
		{
			this->prenume = new char[strlen("Necunoscut") + 1];
			strcpy(this->prenume, "Necunoscut");
		}
	}
	
	~Invitat()
	{
		if (this->nume != nullptr)
		{
			delete[] this->nume;
			this->nume = nullptr;
		}
		if (this->prenume != nullptr)
		{
			delete[] this->prenume;
			this->prenume = nullptr;
		}
	}
	Invitat& operator=(Invitat& l)
	{
		// validari
		if (this->nume != nullptr)
		{
			delete[] this->nume;
			this->nume = nullptr;
		}
		if (this->prenume != nullptr)
		{
			delete[] this->prenume;
			this->prenume = nullptr;
		}

		
		if (l.nume != nullptr)
		{
			this->nume = new char[strlen(l.nume) + 1];
			strcpy(this->nume, l.nume);
		}
		else
		{
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		
		
		if (l.prenume != nullptr)
		{
			this->prenume = new char[strlen(l.prenume) + 1];
			strcpy(this->prenume, l.prenume);
		}
		else
		{
			this->prenume = new char[strlen("Necunoscut") + 1];
			strcpy(this->prenume, "Necunoscut");
		}
		return *this;
	}
	char* getNume()
	{
		if (this->nume != nullptr)
		return this->nume;
	}
	char* getPrenume()
	{
		if (this->prenume != nullptr)
			return this->prenume;
	}
	void setNume(char* nume)
	{
		if (nume != nullptr)
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
				this->nume = nullptr;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
				this->nume = nullptr;
			}
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
	}
	void setPrenume(char* prenume)
	{
		if (prenume != nullptr)
		{
			if (this->prenume != nullptr)
			{
				delete[] this->prenume;
				this->prenume = nullptr;
			}
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else
		{
			if (this->prenume != nullptr)
			{
				delete[] this->prenume;
				this->prenume = nullptr;
			}
			this->prenume = new char[strlen("Necunoscut") + 1];
			strcpy(this->prenume, "Necunoscut");
		}
	}
	friend ostream& operator<<(ostream& out, Invitat& l)
	{
		out << "Nume: " << l.nume << endl;
		out << "Prenume: " << l.prenume << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Invitat& l)
	{
		char buffer[100];
		cout << "Numele invitatului special este: ";
		in >> ws;
		in >> buffer;
		if (l.nume != nullptr)
		{
			delete[] l.nume;
			l.nume = nullptr;
		}
		l.nume = new char[strlen(buffer) + 1];
		strcpy(l.nume, buffer);
		cout << "Prenume invitatului special este: ";
		in >> buffer;
		if (l.prenume != nullptr)
		{
			delete[] l.prenume;
			l.prenume = nullptr;
		}
		l.prenume = new char[strlen(buffer) + 1];
		strcpy(l.prenume, buffer);
		return in;
	}

	void SeteazaDataInceputAn()
	{
		data.zi = 1;
		data.luna = 1;
		data.an = data.an + 1;
	}
	
};
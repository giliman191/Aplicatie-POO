#pragma once
#include<iostream>
#include <fstream>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)
class Eveniment
{
	/*
		Clasa Eveniment =
	* SETTER SI GETTER:
	char* nume_eveniment;
	struct data_eveniment
	{
		int zi; s,g
		int luna; s,g
		int an; s,g
	};
	const int lunile_anului[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; /// vector suplimentar pentru o verificare => nu fac functii pe el
	struct timp
	{
		int ora; s,g
		int minut; s,g
	};

	*OPERATOR
	>>, << : bifat
	+=, = , --  :bifat

	*CONSTRUCTORI:fara p, cu p, de copiere : BIFAT
	*DESTRUCTOR: BIFAT

	METODE:
- verificare_data() : bifat
- verificare_timp() : bifat
ModificaDataEveniment() : bifat

	*/
protected:
	char* nume_eveniment;
	struct data_eveniment
	{
		int zi;
		int luna;
		int an;
	};
	const int lunile_anului[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	data_eveniment data;
	struct timp
	{
		int ora;
		int minut;
	};
	timp t;
public:
	Eveniment() /// constructori cu parametri
	{
		this->nume_eveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_eveniment, "Necunoscut");
		this->data.zi = 0;
		this->data.luna = 0;
		this->data.an = 0;
		this->t.ora = 0;
		this->t.minut = 0;
	}
	Eveniment(const char* nume_eveniment, int zi, int luna, int an, int ora, int minut) /// constructor cu parametri
	{
		if (nume_eveniment != NULL) /// validare 
		{
			this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
			strcpy(this->nume_eveniment, nume_eveniment);
		}
		else
		{
			this->nume_eveniment = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_eveniment, "Necunoscut");
		}
		this->data.zi = zi;
		this->data.luna = luna;
		this->data.an = an;
		this->t.ora = ora;
		this->t.minut = minut;
	}
	Eveniment(const Eveniment& e) /// constructor copiere
	{
		if (e.nume_eveniment != NULL) /// validare
		{
			this->nume_eveniment = new char[strlen(e.nume_eveniment) + 1];
			strcpy(this->nume_eveniment, e.nume_eveniment);
		}
		else
		{
			this->nume_eveniment = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_eveniment, "Necunoscut");
		}
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->t.ora = e.t.ora;
		this->t.minut = e.t.minut;
	}
	Eveniment operator=(Eveniment e) /// operator =
	{
		if (e.nume_eveniment != NULL) /// validare
		{
			this->nume_eveniment = new char[strlen(e.nume_eveniment) + 1];
			strcpy(this->nume_eveniment, e.nume_eveniment);
		}
		else
		{
			this->nume_eveniment = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_eveniment, "Necunoscut");
		}
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->t.ora = e.t.ora;
		this->t.minut = e.t.minut;
		return *this;
	}
	~Eveniment() /// destructor
	{
		if (this->nume_eveniment != NULL)
		{
			delete[] this->nume_eveniment;
			this->nume_eveniment = NULL;
		}
	}
	char* getNumeEveniment(char* nume_eveniment) /// getter
	{
		if (this->nume_eveniment != NULL)
		{
			nume_eveniment = new char[strlen(this->nume_eveniment) + 1];
			strcpy(nume_eveniment, this->nume_eveniment);
		}
		else
		{
			nume_eveniment = new char[strlen("Necunoscut") + 1];
			strcpy(nume_eveniment, "Necunoscut");
		}
		return nume_eveniment;
	}
	void setNumeEveniment(char* nume_eveniment)
	{
		if (this->nume_eveniment != NULL)
			delete[] this->nume_eveniment;
		this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
		strcpy(this->nume_eveniment, nume_eveniment);
	}
	/// <summary>
	/// Getteri pentru timp
	/// </summary>
	/// <returns></returns>
	int getZi()
	{
		return this->data.zi;
	}
	int getLuna()
	{
		return this->data.luna;
	}
	int getAn()
	{
		return this->data.an;
	}
	int getOra()
	{
		return this->t.ora;
	}
	int getMinut()
	{
		return this->t.minut;
	}
	/// <summary>
	/// setteri pentru timp
	/// </summary>
	/// <param name="zi"></param>
	void setZi(int zi)
	{
		this->data.zi = zi;
	}
	void setLuna(int luna)
	{
		this->data.luna = luna;
	}
	void setAn(int an)
	{
		this->data.an = an;
	}
	void setOra(int ora)
	{
		this->t.ora = ora;
	}
	void setMinut(int minut)
	{
		this->t.minut = minut;
	}

	/// <summary>
	/// metoda de afisare
	/// </summary>
	void AfisareProgramEveniment()
	{
		cout << "Data: " << this->data.zi << "." << this->data.luna << "." << this->data.an << endl;
		cout << "Ora: " << this->t.ora << ":" << this->t.minut << endl;
	}
	void ModificaDataEveniment() /// a doua metoda
	{
		int zi, luna, an;
		cout << "Introduceti noua data a evenimentului: ";
		cin >> zi >> luna >> an;
		if (!VerificaData()) /// apelez metoda VerificaData
		{
			cout << "Data introdusa nu este valida " << endl;
			return;
		}
		this->data.zi = zi;
		this->data.luna = luna;
		this->data.an = an;
	}
	int VerificaData() /// o metoda
	{
		if (this->data.an < 2010 || this->data.an>9999)
		{
			return 0;
		}
		if (this->data.luna < 0 || this->data.luna>12)
		{
			return 0;
		}
		if (this->data.zi < 0 || this->data.zi>31)
		{
			return 0;
		}
		if (this->data.luna == 1 || this->data.luna == 3 || this->data.luna == 5 || this->data.luna == 7 || this->data.luna == 8 || this->data.luna == 10 || this->data.luna == 12)
			if (this->data.zi > 31)
			{
				return 0;
			}
		if (this->data.luna == 4 || this->data.luna == 6 || this->data.luna == 9 || this->data.luna == 11)
			if (this->data.zi > 30)
			{
				return 0;
			}
		if (this->data.luna == 2)
			if (this->data.zi > 28)
			{
				return 0;
			}
		return 1;
	}
	int VerificaOra() /// a treia metoda
	{
		if (this->t.ora > 23 && this->t.ora<0)
			return 0;
		if (this->t.minut > 59 && this->t.minut<0)
			return 0;
		return 1;
	}
	
	void ModificaOraEveniment()
	{
		int ora, minut;
		cout << "Introduceti noua ora a evenimentului: ";
		cout << "\n";
		cout << "Ora: ";
		cout << "\n";
		cin >> ora;
		cout << "Minut: ";
		cout << "\n";
		cin>> minut;
		if (!VerificaOra())
		{
			cout << "Ora introdusa nu este valida " << endl;
			return;
		}
		this->t.ora = ora;
		this->t.minut = minut;
	}
	friend ostream& operator<<(ostream& out, Eveniment& e)
	{
		out << "Nume eveniment: " << e.nume_eveniment << endl;
		out << "Data: " << e.data.zi << "." << e.data.luna << "." << e.data.an << endl;
		out << "Ora: " << e.t.ora << ":" << e.t.minut << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Eveniment& e)
	{
		int ok = 0;
		char buffer[100]; // the buffer represents the string that will be read, temporary storage if data
		cout << "Nume eveniment: ";
		in >> ws; // ws represents  spatiul dinaintea sirului
		in.getline(buffer, 99);
		if (e.nume_eveniment != NULL)
			delete[] e.nume_eveniment;
		e.nume_eveniment = new char[strlen(buffer) + 1];
		strcpy(e.nume_eveniment, buffer);
		cout << "\n";
		while (ok == 0)
		{
			cout << "Data: ";
			cout << "zi: ";
			in >> e.data.zi;
			cout << "luna: ";
			in >> e.data.luna;
			cout << "an: ";
			in>> e.data.an;
			cout << "\n";
			cout << "Ora: ";
			in >> e.t.ora;
			cout << "Minut: ";
			in>> e.t.minut;
			cout << "\n";
			if (e.VerificaOra()==1 && e.VerificaData()==1)
			{
				ok = 1;
			}
			else
			{
				cout << "Data sau ora introdusa nu este valida " << endl;
				cout << "Introduceti din nou data si ora " << endl;
			}
		}
		return in;
	}
	friend Eveniment operator--(Eveniment& e)
	{
		e.data.zi--;
		if (e.data.zi == 0)
		{
			e.data.luna--;
			if (e.data.luna == 0)
			{
				e.data.luna = 12;
				e.data.an--;
			}
			else
				e.data.zi = e.lunile_anului[e.data.luna - 1];
		}
	}
	friend Eveniment operator--(Eveniment& e, int)
	{
		Eveniment copie = e;
		e.data.zi--;
		if (e.data.zi == 0)
		{
			e.data.luna--;
			if (e.data.luna == 0)
			{
				e.data.luna = 12;
				e.data.an--;
			}
			else
				e.data.zi = e.lunile_anului[e.data.luna - 1];
		}
		return copie;
	}
	friend Eveniment operator+=(Eveniment& e, int x)
	{
		e.data.zi += x;
		if (e.data.zi > e.lunile_anului[e.data.luna - 1])
		{
			e.data.luna++;
			e.data.zi = e.data.zi - e.lunile_anului[e.data.luna - 1];
			if (e.data.luna > 12)
			{
				e.data.luna = 1;
				e.data.an++;
			}
		}
		return e;
	}

	virtual void SeteazaDataInceputAn()
	{
		this->data.zi = 1;
		this->data.luna = 1;
		this->data.an = this->data.an+1;
	}

};
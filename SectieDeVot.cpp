#include<iostream>
using namespace std;

class SectieVot 
{
	int const NR_SECTIE;
	char*locatie;
	int numar_alegatori;
	int numar_votanti_liste;
	int numar_votanti_suplimentari;
	int static NR_MAXIM_VOTANTI;



public:
	SectieVot():NR_SECTIE(0)
	{
		locatie = new char[strlen("na")+1];
		strcpy(locatie, "na");
		numar_alegatori = 0;
		numar_votanti_liste = 0;
		numar_votanti_suplimentari = 0;
		
    }



	int getnrAlegatori() 
	{
		return numar_alegatori;
	}
	int getnrVotantiSuplimentari() 
	{
		return numar_votanti_suplimentari;
	}



	SectieVot(  const char*loc, int nrA, int nrVL, int nrVS) :NR_SECTIE(0)
	{
		locatie = new char[strlen(loc) + 1];
		strcpy(locatie, loc);
		numar_alegatori = nrA;
		numar_votanti_liste = nrVL;
		numar_votanti_suplimentari = nrVS;

	}


	~SectieVot() {
		if (locatie) {
			delete[]locatie;
		}
	}

	void setLocatie(const char*locatieNoua) 
	{
		if (locatieNoua != NULL) 
		 {
			if (locatie) {
				delete[]locatie;
			}
			locatie = new char[strlen(locatieNoua) + 1];
			strcpy(locatie, locatieNoua);

        }
		else {
			throw"Eroare sectie de vot";

		}

	}


	SectieVot(const SectieVot & s) :NR_SECTIE(s.NR_SECTIE)
	{
		locatie = new char[strlen(s.locatie) + 1];
		strcpy(locatie, s.locatie);
		numar_alegatori = s.numar_alegatori;
		numar_votanti_liste = s.numar_votanti_liste;
		numar_votanti_suplimentari = s.numar_votanti_suplimentari;

	}
	//pct 7
	SectieVot &operator=(const SectieVot & s) 
	{
		if (locatie) {
			delete[]locatie;
		}
		locatie = new char[strlen(s.locatie) + 1];
		strcpy(locatie, s.locatie);
		numar_alegatori = s.numar_alegatori;
		numar_votanti_liste = s.numar_votanti_liste;
		numar_votanti_suplimentari = s.numar_votanti_suplimentari;
		return *this;
	}


	//pct 8
	friend ostream& operator<<(ostream &out, SectieVot &s)
	{
		out << s.locatie << " " << s.numar_alegatori << " " << s.numar_votanti_liste << " " << s.numar_votanti_suplimentari << endl;
		return out;
	
	}

	friend istream& operator>>(istream &in, SectieVot &s)
	{
		cout << "Da locatie:";
		in >> s.locatie;
		cout << " Da numar alegatori:";
		in >> s.numar_alegatori;
		cout << " Da numar votanti liste:";
		in >> s.numar_votanti_liste;
		cout << " Da numar votanti liste suplimentare:";
		in >> s.numar_votanti_suplimentari;


		return in;

	}

	//cast pct 10
	explicit operator int()
	{
		return numar_alegatori;
	}


	//punctul 9
	bool operator>(const SectieVot& s) 
	{
		return numar_alegatori > s.numar_alegatori;
	}
	bool operator<(const SectieVot& s) 
	{
		return numar_alegatori < s.numar_alegatori;
    }



};

int SectieVot::NR_MAXIM_VOTANTI = 100;











void main()
{
	SectieVot s1;
	s1.getnrAlegatori();
	s1.getnrVotantiSuplimentari();
	cout << s1.getnrAlegatori();
	 SectieVot s2("Bucuresti", 5, 3, 2);
	 s2.setLocatie("Buzau");
	 SectieVot s3 = s2;
	 s3 = s2;
	 cout << s2;
	 cin >> s2;
	 int nr_aleg = (int)s1;//cast pct 10
	 if (s1 > s2)//pct 9 operator >< comparare
	 {
		 cout << "s1 este mai mare ca s2" << endl;
	 }
	 else 
	 {
		 cout << "s1 este mai mic sau  egal ca s2" << endl;
	 }
	 if (s1 < s2) {
		 cout << "s1 este mai mic ca s2" << endl;

	 }
	 else {
		 cout << "si este mai mare sau egal cu s2" << endl;
	 }

};
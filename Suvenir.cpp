#include <iostream>
using namespace std;



class Suvenir {
public:
	int const COD;
private:
	char* locatie;
	float greutate;
	bool esteMagnet;
	int latime;

	static int GREUTATE_MAXIMA;


public:

	friend ostream& operator<<(ostream& o, Suvenir & s) {

		o << s.locatie << " " << s.greutate << " " << s.esteMagnet << " " << s.latime << endl;
		return o;

	}

	void setLocatie(const char* locatieNoua) {
		if (locatieNoua != NULL) {
			if (locatie) {
				delete[] locatie;
			}
			locatie = new char[strlen(locatieNoua) + 1];
			strcpy(locatie, locatieNoua);
		}
		else {
			throw "Eroare suvenir";
		}
	}

	const char* getLocatie() {
		return locatie;
	}

	int getLatime() {
		return latime;
	}
	float getGreutate() {
		return greutate;
	}

	Suvenir() :COD(0) {
		locatie = new char[strlen("na") + 1];
		strcpy(locatie, "na");
		greutate = 0;
		esteMagnet = 0;
		latime = 0;
	}

	Suvenir(const char*Locatie, float greutate, int latime) :COD(0) {
		
			this->greutate = greutate;
		
		
			locatie = new char[strlen(Locatie) + 1];
			strcpy(locatie, Locatie);
		
		this->latime = latime;
	}




	Suvenir(const Suvenir& s) :COD(s.COD) {
		if (s.greutate > 0 && GREUTATE_MAXIMA >= s.greutate) {
			this->greutate = s.greutate;
		}
		else {
			throw "Eroare suvenir";
		}
		if (s.locatie != NULL) {
			locatie = new char[strlen(s.locatie) + 1];
			strcpy(locatie, s.locatie);
		}
		else {
			locatie = new char[strlen("na") + 1];
			strcpy(locatie, "na");
		}
		this->latime = s.latime;
		esteMagnet = s.esteMagnet;
	}
	~Suvenir() {
		if (locatie) {
			delete[] locatie;
		}
	}
	explicit operator int() {
		return latime;
	}
	bool operator >(const  Suvenir& s) {
		return greutate > s.greutate;
	}

	bool operator <(const  Suvenir& s) {
		return greutate < s.greutate;
	}

	Suvenir& operator =(const Suvenir& s) {
		if (locatie) {
			delete[] locatie;
		}


		if (s.greutate > 0 && GREUTATE_MAXIMA >= s.greutate) {
			this->greutate = s.greutate;
		}
		else {
			throw "Eroare suvenir";
		}
		if (s.locatie != NULL) {
			locatie = new char[strlen(s.locatie) + 1];
			strcpy(locatie, s.locatie);
		}
		else {
			locatie = new char[strlen("na") + 1];
			strcpy(locatie, "na");
		}
		this->latime = s.latime;
		esteMagnet = s.esteMagnet;
		return*this;
	}


};

int Suvenir::GREUTATE_MAXIMA = 1000;










void main() {

	Suvenir s;
	Suvenir s1("Balea lac", 200, 200);
	Suvenir s2(s1);
	s = s1;
	s1.setLocatie("Castelul Peles");
	if (s1 > s2) {
		cout << "S1 este mai mare" << endl;
	}
	else {//return false sunt egale...
		cout << " s1 este mai mic sau egal" << endl;
	}

	if (s1 < s2) {
		cout << "S1 este mai mic mare" << endl;
	}
	else {//return false sunt egale...
		cout << " s1 este mai mare sau egal" << endl;
	}
	int lat = (int)s1;
	cout << s1.getGreutate() << endl;
	cout << s1.getLatime() << endl;
	cout << s1.getLocatie() << endl;
	cout << lat;
	cout << s;

}
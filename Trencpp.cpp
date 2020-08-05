#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class Tren {

	//punctul 1
	const int nrTren;
	string numeVatman;
	int nrStatii;
	int*minStatie;
public:
	Tren() :nrTren(0)
	{
		numeVatman = "na";
		nrStatii = 0;
		minStatie = NULL;

	}
	//punctul 2
	Tren(string nuV) :nrTren(1)
	{
		numeVatman = nuV;
		nrStatii = 0;
		minStatie = NULL;

	}
	Tren(string nuV, int nrS, int*minS) :nrTren(1)
	{
		numeVatman = nuV;
		nrStatii = nrS;
		minStatie = new int[nrS];
		for (int i = 0; i < nrS; i++) {
			minStatie[i] = minS[i];

		}

	}

	//punctul 3
	Tren(const Tren & s) :nrTren(s.nrTren)
	{
		if (numeVatman.length() > 2)
		{
			numeVatman = s.numeVatman;
		}
		nrStatii = s.nrStatii;
		minStatie = new int[s.nrStatii];
		for (int i = 0; i < s.nrStatii; i++) {
			minStatie[i] = s.minStatie[i];

		}

	}


	~Tren() {
		if (minStatie)
		{
			delete[]minStatie;

		}


	}


	Tren & operator=(const Tren & s)
	{
		if (minStatie)
		{
			delete[]minStatie;

		}
		if (numeVatman.length() > 2) {
			numeVatman = s.numeVatman;
		}
		nrStatii = s.nrStatii;
		minStatie = new int[s.nrStatii];
		for (int i = 0; i < s.nrStatii; i++) {
			minStatie[i] = s.minStatie[i];

		}
		return*this;
	}

	//punctul 4
	//t2.calculMinuteStationate(1,2);

	int calculMinuteStationate(int indexStart, int indexEnd) {
		int sumaDurate = 0;
		for (int i = 0; i < nrStatii; i++) {
			if (i > indexStart&&i < indexEnd) {
				sumaDurate += minStatie[i];
			}
		}
		return sumaDurate;
	}
	//total minute stationate
	int totalMinuteStationate() {
		int sumaDurate = 0;
		for (int i = 0; i < nrStatii; i++) {
			sumaDurate += minStatie[i];
		}
		return sumaDurate;
	}
	//adauga statie
	void adaugaStatie(int durataNoua) {
		int* vectorDurate = new int[nrStatii + 1];
		for (int i = 0; i < nrStatii; i++) {
			vectorDurate[i] = minStatie[i];
		}
		vectorDurate[nrStatii] = durataNoua;
		if (minStatie) {
			delete[]minStatie;
		}
		minStatie = vectorDurate;
		nrStatii++;
	}


	//punctul 5
	friend ostream & operator<<(ostream & out, const Tren & s)
	{
		out << s.nrTren << " " << s.numeVatman << s.nrStatii;
		for (int i = 0; i < s.nrStatii; i++) {
			out << s.minStatie[i];

		}
		return out;


	}

	int & operator[](int index)
	{
		if (index >= 0 && nrStatii <= index)
		{
			return minStatie[index];

		}
		else
		{
			throw new  exception;
		}

	}



	//punctul 6

	friend ofstream & operator<<(ofstream & out, const Tren & s)
	{
		out << s.nrTren << " " << s.numeVatman << s.nrStatii;
		for (int i = 0; i < s.nrStatii; i++) {
			out << s.minStatie[i];

		}
		return out;


	}

	friend ifstream & operator>>(ifstream & in, const Tren & s)
	{
		if (s.minStatie) {
			delete[]s.minStatie;
		}
		in >> s.numeVatman;
		in >> s.nrStatii;
		s.minStatie = new int[s.nrStatii];
		for (int i = 0; i < s.nrStatii; i++) {
			in >> s.minStatie[i];
		}
		return in;
	}





	//pct 7
	virtual void afisareVirtualizare() {
		cout << "nr tren" << nrTren;
	}


};
//puctul 7
class TrenHibrid :public Tren {
	int capacitBaterie;
	int timpIncarcare;
public:

	TrenHibrid() :Tren("na", 2, NULL) {
		capacitBaterie = 0;
		timpIncarcare = 0;
	}

	TrenHibrid(string numV, int nrSt, int*minS, int capB, int timpI) :Tren(numV, nrSt, minS)
	{
		if (capB >= 0 && capB<=100) 
		{
			capacitBaterie = capB;
        }
		if (timpI > 0) {
			timpIncarcare = timpI;
		}


	}


	TrenHibrid(const TrenHibrid & s) :Tren()
	{
		capacitBaterie = s.capacitBaterie;
		timpIncarcare = s.timpIncarcare;




	}

	TrenHibrid & operator=(const TrenHibrid & s) 
	{
		Tren::operator=(s);
		capacitBaterie = s.capacitBaterie;
		timpIncarcare = s.timpIncarcare;


		return *this;

	}

	virtual void afisareVirtualizare() {
		cout << "Capacitate baterie" << capacitBaterie;
		cout << "timp incarcare" << timpIncarcare;
	}


};










void main() 
{
	Tren();
	Tren t1("ion");
	int vect[2] = { 15,5 };
	Tren t2("Vasile", 2, vect);
	Tren t3 = t2;
	t3 = t2;
	t3.adaugaStatie(3);
	t3.totalMinuteStationate();
	t3.calculMinuteStationate(2, 8);
	cout << t3;
	cout << t2[1];
	//pct 6
	ofstream fout1;
	fout1.open("t2.tex", ofstream::out);
	if (fout1.is_open()) {
		fout1 << t2;
		fout1.close();
	}

	ifstream fin1;
	fin1.open("t2.text", ifstream::in);
	if (fin1.is_open()) {
		fin1>>t2;
		fin1.close();
	}


	TrenHibrid();
	TrenHibrid h1("Vasile", 2, vect, 15, 20);
	TrenHibrid h2;
	TrenHibrid h3 = h1;
	h2 = h1;
	Tren*trenuri[2] = { &t1,&t2 };//pct 7
	for (int i = 0; i < 2; i++) {
		trenuri[i]->afisareVirtualizare();
	}

}

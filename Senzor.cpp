#include<iostream>
using namespace std;

class SenzorTemperatura {
	int const nrSenzor;
	char* locatie;
	int altitudine;
	int nrInregistrari;
	int*frecventa;
	float static TEMPERATURA_MINIMA;
	int static nrObiecte;
public:


	SenzorTemperatura():nrSenzor (nrObiecte++)
	{
		locatie = new char[strlen("na") + 1];
		strcpy(locatie, "na");
		altitudine = 0;
		nrInregistrari = 0;
		frecventa = NULL;

    }



	SenzorTemperatura( const char*loc,int alt, int nrI, int*frec) :nrSenzor(nrObiecte++)
	{
		locatie = new char[strlen(loc) + 1];
		strcpy(locatie, loc);
		altitudine = alt;
		nrInregistrari = nrI;
		frecventa = new int[nrI];
		for (int i = 0; i < nrI; i++) 
		{
			frecventa[i] = frec[i];

		}


    }

	SenzorTemperatura(int nrInregistrari, int*frecventa) :nrSenzor(nrObiecte++)
	{
		this->nrInregistrari = nrInregistrari;
		this->frecventa = new int[nrInregistrari];
		for (int i = 0; i < nrInregistrari; i++)
		{
			this->frecventa[i] = frecventa[i];

		}
		locatie = new char[strlen("na") + 1];
		strcpy(locatie, "na");
		altitudine = 0;
	}



	int getnrInregistrari() 
	{
		return nrInregistrari;
	}


	char*getlocatie()
	{
		return locatie;
	}
	int getAltitudine() 
	{
		return altitudine;

	}



	~SenzorTemperatura()
	{
		if (locatie)
		{
			delete[] locatie;
		}
		if (frecventa) {
			delete[]
				frecventa;
		}
		nrObiecte--;
	}



	//SenzorTemperatura s3 = s2;
	SenzorTemperatura(const SenzorTemperatura & s) :nrSenzor(nrObiecte++)
	{
		locatie = new char[strlen(s.locatie) + 1];
		strcpy(locatie, s.locatie);
		altitudine =s.altitudine;
		nrInregistrari = s.nrInregistrari;
		frecventa = new int[s.nrInregistrari];
		for (int i = 0; i <s.nrInregistrari; i++)
		{
			frecventa[i] = s.frecventa[i];

		}


	}




	friend ostream & operator<<(ostream& out,  const SenzorTemperatura& s)
	{
		out << s.altitudine << " " << s.locatie << " " << s.nrInregistrari << " ";
		s.frecventa = new int[s.nrInregistrari];
		for (int i = 0; i < s.nrInregistrari; i++)
		{
			 s.frecventa[i];

		}




			return out;
	}


	SenzorTemperatura & operator=(const SenzorTemperatura & s)
	{
		if (locatie)
		{
			delete[] locatie;
		}
		if (frecventa) {
			delete[]
				frecventa;
		}

		locatie = new char[strlen(s.locatie) + 1];
		strcpy(locatie, s.locatie);
		altitudine = s.altitudine;
		nrInregistrari = s.nrInregistrari;
		frecventa = new int[s.nrInregistrari];
		for (int i = 0; i < s.nrInregistrari; i++)
		{
			frecventa[i] = s.frecventa[i];

		}
		return *this;


    }





	static void setTemperatura(int Temperatura) {
		if (Temperatura > 60) {
			TEMPERATURA_MINIMA = Temperatura;
		}

	}

	//s2.locatie
	void setLocatieNoua( const char* LocatieNoua) {
		if(strlen(LocatieNoua)>2)
		{
			if (locatie) {
				delete[]locatie;

			}
			locatie = new char[strlen(LocatieNoua) + 1];
			strcpy(locatie, LocatieNoua);

		
		
		}
		
	}


	void setFrecventaNoua(int nrI, int*Frecv) 
	{
		if (nrI > 0) 
		{
			if (frecventa)
			{
				delete[]frecventa;

			}

			frecventa = new int[nrI];
			for (int i = 0; i < nrI; i++)
			{
				frecventa[i] = Frecv[i];
			}
	    }

		

	}
		

	

		
	


};

float SenzorTemperatura::TEMPERATURA_MINIMA = -50.0;
int SenzorTemperatura::nrObiecte = 0;

















 void main()
 {
	 SenzorTemperatura s1;
	 int  vect[] = { 23, 25, 89 };
	 SenzorTemperatura s2("Bucuresti", 1300, 3, vect);
	 s2.getAltitudine();
	 s2.getlocatie();
	 s2.getnrInregistrari();
	 SenzorTemperatura s3 = s2;
	 s3 = s2;
	 int vect2[] = { 25,89,78,65 };
	 SenzorTemperatura s4(4, vect2);
	 SenzorTemperatura::setTemperatura(80);
	 s3.setLocatieNoua("Buzau");
	int vect3[2] = { 26, 65 };//jj
    //s3.setFrecventaNoua(2,vect3);
	cout << s3;
 };
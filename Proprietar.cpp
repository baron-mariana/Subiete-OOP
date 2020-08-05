#include<iostream>
#include<string>
using namespace std;

class Proprietar {

	char* nume;
	string cnp;
	int nrApartamente;//e o val ce gestioneaza vect dinic de pointerul chirii
	float* chirii;//pointer ce gestioneaza adresa unui vect dinamic de val
	const int id;
	static float tva;
public:



	Proprietar() :id(0) {
		this->cnp = "na";
		this->nrApartamente = 0;
		this->chirii = NULL;
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");

	}
	Proprietar(int idd, const char* nume, string cnp, int nrAp, float* chirii) :id(idd) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->cnp = cnp;
		this->nrApartamente = nrAp;
		this->chirii = new float[nrAp];
		for (int i = 0; i < nrAp; i++)
		{
			this->chirii[i] = chirii[i];
		}
	}

	//const char* nume, si string cnp
	Proprietar(const char* nume, string cnp) :id(0) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->cnp = cnp;
		this->nrApartamente = 0;
		this->chirii = NULL;

	}
	Proprietar(const Proprietar&sursa) :id(sursa.id) {
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->cnp = sursa.cnp;
		this->nrApartamente = sursa.nrApartamente;
		this->chirii = new float[sursa.nrApartamente];
		for (int i = 0; i < sursa.nrApartamente; i++)
		{
			this->chirii[i] = sursa.chirii[i];
		}
	}
	~Proprietar() {
		if (this->nume) {
			delete[]this->nume;
		}
		if (this->chirii) {
			delete[]this->chirii;
		}
	}


	//p2=p1=p5=p6
	Proprietar&operator=(const Proprietar& sursa) {
		if (this->nume) {
			delete[]this->nume;
		}
		if (this->chirii) {
			delete[]this->chirii;
		}
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->cnp = sursa.cnp;
		this->nrApartamente = sursa.nrApartamente;
		this->chirii = new float[sursa.nrApartamente];
		for (int i = 0; i < sursa.nrApartamente; i++)
		{
			this->chirii[i] = sursa.chirii[i];

		}

		return*this;
	}
	//s3.set(dxf)
	void setnume(const char* numeNou) {
		if (strlen(numeNou) > 2) {
			if (this->nume) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}

	}
	void setcnp(string cnpNou) {
		if (cnpNou.length() > 2) {
			this->cnp = cnpNou;
		}
	}

	void setchirii(int nrap, float*chiriiNoi) {
		if (nrap > 0) {
			if (this->chirii) {
				delete[]this->chirii;
			}
			this->nrApartamente = nrap;
			this->chirii = new float[nrap];
			for (int i = 0; i < nrap; i++) {
				this->chirii[i] = chiriiNoi[i];
			}
		}

	}

	//afisez chiria pt p2
	float* getchirie() {
		return this->chirii;
	}

	int getnrApartamente() {
		return this->nrApartamente;
	}



	//cout<<s3<<s2;
	friend ostream& operator<<(ostream& o, const Proprietar& sursa) {
		o << "NUME:" << sursa.nume << endl;
		o << "CNP:" << sursa.cnp << endl;
		o << "NR APARTAMENTE:" << sursa.nrApartamente << endl;

		for (int i = 0; i < sursa.nrApartamente; i++) {
			o << sursa.chirii[i] << " ";
		}
		return o;
	}

	//cin>>s2>>s3;
	friend istream& operator>> (istream& in, Proprietar& sursa) {
		cout << "Da nume: ";
		char buffer[100];
		in >> buffer;
		sursa.setnume(buffer);

		cout << "Da cnp:";
		in >> sursa.cnp;

		cout << "Da numarul de aprtamente ";
		in >> sursa.nrApartamente;

		if (sursa.chirii) {
			delete[]sursa.chirii;
		}
		sursa.chirii = new float[sursa.nrApartamente];
		for (int i = 0; i < sursa.nrApartamente; i++) {
			cout << "Da chiria pentru ap " << i + 1 << ": ";
			in >> sursa.chirii[i];
		}



		return in;
	}



	//  p1 +=1200; 


	//p1
	// Gabriel
	// 2 
	// 340   380  -->> 440    480 

	// p1+=100; 

	// p1.marireChirii(100.00);
	void marireChirii(float marirre)
	{
		for (int i = 0; i < this->nrApartamente; i++) {
		//	this->chirii[i] = this->chirii[i] + marirre;
			this->chirii[i] += marirre; 
		}
	}

	// operatori aritmetici unari +=  -=   /=  *= 
	//tipul returnat: va fi intotdeauna o referinta a obiectului pentru care s a apelat functia 
	// nu mele   operatorului  operator += / operator -= etdc...
	//lista de parametrii: PRIMESTE doar 2 Parametri! ... Obiectul pentru care s a apelat functia ... si inca o referinta sau pointer sau valoarea la orice tip de data 
	// in corpul functiei ... lucram pe this 

	// p1+=120;
	Proprietar& operator+=(float marirre) {
		for (int i = 0; i < this->nrApartamente; i++) {
			//	this->chirii[i] = this->chirii[i] + marirre;
			this->chirii[i] += marirre;
		}
	//	cout << *this;// ti l afisaeaza pe p1 ... cout<<p1;
		return *this;
	}


// operatori aritmetici binari +    -    /    * 
//tipul returnat: va fi intotdeauna o COPIE  a obiectului pentru care s a apelat functia 
// nu mele   operatorului  operator + / operator - etdc...
//lista de parametrii: PRIMESTE doar 2 Parametri! ... Obiectul pentru care s a apelat functia ... si inca o referinta sau pointer sau valoarea la orice tip de data 
// in corpul functiei ... Primul lucru pe care il facem este sa copiem obiectul din this 
	//Apoi lucram pe acea copie... modificam pe ea .... Originalul il pstram intact 
	//la  final returnam copia;

	// p1+23;
	//Proprietar operator + (float marire) {
	//	Proprietar copie = *this;  // Proprietar copie(p1); //apel cosntructor copiere
	//	for (int i = 0; i < copie.nrApartamente; i++) {
	//		//	this->chirii[i] = this->chirii[i] + marirre;
	//		copie.chirii[i] +=  marire;
	//	}
	//	return copie;
	//}


Proprietar operator+( float chirieNoua) {
		Proprietar copie = *this;
		float*vn = new float[copie.nrApartamente + 1];
		for (int i = 0; i < copie.nrApartamente; i++) {
			vn[i] = copie.chirii[i];
		}
			
			vn[copie.nrApartamente] = chirieNoua;
			copie.nrApartamente++;
			if (copie.chirii) {
				delete[]copie.chirii;
			}
			copie.chirii = vn;
		
		return copie;
	}



	// operator++ -- forma  PRE  - incrementare decremendate
	//tipul returnat: va fi intotdeauna o referinta a obiectului pentru care s a apelat functia 
	// nu mele   operatorului  operator ++ / operator -- etdc...
	//lista de parametrii: PRIMESTE doar 1 Parametru!
	// in corpul functiei ... lucram pe this ... si modificam this cu valoare implicita 
	//la final *this;
	// ++p1;
	Proprietar& operator++() {
		for (int i = 0; i < this->nrApartamente; i++) {
				this->chirii[i] = this->chirii[i] + 10;
			//this->chirii[i] += 10;
		}

		return *this;
	}


	// operator++ -- forma  post  - incrementare decremendate
//tipul returnat: va fi intotdeauna o Copie a obiectului pentru care s a apelat functia 
// nu mele   operatorului  operator ++ / operator -- etdc...
//lista de parametrii: PRIMESTE doar 1 Parametru!  si cuvantul INT in lista .. pentru a se face diferentierea intre pre si post 
// in corpul functiei    Mai intai facem o copie a lui this  apoi   ... lucram pe this ... si modificam this cu valoare implicita 
//obs: NU AVEM VOIE sa modificam copia... deoarece ea  a fost facuta la inceput si retine valorile initiale a lui this 
// returnam copia  cu valorile initiale a lui this 

	Proprietar operator++(int) {
		Proprietar copie = *this;
		for (int i = 0; i < this->nrApartamente; i++) {
			this->chirii[i] = this->chirii[i] + 10;
			//this->chirii[i] += 10;
		}
		return copie;
	}


	



// operatori relationali / de comparatie  >  <  >=   <=  ==   !=     
//tipul returnat: va fi intotdeauna un BOOL
// nu mele   operatorului  operator > / operator < etdc...
	//lista de parametrii: PRIMESTE doar 2 Parametri! ... Obiectul pentru care s a apelat functia ... si inca o referinta sau pointer sau valoarea la orice tip de data 

// in corpul functiei    Mai intai facem o copie a lui this  apoi   ... lucram pe this ... si modificam this cu valoare implicita 
//obs: NU AVEM VOIE sa modificam copia... deoarece ea  a fost facuta la inceput si retine valorile initiale a lui this 
// returnam copia  cu valorile initiale a lui this 
	//  p2==p3 p2>=12   p2<vect;  p1 != "Gabriel"  etc.. 
	
	// getTotalChirii
	float getTotalChirii() {
		float s = 0;
		for (int i = 0; i < nrApartamente; i++) {
			s += chirii[i];
		}
		return s;
	}

	float operator ()() {
		float s = 0;
		for (int i = 0; i < nrApartamente; i++) {
			s += chirii[i];
		}
		return s;
	}

	bool operator == (Proprietar sursa) {  // copie a unui proprietar
		if (this->getTotalChirii() == sursa.getTotalChirii()) {
			return 1;
		}
		else {
			return 0;
		}


	}

	// operatorul not!  
	bool operator!() {
		if (nrApartamente > 0) {
			return false;
		}
		else {
			return true;
		}
	}



	//Protrietar& operator!() {
	//	if (protectieProprietar == 0) {
	//		pritectieProprietar= true;
	//	}
	//	else {
	//		pritectieProprietar= false;
	//	}

	/// return * this;
	//}



	//operator int() {
	//	return nrApartamente;
	//}

	explicit operator int() {
		return nrApartamente;
	}

	explicit operator float() {
		return getTotalChirii();
	}


	float&  operator[] (int i) {
		if (i >= 0 && i < nrApartamente) {
			return  chirii [i];
		}
		else {
			throw new exception();
		}
	}

	float&  operator() (int i) {
		if (i >= 0 && i < nrApartamente) {
			return  chirii[i];
		}
		else {
			throw new exception();
		}
	}





};
float Proprietar::tva = 0.19;


void main() {
	Proprietar p;
	float vect[] = { 200,300,400 };
	Proprietar p2(123, "Popescu", "sfg", 3, vect);
	Proprietar p3("p2", "gfsh");
	Proprietar p4(p2);
	p4 = p2;
	p2.setnume("ionescu");
	p2.setcnp("cdh");
	float chirii[] = { 200,300 };
	p2.setchirii(2, chirii);
	//cout << p2.getchirie();
	for (int i = 0; i < p2.getnrApartamente(); i++) {
		//	cout << p2.getchirie()[i]<<endl;
	}
	//cout << p2;

	if (p2 == p4) {
	//	cout << "Sunt egali=" << endl;
	}
	else {
	//	cout << "nu sunt egali" << endl;
	}

	if (!p2) {
		cout << "Are  apartamente" << endl;
	}
	else {
		cout << "N are apartamente" << endl;
	}

	// !p2;
	p2 + 12;
	p2 += 12;
	//int apartamenteP2 =p2; //implicit ... atunci cand compilatorul isi da seama singur la ce sa se faca cast 
	// de evenitat sa folosim castul implicit ca intra in ambiguitate cu alti operatori ;
	int apartamenteP2 = (int)p2;//explicit 
	float sum = (float)p2;
	//cout << sum << endl;
//	p2[1] = 12312;
	cout << p2();
	//cout << p2[1];
}
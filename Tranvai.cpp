#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Tramvai{
	const int nrTramvai;
	string numeVatman;
	int nrStatii;
	int* minuteStatie;
public:
	Tramvai():nrTramvai(0){
		this->numeVatman = "na";
		this->nrStatii = 0;
		this->minuteStatie = NULL;
	}

	Tramvai(string numeVatman ) :nrTramvai(1){
		if (numeVatman.length() > 2){
			this->numeVatman = numeVatman;
		}
		this->nrStatii = 0;
		this->minuteStatie = NULL;
	}

	//facem un constructor cu toti parametri pentru a implementa operatorul []
	Tramvai(string numeVatman, int nrStatii, int* minuteStatie) :nrTramvai(1){
		if (numeVatman.length() > 2){
			this->numeVatman = numeVatman;
		}
		if (nrStatii >=0){
			this->nrStatii = nrStatii;
			this->minuteStatie = new int[nrStatii];
			for (int i = 0; i<nrStatii; i++){
				this->minuteStatie[i] = minuteStatie[i];
			}
		}

	}

	Tramvai(const Tramvai& sursa) :nrTramvai(1){
		if (numeVatman.length() > 2){
			this->numeVatman = numeVatman;
		}
		this->nrStatii = sursa.nrStatii;
		this->minuteStatie = new int[nrStatii];
		for (int i = 0; i < nrStatii; i++){
			this->minuteStatie[i] = sursa.minuteStatie[i];
		}
	}

	Tramvai& operator=(const Tramvai& sursa){
		if (minuteStatie){
			delete[]minuteStatie;
		}
		if (numeVatman.length() > 2){
			this->numeVatman = numeVatman;
		}
		this->nrStatii = sursa.nrStatii;
		this->minuteStatie = new int[nrStatii];
		for (int i = 0; i < nrStatii; i++){
			this->minuteStatie[i] = sursa.minuteStatie[i];
		}
		return*this;
	}

	friend ostream& operator<<(ostream& out, const Tramvai& sursa){
		out << "Numar tramvai: " << sursa.nrTramvai << endl;
		out << "Nume: " << sursa.numeVatman << endl;
		out << "Nr statii: " << sursa.nrStatii << endl;
		for (int i = 0; i < sursa.nrStatii; i++){
			out << "Statia " << i + 1 << " " << sursa.minuteStatie[i] << endl;
		}
		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Tramvai& sursa){
		out << "Numar tramvai: " << sursa.nrTramvai << endl;
		out << "Nume: " << sursa.numeVatman << endl;
		out << "Nr statii: " << sursa.nrStatii << endl;
		for (int i = 0; i < sursa.nrStatii; i++){
			out << "Statia " << i + 1 << " " << sursa.minuteStatie[i] << endl;
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Tramvai& sursa){
		if (sursa.minuteStatie){
			delete[]sursa.minuteStatie;
		}
		in >> sursa.numeVatman;
		in >> sursa.nrStatii;
		sursa.minuteStatie = new int[sursa.nrStatii];
		for (int i = 0; i < sursa.nrStatii; i++){
			in >> sursa.minuteStatie[i];
		}
		return in;
	}

	int& operator[](int index){   //& permite modificarea
		if (index >= 0 && index <= nrStatii){
			return minuteStatie[index];
		}
		else{
			throw new exception;
		}
	}
	virtual void afisareVirtuala(){
		cout << "Tramvaiul " << nrTramvai << " este functional" << endl;
	}

	int totalMinuteStationate(){
			int sumaDurate = 0;
			for (int i = 0; i < nrStatii; i++){
				sumaDurate += minuteStatie[i];
			}
			return sumaDurate;
	}

	void adaugaStatie(int durataNoua){
		int* vectorDurate = new int[nrStatii + 1];
		for (int i = 0; i < nrStatii; i++){
			vectorDurate[i] = minuteStatie[i];
		}
		vectorDurate[nrStatii] = durataNoua;
		if (minuteStatie){
			delete[]minuteStatie;
		}
		minuteStatie = vectorDurate;
		nrStatii++;
	}

	

	
};

class TramvaiHibrid :public Tramvai{
	int capacitateBaterie;
	int timpIncarcare;
public:
	TramvaiHibrid():Tramvai("na",0,NULL){
		this->capacitateBaterie = 0;
		this->timpIncarcare = 0;
	}

	TramvaiHibrid(string numeVatman, int nrStatii, int* minuteStatie,
		int capacitateBaterie, int timpIncarcare):Tramvai(numeVatman, nrStatii,minuteStatie){
		if (capacitateBaterie >= 0 && capacitateBaterie <= 100){
			this->capacitateBaterie = capacitateBaterie;
		}
		if (timpIncarcare > 0){
			this->timpIncarcare = timpIncarcare;
		}
	}

	TramvaiHibrid(const TramvaiHibrid& sursa):Tramvai(){   //apel constr copiere din prima cls
		this->capacitateBaterie = sursa.capacitateBaterie;
		this->timpIncarcare = sursa.capacitateBaterie;
	}

	TramvaiHibrid& operator=(const TramvaiHibrid& sursa){   //apel constr copiere din prima cls
		Tramvai::operator=(sursa);
		this->capacitateBaterie = sursa.capacitateBaterie;
		this->timpIncarcare = sursa.capacitateBaterie;
		return *this;
	}


	virtual void afisareVirtuala(){
		cout << "Si are o capacitate a bateriei de " << capacitateBaterie << " procente." << endl;
		cout << "Durata de incarcare a fost de " << timpIncarcare << " ore." << endl;
	}



};


void main(){
	Tramvai t1;
	int  durate[3] = { 3, 4, 2 };
	Tramvai t2("RATB",3,durate);

	//cout << t2;
    //cout<<t2[1];

	//totalMinuteStationate
	cout << t2.totalMinuteStationate ();

	//adauga statie
	t2.adaugaStatie(8);

	//calcul minute stationate intre statia/indexul  0 si 3 (4+2)
	//adica calculul minutelor stationate in indexul 1 si 2
	cout << t2.calculMinuteStationate(0, 3);





   ofstream fout1;
   fout1.open("t2.txt", ofstream::out);
   if (fout1.is_open()){
	   fout1<< t2;
	   fout1.close();
   }

   ifstream fin1;
   fin1.open("t2.txt", ifstream::in);
   if (fin1.is_open()){
	   fin1>> t2;
	   fin1.close();
   }

   ////////////HIBRID
   TramvaiHibrid th1 ("george", 3, durate, 30, 22);
   TramvaiHibrid th2;   //fara param
   Tramvai th3(th1);  //constr copiere
   th2 = th1;         //op egal

   //VIRTUALIZARE
   //facem un vector de pointeri la tramvaie/obiecte de tip TRamvai si TRamvaiHibrid
   Tramvai * tramvaie[2] = { &t1, &th1 }; 
   for (int i = 0; i < 2; i++){
	//   tramvaie[i]->afisareVirtuala();
   }



}
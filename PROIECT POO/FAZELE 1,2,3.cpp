//Domeniul Legumicultura

#include<iostream>
#include<string>


using namespace std;


enum localitate { Mandresti, Odobesti, Panciu, Marasesti };

string localitateString(localitate loc) {
	if (loc == Mandresti) {
		return "Mandresti";
	}
	if (loc == Odobesti) {
		return "Odobesti";
	}
	if (loc == Panciu) {
		return "Panciu";
	}
	if (loc == Marasesti) {
		return "Marasesti";
	}
}

class Sera {
private:
	const int anInfiintare;
	localitate loc;
	int nrSere;
	string* tipSera;
	float* temperatura;
	bool arePanouriFotovoltaice;
	static string judet;


public:
	Sera() :anInfiintare(1990) {
		this->loc = Mandresti;
		this->nrSere = 0;
		this->tipSera = NULL;
		this->temperatura = NULL;
		this->arePanouriFotovoltaice = false;
	}

	Sera(const int an, localitate loc, bool arePanouriFotovoltaice) : anInfiintare(an) {
		this->loc = loc;
		this->nrSere = nrSere;
		this->tipSera = NULL;
		this->temperatura = NULL;
		this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}

	Sera(const int an, localitate loc, int nrSere, string* tipSera, float* temperatura, bool arePanouriFotovoltaice) : anInfiintare(an) {
		this->loc = loc;
		this->nrSere = nrSere;
		if (nrSere > 0) {
			this->tipSera = new string[nrSere];
			this->temperatura = new float[nrSere];
			for (int i = 0; i < nrSere; i++) {
				this->tipSera[i] = tipSera[i];
				this->temperatura[i] = temperatura[i];
			}
		}
		else {
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
		this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}

	Sera(const Sera& sera) : anInfiintare(sera.anInfiintare) {
		this->loc = sera.loc;
		this->nrSere = sera.nrSere;
		if (sera.nrSere > 0) {
			this->tipSera = new string[sera.nrSere];
			this->temperatura = new float[sera.nrSere];
			for (int i = 0; i < nrSere; i++) {
				this->tipSera[i] = sera.tipSera[i];
			}
			for (int i = 0; i < nrSere; i++) {
				this->temperatura[i] = sera.temperatura[i];
			}
		}
		else {
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
		this->arePanouriFotovoltaice = sera.arePanouriFotovoltaice;
	}

	Sera& operator=(const Sera& sera) {
		if (this != &sera) {
			this->loc = sera.loc;
			if (sera.nrSere > 0) {
				this->nrSere = sera.nrSere;
				if (this->tipSera != NULL) 
				delete[]this->tipSera;
				if (this->temperatura != NULL) 
				delete[]this->temperatura;
			this->tipSera = new string[sera.nrSere];
			this->temperatura = new float[sera.nrSere];
			for (int i = 0; i < nrSere; i++) {
				this->tipSera[i] = sera.tipSera[i];
			}
			for (int i = 0; i < nrSere; i++) {
				this->temperatura[i] = sera.temperatura[i];
			}
		}
		else {
			this->nrSere = 0;
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
		this->arePanouriFotovoltaice = sera.arePanouriFotovoltaice;
	}
	return *this;
}

	~Sera() {
		if (this->tipSera != NULL) {
			delete[]this->tipSera;
		}
		if (this->temperatura != NULL) {
			delete[]this->temperatura;
		}
	}


	const int getAnInfiintare() {
		return this->anInfiintare;
	}


	localitate getLocalitate() {
		return this->loc;
	}

	void setLocalitate(localitate loc) {
			this->loc = loc;
	}


	int getNrSere() {
		return this->nrSere;
	}

	string* getTipSera() {
		return this->tipSera;
	}

	float* getTemperatura() {
		return this->temperatura;
	}


	void setSera(int nrSere, string* tipSera, float* temperatura) {
		if (nrSere > 0) {
			this->nrSere = nrSere;

			if (this->tipSera != NULL) {
				delete[]this->tipSera;
			}
			if (this->temperatura != NULL) {
				delete[]this->temperatura;
			}
			this->tipSera = new string[nrSere];
			this->temperatura = new float[nrSere];
			for (int i = 0; i < nrSere; i++) {
				this->tipSera[i] = tipSera[i];
				this->temperatura[i] = temperatura[i];
			}
		}
	}


	bool getArePanouriFotovoltaice() {
		return this->arePanouriFotovoltaice;
	}

	void setArePanouriFotovoltaice(bool arePanouriFotovoltaice) {
			this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}


	static string getJudet() {
		return Sera::judet;
	}

	static void setJudet(string judet) {
		Sera::judet = judet;
	}


	static float calculTemperaturaMedie(float* temperatura, int nrSere) {
		if (temperatura == NULL || nrSere<=0) {
			return 0;
		}
		float sumaTemperatura = 0;
		for (int i = 0; i < nrSere; i++) {
			sumaTemperatura = sumaTemperatura + temperatura[i];
		}
		return sumaTemperatura / nrSere;
	}

	pair<string, float> operator[] (int index) {
		if (index >= 0 && index < this->nrSere) {
			return { tipSera[index], temperatura[index] };
		}
	}

	void afisareSera() {
		cout << "An Infiintare: " << anInfiintare << ", Localitate: " << localitateString(loc) << ", Numar sere: " << nrSere <<", Are panouri fotovoltaice: "<<arePanouriFotovoltaice << endl;
		if (tipSera != NULL && temperatura != NULL) {
			for (int i = 0; i < nrSere; i++) {
				cout << "Tip sera " << i + 1 << ": " << tipSera[i] << endl;
			}
			for (int i = 0; i < nrSere; i++) {
				cout << "Temperatura " << i + 1 << ": " << temperatura[i] << endl;
			}
		}
		cout << endl;
	}

	friend istream& operator>>(istream& in, Sera& sera);

	friend ostream& operator<<(ostream& out, const Sera& sera);
};
string Sera::judet = "Vrancea";


istream& operator>>(istream& in, Sera& sera) 
{
	cout << "Localitate (0-Mandresti, 1-Odobesti, 2-Panciu, 3-Marasesti) :  ";
	int loc; 
	in >> loc;
	sera.setLocalitate(static_cast<localitate>(loc));
	cout << "\nNumar sere: ";
	in >> sera.nrSere;

	if (sera.tipSera != NULL) 
		delete[]sera.tipSera;
	if (sera.temperatura != NULL) 
		delete[]sera.temperatura;
	sera.tipSera = new string[sera.nrSere];
	sera.temperatura = new float[sera.nrSere];

	for (int i = 0; i < sera.nrSere; i++) 
	{
		cout << "\nTip sera " << i + 1 << ": ";
		in >> sera.tipSera[i]; 
	}
	for (int i = 0; i < sera.nrSere; i++) 
	{
		cout << "\nTemperatura " << i + 1 << ": ";
		in >> sera.temperatura[i]; 
	}
	cout << "\nAre panouri fotovoltaice (0-DA, 1-NU) : ";
	in >> sera.arePanouriFotovoltaice;
	return in;
}


ostream& operator<<(ostream& out, const Sera& sera) 
{
	out << "An Infiintare: " << sera.anInfiintare << ", Localitate: " << localitateString(sera.loc) << ", Numar sere: " << sera.nrSere << ", Are panouri fotovoltaice: " << sera.arePanouriFotovoltaice << endl;
	if (sera.tipSera != NULL && sera.temperatura != NULL) {
		for (int i = 0; i < sera.nrSere; i++) {
			out << "Tip sera " << i + 1 << ": " << sera.tipSera[i] << endl;
		}
		for (int i = 0; i < sera.nrSere; i++) {
			out << "Temperatura " << i + 1 << ": " << sera.temperatura[i] << endl;
		}
	}
	out << endl;
	return out;
}



class Fermier {

private:
	const int id;
	string nume;
	int varsta;
	int nrEchipamente;
	int* pretEchipament;
	static int nrFermieri;

public:
	Fermier() :id(nrFermieri++) {
		this->nume = "Anonim";
		this->varsta = NULL;
		this->nrEchipamente = NULL;
		this->pretEchipament = NULL;
	}

	Fermier(string nume, int varsta) :id(nrFermieri) {
		nrFermieri++;
		this->nume = nume;
		this->varsta = varsta;
		this->nrEchipamente = NULL;
		this->pretEchipament = NULL;
	}

	Fermier(string nume, int varsta, int nrEchipamente, int* pretEchipament) :id(nrFermieri) {
		nrFermieri++;
		this->nume = nume;
		this->varsta = varsta;
		this->nrEchipamente = nrEchipamente;
		if (nrEchipamente > 0) {
			this->pretEchipament = new int[nrEchipamente];
			for (int i = 0; i < nrEchipamente; i++) {
				this->pretEchipament[i] = pretEchipament[i];
			}
		}
		else this->pretEchipament = NULL;
	}

	Fermier(const Fermier& fermier) :id(nrFermieri++) {
		this->nume = fermier.nume;
		this->varsta = fermier.varsta;
		this->nrEchipamente = fermier.nrEchipamente;
		if (nrEchipamente > 0) {
			this->pretEchipament = new int[fermier.nrEchipamente];
			for (int i = 0; i < nrEchipamente; i++) {
				this->pretEchipament[i] = fermier.pretEchipament[i];
			}
		}
		else this->pretEchipament = NULL;
	}

	const Fermier& operator= (const Fermier& fermier) {
		if (this != &fermier) {
			if (this->pretEchipament != NULL) 
				delete[]this->pretEchipament;
			this->nume = fermier.nume;
			this->varsta = fermier.varsta;
			this->nrEchipamente = fermier.nrEchipamente;
			if (nrEchipamente > 0) {
				this->pretEchipament = new int[fermier.nrEchipamente];
				for (int i = 0; i < nrEchipamente; i++) {
					this->pretEchipament[i] = fermier.pretEchipament[i];
				}
			}
			else this->pretEchipament = NULL;
		}
		return *this;
	}

	~Fermier() {
		if (this->pretEchipament != NULL) {
			delete[]this->pretEchipament;
		}
	}


	const int getId() {
		return this->id;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int varsta) {
		if (varsta > 0) {
			this->varsta = varsta;
		}
	}


	int getNrEchipamente() {
		return this->nrEchipamente;
	}

	int* getPretEchipamente() {
		return this->pretEchipament;
	}

	void setEchipament(int nrEchipamente, int* pretEchipament) {
		if (nrEchipamente > 0) {
			this->nrEchipamente = nrEchipamente;

			if (this->pretEchipament != NULL) {
				delete[]this->pretEchipament;
			}
			this->pretEchipament = new int[nrEchipamente];
			for (int i = 0; i < nrEchipamente; i++) {
				this->pretEchipament[i] = pretEchipament[i];
			}
		}
	}

	static int getNrFermieri() {
		return Fermier::nrFermieri;
	}

	static void setNrFermieri(int nrFermieri) {
		if (nrFermieri > 0) {
			Fermier::nrFermieri = nrFermieri;
		}
	}

	void afisareFermier() {
		cout << "ID: " << id << ", Nume: " << nume << ", Varsta: " << varsta<< ", Numar echipamente: " << nrEchipamente << endl;
		if (pretEchipament != NULL) {
			for (int i = 0; i < nrEchipamente; i++) {
				cout << "Pret echipament " << i + 1 << ": " << pretEchipament[i] << endl;
			}
		}
		cout << endl;
	}

	static void resetNrFermieri() {
		Fermier::nrFermieri = 0;
	}

	void operator()(int echipIndex, int newPrice) {
		if (echipIndex >= 0 && echipIndex < nrEchipamente) {
			pretEchipament[echipIndex] = newPrice;
		}
	}

	Fermier& operator+=(int valoareEchipament) {
		int* pretEchipamentNou = new int[nrEchipamente + 1];
		for (int i = 0; i < nrEchipamente; i++) {
			pretEchipamentNou[i] = pretEchipament[i];
		}
		pretEchipamentNou[nrEchipamente] = valoareEchipament;
		delete[]pretEchipament;
		pretEchipament = pretEchipamentNou;
		nrEchipamente++;
		return *this;
	}

	Fermier& operator-=(int valoareEchipament) {
		bool found = false;
		for (int i = 0; i < nrEchipamente; i++) {
			if (pretEchipament[i] == valoareEchipament && !found) {
				found = true;
				for (int j = i; j < nrEchipamente - 1; j++) {
					pretEchipament[j] = pretEchipament[j + 1];
				}
				nrEchipamente--;
			}
		}
		if (found) {
			int* pretEchipamentNou = new int[nrEchipamente];
			for (int i = 0; i < nrEchipamente; i++) {
				pretEchipamentNou[i] = pretEchipament[i];
			}
			delete[]pretEchipament;
			pretEchipament = pretEchipamentNou;
		}
		return *this;
	}


	friend void pretTotalEchipamente(string nume, int nrEchipament, int* pretEchipament);
};
int Fermier::nrFermieri = 0;


void pretTotalEchipamente(string nume, int nrEchipament, int* pretEchipament) {
	int pretTotalEchipamente = 0;
	if (pretEchipament != NULL) {
		for (int i = 0; i < nrEchipament; i++) {
			pretTotalEchipamente = pretTotalEchipamente + pretEchipament[i];
		}
	}
	cout << "Fermierul cu numele: " << nume << " are echipamente in valoare de: " << pretTotalEchipamente << endl;
}


class Leguma {

private:
	const int id;
	char* tipLeguma;
	float costKG;
	bool gataDeRecoltat;
	static int nrLegume;

public:
	Leguma() :id(nrLegume++) {
		this->tipLeguma = new char[strlen("Necunoscuta") + 1];
		strcpy_s(this->tipLeguma, strlen("Necunoscuta") + 1, "Necunoscuta");
		this->costKG = 0;
		this->gataDeRecoltat = false;
	}

	Leguma(const char* tipLeguma) :id(nrLegume) {
		nrLegume++;
		this->tipLeguma = new char[strlen(tipLeguma) + 1];
		strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
		this->costKG = 0;
		this->gataDeRecoltat = false;
	}

	Leguma(const char* tipLeguma, float costKG, bool gataDeRecoltat) :id(nrLegume) {
		nrLegume++;
		this->tipLeguma = new char[strlen(tipLeguma) + 1];
		strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
		this->costKG = costKG;
		this->gataDeRecoltat = gataDeRecoltat;
	}

	Leguma(const Leguma& leguma) :id(nrLegume++) {
		this->tipLeguma = new char[strlen(leguma.tipLeguma) + 1];
		strcpy_s(this->tipLeguma, strlen(leguma.tipLeguma) + 1, leguma.tipLeguma);
		this->costKG = leguma.costKG;
		this->gataDeRecoltat = leguma.gataDeRecoltat;
	}

	const Leguma& operator= (const Leguma& leguma) {
		if (this != &leguma) {
			if (this->tipLeguma != NULL) 
				delete[]this->tipLeguma;
			this->tipLeguma = new char[strlen(leguma.tipLeguma) + 1];
			strcpy_s(this->tipLeguma, strlen(leguma.tipLeguma) + 1, leguma.tipLeguma);
			this->costKG = leguma.costKG;
			this->gataDeRecoltat = leguma.gataDeRecoltat;
		}
		return *this;
	}

	~Leguma() {
		if (this->tipLeguma != NULL) {
			delete[]this->tipLeguma;
		}
	}


	const int getId() {
		return this->id;
	}

	char* getTipLeguma() {
		return this->tipLeguma;
	}

	void setTipLeguma(const char* tipLeguma) {
		if (tipLeguma != NULL) {
			delete[]this->tipLeguma;
		}
		this->tipLeguma = new char[strlen(tipLeguma) + 1];
		strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
	}

	float getCostKG() {
		return this->costKG;
	}

	void setCostKG(float costKG) {
		if (costKG > 0) {
			this->costKG = costKG;
		}
	}

	bool getGataDeRecoltat() {
		return this->gataDeRecoltat;
	}

	void setGataDeRecoltat(bool gataDeRecoltat) {
		 this->gataDeRecoltat = gataDeRecoltat;
		
	}

	static int getNrLegume() {
		return Leguma::nrLegume;
	}

	static void setNrLegume(int nrLegume) {
		if (nrLegume > 0) {
			Leguma::nrLegume = nrLegume;
		}
	}

	static float calculCostTotal(Leguma* legume, int nrLegume) {
		float costTotal = 0;
		if (nrLegume < 0 || legume == NULL) {
			return costTotal;
		}
		for (int i = 0; i < nrLegume; i++) {
			if (legume[i].getGataDeRecoltat()) {
				costTotal = costTotal + legume[i].getCostKG();
			}
		}
		return costTotal;
	}

	Leguma operator+(const Leguma& leg) {
		Leguma result = leg;
		result.setTipLeguma("mix");
		result.setCostKG(this->getCostKG()+leg.costKG);
		result.setGataDeRecoltat(this->getGataDeRecoltat() || leg.gataDeRecoltat);
		return result;
	}

	Leguma& operator++() {
		this->costKG += 1;
		return *this;
	}

	Leguma operator++(int) {
		Leguma temp(*this);
		operator++();
		return temp;
	}

	operator float()const {
		return this->costKG;
	}

	operator int()const {
		return static_cast <int> (this->costKG);
	}

	void afisareLeguma() {
		cout << "ID: " << id << ", Tip leguma: " << tipLeguma << ", Cost KG: " << costKG << ", Gata de recoltat: " << gataDeRecoltat << endl;
	}

	friend void schimbaStadiulRecoltarii(Leguma& l);

};
int Leguma::nrLegume = 300;

void schimbaStadiulRecoltarii(Leguma& l) {
	l.setGataDeRecoltat(!l.getGataDeRecoltat());
}



void main() {

	cout << "SERA"<<endl;

	string* tipSera = new string[3];
	tipSera[0] = "Rece";
	tipSera[1] = "Temperata";
	tipSera[2] = "Calda";

	float* temperatura = new float[3];
	temperatura[0] = 8.5;
	temperatura[1] = 18.5;
	temperatura[2] = 27;

	Sera s1;
	Sera s2(2000, Odobesti, false);
	Sera s3(2010, Panciu, 3, tipSera, temperatura, true);

	s1.afisareSera();
	s2.afisareSera();
	s3.afisareSera();
	cout << endl;

	Sera s4(s3);
	s4.afisareSera();
	cout << endl;

	Sera s5 = s4;
	s5.afisareSera();
	cout << endl;
	

	cout << Sera::getJudet() << endl;
	cout << endl;


	float temperaturaMedie = Sera::calculTemperaturaMedie(temperatura, 3);
	cout <<"Temperatura medie: "<< temperaturaMedie << endl<<endl;

	cout << "Operator[]";
	pair <string, float> firstSera = s3[1];
	cout << "\nTip sera: " << firstSera.first << ", Temperatura: " << firstSera.second;
	cout << endl<<endl;

	cout << "Modificam valorile obiectului s3" << endl;

	cout << s3.getAnInfiintare()<<endl;

	s3.setLocalitate(Mandresti);
	cout << localitateString(s3.getLocalitate()) << endl;

	s3.setSera(2, tipSera, temperatura);
	int nrDeSere = s3.getNrSere();
	string* tipuriSere = s3.getTipSera();
	float* temperaturi = s3.getTemperatura();
	for (int i = 0; i < nrDeSere; i++) {
		cout << "Numar sere: " << i + 1 << endl;
		cout<<"Tip sera " << i + 1 <<": "<< tipuriSere[i] << "; Temperatura "<<i+1<<": " << temperaturi[i] << endl;
	}

	s3.setArePanouriFotovoltaice(false);
	cout << s1.getArePanouriFotovoltaice() << endl;

	s3.setJudet("Galati");
	cout << Sera::getJudet() << endl<<endl;

	cout << "Afisare noua sera s3 " << endl;
	s3.afisareSera();

	cout << s2 << endl;

	cin >> s3;
	cout << endl;
	cout << s3 << endl;


	cout << endl<<endl;


	cout << "FERMIER" << endl;

	int* pretEchipament = new int[4];
	pretEchipament[0] = 800;
	pretEchipament[1] = 1100;
	pretEchipament[2] = 1300;
	pretEchipament[3] = 2200;

	Fermier f1;
	Fermier f2("George Paun", 29);
	Fermier f3("Anca Ionescu", 38, 4, pretEchipament);

	f1.afisareFermier();
	f2.afisareFermier();
	f3.afisareFermier();

	Fermier f4(f2);
	f4.afisareFermier();

	Fermier f7 = f2;
	f7.afisareFermier();
	cout << endl;

	cout << Fermier::getNrFermieri() << endl;
	cout << endl;

	pretTotalEchipamente(f3.getNume(), f3.getNrEchipamente(), f3.getPretEchipamente());
	cout << endl;

	cout << "Operator()" << "\nModificam pretul primul echipament" << endl;
	Fermier f8("George Paun", 24, 4, pretEchipament);
	f8(0, 850);
	f8.afisareFermier();

	f3 += 2500;
	f3.afisareFermier();
	cout << endl;

	f3 -= 1300;
	f3.afisareFermier();
	cout << endl;

	cout << "Modificam valorile obiectului f3" << endl;

	cout << f3.getId() << endl;

	f3.setNume("Sandra Diac");
	cout << f3.getNume() << endl;

	f3.setVarsta(32);
	cout << f3.getVarsta() << endl;

	f3.setEchipament(2, pretEchipament);
	int nrDeEchipamente = f3.getNrEchipamente();
	int* preturi = f3.getPretEchipamente();
	for (int i = 0; i < nrDeEchipamente; i++) {
		cout << "Numar echipamente: " << i + 1 << ", pretul echipamentului " << i + 1 << ": " << preturi[i] << endl;
	}

	f3.setNrFermieri(1);
	cout << Fermier::getNrFermieri() << endl << endl;

	cout << "Afisare noul fermier f3 " << endl;
	f3.afisareFermier();
	cout << endl;

	Fermier::resetNrFermieri();
	cout << "Resetare Fermieri; Reincepem inregistrarea fermierilor" << endl;
	
	Fermier f5;
	f5.afisareFermier();
	Fermier f6("Bogdan Antal", 41, 2, pretEchipament);
	f6.afisareFermier();

	cout << endl;


	cout << "LEGUMA" << endl;

	Leguma l1;
	Leguma l2("Rosie");
	Leguma l3("Ardei", 9.5, true);

	l1.afisareLeguma();
	l2.afisareLeguma();
	l3.afisareLeguma();

	Leguma l4(l3);
	l4.afisareLeguma();
	cout << endl;

	Leguma l5 = l4;
	l5.afisareLeguma();
	cout << endl;

	cout << Leguma::getNrLegume() << endl;
	cout << endl;

	++l3;
	l2++;
	cout << "Operator++; creste costul KG cu 1" << endl;
	l3.afisareLeguma();
	l2.afisareLeguma();

	cout << "Operator +" << endl;
	Leguma l6("salata", 5, false);
	Leguma l7 = l6+l5;
	l7.afisareLeguma();
	cout << endl;

	cout << "Operator cast" << endl;
	float cost = (float)l7;
	cout << cost << endl;
	int costInt = (int)l7;
	cout << costInt << endl;
	cout << endl;

	cout << "Modificam valorile obiectului l3" << endl;

	cout << l3.getId() << endl;

	l3.setTipLeguma("castravete");
	cout << l3.getTipLeguma() << endl;

	l3.setCostKG(7.5);
	cout << l3.getCostKG() << endl;

	l3.setGataDeRecoltat(false);
	cout << l3.getGataDeRecoltat() << endl;

	l3.setNrLegume(100);
	cout << Leguma::getNrLegume() << endl << endl;

	cout << "Afisare noua leguma l3 " << endl;
	l3.afisareLeguma();

	cout << endl;


	Leguma legume[] = { l1, l2, l3, l4 };

	float costTotal = Leguma::calculCostTotal(legume, 4);
	cout << "Costul total al legumelor gata de recoltat: " << costTotal << " lei" << endl;
	cout << endl;

	for (int i = 0; i < 4; ++i) {
		schimbaStadiulRecoltarii(legume[i]);
	}
	for (int i = 0; i < 4; ++i) {
		legume[i].afisareLeguma();
	}

	cout << endl;

}
















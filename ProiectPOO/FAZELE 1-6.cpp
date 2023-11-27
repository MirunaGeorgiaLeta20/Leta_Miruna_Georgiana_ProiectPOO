//Domeniul Legumicultura (initiale: M,G,L)

#include<iostream>
#include<string>
#include<fstream>

using namespace std;


enum localitate {Localitate, Mandresti, Odobesti, Panciu, Marasesti};

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
	else return "Localitate";
}


class Ferma {
	const int anInfiintare;
	localitate loc;
	int nrSere;
	string* tipSera;
	float* temperatura;
	bool arePanouriFotovoltaice;
	static string judet;

public:
	Ferma() :anInfiintare(1990) {
		this->loc = Localitate;
		this->nrSere = 0;
		this->tipSera = NULL;
		this->temperatura = NULL;
		this->arePanouriFotovoltaice = 0;
	}


	Ferma(int an, localitate loc, bool arePanouriFotovoltaice) : anInfiintare(an) {
		this->loc = loc;
		this->nrSere = 0;
		this->tipSera = NULL;
		this->temperatura = NULL;
		this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}


	Ferma(int an, localitate loc, int nrSere, string* tipSera, float* temperatura, bool arePanouriFotovoltaice) : anInfiintare(an) {
		
		this->loc = loc;

		if (nrSere > 0 && tipSera != NULL && temperatura != NULL) {
			this->nrSere = nrSere;
			this->tipSera = new string[this->nrSere];
			this->temperatura = new float[this->nrSere];

			for (int i = 0; i < this->nrSere; i++) {

				if (tipSera[i].size() >= 3)
					this->tipSera[i] = tipSera[i];
				else this->tipSera[i] = "Necunoscuta";

				if (temperatura[i] >= 8 && temperatura[i] <= 30)
					this->temperatura[i] = temperatura[i];
				else if (temperatura[i] > 30)
					this->temperatura[i] = 30;
				else this->temperatura[i] = 8;
			}
		}
		else {
			this->nrSere = 0;
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
		this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}

	Ferma(const Ferma& sera) : anInfiintare(sera.anInfiintare) {

		this->loc = sera.loc;

		if (sera.nrSere > 0 && sera.tipSera != NULL && sera.temperatura != NULL) {
			this->nrSere = sera.nrSere;
			this->tipSera = new string[this->nrSere];
			this->temperatura = new float[this->nrSere];

			for (int i = 0; i < this->nrSere; i++) {
				if (sera.tipSera[i].size() >= 3)
					this->tipSera[i] = sera.tipSera[i];
				else this->tipSera[i] = "Necunoscuta";

				if (sera.temperatura[i] >= 8 && sera.temperatura[i] <= 30)
					this->temperatura[i] = sera.temperatura[i];
				else if (sera.temperatura[i] > 30)
					this->temperatura[i] = 30;
				else this->temperatura[i] = 8;
			}
		}
		else {
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
		this->arePanouriFotovoltaice = sera.arePanouriFotovoltaice;
	}

	Ferma& operator=(const Ferma& sera) {
		if (this != &sera) {

			if (this->tipSera != NULL) {
				delete[]this->tipSera;
			}
			if (this->temperatura != NULL) {
				delete[]this->temperatura;
			}
			this->loc = sera.loc;

			if (sera.nrSere > 0 && sera.tipSera != NULL && sera.temperatura != NULL) {
				this->nrSere = sera.nrSere;
				this->tipSera = new string[this->nrSere];
				this->temperatura = new float[this->nrSere];
				for (int i = 0; i < this->nrSere; i++) {
					if (sera.tipSera[i].size() >= 3)
						this->tipSera[i] = sera.tipSera[i];
					else this->tipSera[i] = "Necunoscuta";

					if (sera.temperatura[i] >= 8 && sera.temperatura[i] <= 30)
						this->temperatura[i] = sera.temperatura[i];
					else if (sera.temperatura[i] > 30)
						this->temperatura[i] = 30;
					else this->temperatura[i] = 8;
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

	~Ferma() {
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

	int getNrSere() {
		return this->nrSere;
	}

	string* getTipSera() {
		return this->tipSera;
	}

	float* getTemperatura() {
		return this->temperatura;
	}

	bool getArePanouriFotovoltaice() {
		return this->arePanouriFotovoltaice;
	}

	static string getJudet() {
		return judet;
	}

	
	void setLocalitate(localitate loc) {
			this->loc = loc;
	}

	void setSera(int nrSere, string* tipSera, float* temperatura) {
		if (this->tipSera != NULL) {
			delete[]this->tipSera;
		}
		if (this->temperatura != NULL) {
			delete[]this->temperatura;
		}

		if (nrSere > 0 && tipSera != NULL && temperatura != NULL) {
			this->nrSere = nrSere;
			this->tipSera = new string[this->nrSere];
			this->temperatura = new float[this->nrSere];
			for (int i = 0; i < this->nrSere; i++) {
				if (tipSera[i].size() >= 3)
					this->tipSera[i] = tipSera[i];
				else this->tipSera[i] = "Necunoscuta";

				if (temperatura[i] >= 8 && temperatura[i] <= 30)
					this->temperatura[i] = temperatura[i];
				else if (temperatura[i] > 30)
					this->temperatura[i] = 30;
				else this->temperatura[i] = 8;
			}
		}
		else {
			this->nrSere = 0;
			this->tipSera = NULL;
			this->temperatura = NULL;
		}
	}

	void setArePanouriFotovoltaice(bool arePanouriFotovoltaice) {
			this->arePanouriFotovoltaice = arePanouriFotovoltaice;
	}

	static void setJudet(string judet) {
		if (judet.size() >= 3) {
			Ferma::judet = judet;
		}
		else Ferma::judet = "Judet";
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


	pair<string,float> operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrSere) {
			return { this->tipSera[pozitie], this->temperatura[pozitie] };
		}
	}

	Ferma& operator!() {
		arePanouriFotovoltaice = !arePanouriFotovoltaice;
		return *this;
	}

	friend istream& operator>>(istream& in, Ferma& sera);

	friend ostream& operator<<(ostream& out, const Ferma& sera);


	friend ofstream& operator<<(ofstream& out, const Ferma& sera) {
		out << sera.loc << endl;
		out << sera.nrSere << endl;
		for (int i = 0; i < sera.nrSere; i++) {
			out << sera.tipSera[i] << " " << sera.temperatura[i] << endl;
		}
		out << sera.arePanouriFotovoltaice << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Ferma& sera) {
		int val;
		in >> val;
		switch (val) {
		case 0: sera.loc = Localitate; break;
		case 1: sera.loc = Mandresti; break;
		case 2: sera.loc = Odobesti; break;
		case 3: sera.loc = Panciu; break;
		case 4: sera.loc = Marasesti; break;
		default: sera.loc = Localitate; break; }

		in >> sera.nrSere;

		if (sera.tipSera != NULL)
			delete[]sera.tipSera;
		if (sera.temperatura != NULL)
			delete[]sera.temperatura;
		sera.tipSera = new string[sera.nrSere];
		sera.temperatura = new float[sera.nrSere];
		for (int i = 0; i < sera.nrSere; i++)
		{	in >> sera.tipSera[i];
			in >> sera.temperatura[i]; }

		in >> sera.arePanouriFotovoltaice;
		return in;
	}


};
string Ferma::judet = "Vrancea";



istream& operator>>(istream& in, Ferma& sera)
{
	cout << "Localitate (0-Localitate, 1-Mandresti, 2-Odobesti, 3-Panciu, 4-Marasesti) :  ";
	int val; 
	in >> val;
	switch (val) {
	case 0: sera.loc = Localitate; break;
	case 1: sera.loc=Mandresti; break;
	case 2: sera.loc=Odobesti; break;
	case 3: sera.loc=Panciu; break;
	case 4: sera.loc=Marasesti; break;
	default: sera.loc=Localitate; break;
	}

	cout << "Numar sere: ";
	in >> sera.nrSere;

	if (sera.tipSera != NULL) 
		delete[]sera.tipSera;
	if (sera.temperatura != NULL) 
		delete[]sera.temperatura;
	sera.tipSera = new string[sera.nrSere];
	sera.temperatura = new float[sera.nrSere];
	for (int i = 0; i < sera.nrSere; i++) 
	{
		cout << "Tip sera " << i + 1 << ": ";
		in >> sera.tipSera[i]; 
		cout << "Temperatura " << i + 1 << ": ";
		in >> sera.temperatura[i]; 
	}

	cout << "Are panouri fotovoltaice (0-NU, 1-DA) : ";
	in >> sera.arePanouriFotovoltaice;
	return in;
}


ostream& operator<<(ostream& out, const Ferma& sera)
{
	out << "An Infiintare: " << sera.anInfiintare << endl;
	out << "Localitate: ";
	switch (sera.loc) {
	case 0: out << "Localitate"; break;
	case 1: out << "Mandresti"; break;
	case 2: out << "Odobesti"; break;
	case 3: out << "Panciu"; break;
	case 4: out << "Marasesti"; break;
	default: out << "Localitate"; break;
	}
	out << endl;
	out << "Numar sere: " << sera.nrSere << endl;
	for (int i = 0; i < sera.nrSere; i++) {
		out << "Tip sera " << i + 1 << ": " << sera.tipSera[i] << ",  Temperatura " << i + 1 << ": " << sera.temperatura[i] << endl;
	}
	out << "Are panouri fotovoltaice: " << sera.arePanouriFotovoltaice << endl;
	out << endl;
	return out;
}



class Fermier {
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
		if (nume.size() >= 3) {
			this->nume = nume;
		}
		else this->nume = "Anonim";

		if (varsta > 0) {
			this->varsta = varsta;
		}
		else this->varsta = 0;
		
		this->nrEchipamente = NULL;
		this->pretEchipament = NULL;
		nrFermieri++;
	}


	Fermier(string nume, int varsta, int nrEchipamente, int* pretEchipament) :id(nrFermieri) {
		if (nume.size() >= 3) {
			this->nume = nume;
		}
		else this->nume = "Anonim";

		if (varsta > 0) {
			this->varsta = varsta;
		}
		else this->varsta = 0;

		if (nrEchipamente > 0 && pretEchipament!=NULL) {
			this->nrEchipamente = nrEchipamente;
			this->pretEchipament = new int[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++) {
				if (pretEchipament[i] >= 100) {
					this->pretEchipament[i] = pretEchipament[i];
				}
				else this->pretEchipament[i] = 100;
			}
		}
		else {
			this->nrEchipamente = 0;
			this->pretEchipament = NULL;
		}
		nrFermieri++;
	}

	Fermier(const Fermier& fermier) :id(fermier.nrFermieri) {
		if (fermier.nume.size() >= 3) {
			this->nume = fermier.nume;
		}
		else this->nume = "Anonim";

		if (fermier.varsta > 0) {
			this->varsta = fermier.varsta;
		}
		else this->varsta = 0;

		if (fermier.nrEchipamente > 0 && fermier.pretEchipament != NULL) {
			this->nrEchipamente = fermier.nrEchipamente;
			this->pretEchipament = new int[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++) {
				if (fermier.pretEchipament[i] >= 100) {
					this->pretEchipament[i] = fermier.pretEchipament[i];
				}
				else this->pretEchipament[i] = 100;
			}
		}
		else {
			this->nrEchipamente = 0;
			this->pretEchipament = NULL;
		}
	}

	Fermier& operator= (const Fermier& fermier) {
		if (this != &fermier) {

			if (this->pretEchipament != NULL)
				delete[]this->pretEchipament;

			if (fermier.nume.size() >= 3) {
				this->nume = fermier.nume;
			}
			else this->nume = "Anonim";

			if (fermier.varsta > 0) {
				this->varsta = fermier.varsta;
			}
			else this->varsta = 0;

			if (fermier.nrEchipamente > 0 && fermier.pretEchipament != NULL) {
				this->nrEchipamente = fermier.nrEchipamente;
				this->pretEchipament = new int[this->nrEchipamente];
				for (int i = 0; i < this->nrEchipamente; i++) {
					if (fermier.pretEchipament[i] >= 100) {
						this->pretEchipament[i] = fermier.pretEchipament[i];
					}
					else this->pretEchipament[i] = 100;
				}
			}
			else {
				this->nrEchipamente = 0;
				this->pretEchipament = NULL;
			}
			return *this;
		}
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

	int getVarsta() {
		return this->varsta;
	}

	int getNrEchipamente() {
		return this->nrEchipamente;
	}

	int* getPretEchipamente() {
		return this->pretEchipament;
	}

	static int getNrFermieri() {
		return nrFermieri;
	}

	void setNume(string nume) {
		if (nume.size() >= 3) {
			this->nume = nume;
		}
		else this->nume = "Anonim";
	}

	void setVarsta(int varsta) {
		if (varsta > 0) {
			this->varsta = varsta;
		}
		else this->varsta = 0;
	}

	void setEchipament(int nrEchipamente, int* pretEchipament) {
		if (this->pretEchipament != NULL) {
			delete[]this->pretEchipament;
		}
		if (nrEchipamente > 0 && pretEchipament != NULL) {
			this->nrEchipamente = nrEchipamente;
			this->pretEchipament = new int[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++) {
				if (pretEchipament[i] >= 100) {
					this->pretEchipament[i] = pretEchipament[i];
				}
				else this->pretEchipament[i] = 100;
			}
		}
		else {
			this->nrEchipamente = 0;
			this->pretEchipament = NULL;
		}
	}


	static void setNrFermieri(int nrFermieri) {
		if (nrFermieri >= 1) {
			Fermier::nrFermieri = nrFermieri;
		}
		else Fermier::nrFermieri = 0;
	}


	void afisareFermier() {
		cout << "ID: " << id << ", Nume: " << nume << ", Varsta: " << varsta<< ", Numar echipamente: " << nrEchipamente << endl;
		for (int i = 0; i < nrEchipamente; i++) {
			cout << "Pret echipament " << i + 1 << ": " << pretEchipament[i] << endl;
		}
		cout << endl;
	}

	static void resetNrFermieri() {
		Fermier::nrFermieri = 0;
	}

	void operator()(int echipIndex, int pretNou) {
		if (echipIndex >= 0 && echipIndex < nrEchipamente) {
			pretEchipament[echipIndex] = pretNou;
		}
	}

	Fermier& operator+=(int valoareEchipament) {
		Fermier copie = *this;
		if (this->pretEchipament != NULL) {
			delete[]this->pretEchipament;
		}
		this->nrEchipamente++;
		this->pretEchipament = new int[this->nrEchipamente];
		for (int i = 0; i < copie.nrEchipamente; i++) {
			this->pretEchipament[i] = copie.pretEchipament[i];
		}
		this->pretEchipament[this->nrEchipamente - 1] = valoareEchipament;
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

	bool operator>=(Fermier fm) {
		return this->varsta >= fm.varsta;
	}

	friend void pretTotalEchipamente(string nume, int nrEchipament, int* pretEchipament);

	friend istream& operator>>(istream& in, Fermier& f);

	friend ostream& operator<<(ostream& out, const Fermier& f);


	/*string nume;
	int varsta;
	int nrEchipamente;
	int* pretEchipament;*/

	void serializare(string numeFisier) {
		ofstream f(numeFisier, ios::out | ios::binary);

		int dimNume = this->nume.size();//this->numeMagazin.length()
		f.write((char*)&dimNume, sizeof(dimNume));
		f.write(this->nume.c_str(), dimNume + 1);

		f.write((char*)&this->varsta, sizeof(this->varsta));

		f.write((char*)&this->nrEchipamente, sizeof(this->nrEchipamente));
		for (int i = 0; i < this->nrEchipamente; i++) {
			f.write((char*)&this->pretEchipament[i], sizeof(this->pretEchipament[i]));
		}
	}

	void deserializare(string numeFisier) {
		ifstream f(numeFisier, ios::out | ios::binary);
		if (f.is_open()) {
			int dimNume = 0;
			f.read((char*)&dimNume, sizeof(dimNume));
			char* aux = new char[dimNume + 1];
			f.read(aux, dimNume + 1);
			this->nume = aux;
			delete[]aux;

			f.read((char*)&this->varsta, sizeof(this->varsta));

			f.read((char*)&this->nrEchipamente, sizeof(this->nrEchipamente));

			if (this->pretEchipament != NULL)
				delete[]this->pretEchipament;
			this->pretEchipament = new int[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++) {
				f.read((char*)&this->pretEchipament[i], sizeof(this->pretEchipament[i]));
			}
		}
	}

};
int Fermier::nrFermieri = 0;


istream& operator>>(istream& in, Fermier& f)
{
	cout << "Nume Fermier: ";
	in >> f.nume;
	cout << "Varsta: ";
	in >> f.varsta;
	cout << "Numar echipamente: ";
	in >> f.nrEchipamente;
	if (f.pretEchipament != NULL)
		delete[]f.pretEchipament;
	f.pretEchipament = new int[f.nrEchipamente];
	for (int i = 0; i < f.nrEchipamente; i++) {
		cout << "Pret echipament " << i + 1 << ": ";
		in >> f.pretEchipament[i];
	}
	cout << endl;
	return in;
}



ostream& operator<<(ostream& out, const Fermier& f)
{
	out << "ID: " << f.id << ", Nume Fermier: " << f.nume << ", Varsta: " << f.varsta << ", Numar echipamente: " << f.nrEchipamente << endl;
	for (int i = 0; i < f.nrEchipamente; i++) {
		out << "Pret echipament " << i + 1 << ": " << f.pretEchipament[i] << endl;
	}
	out << endl;
	return out;
}

void pretTotalEchipamente(string nume, int nrEchipament, int* pretEchipament) {
	int pretTotalEchipamente = 0;
	if (pretEchipament != NULL) {
		for (int i = 0; i < nrEchipament; i++) {
			pretTotalEchipamente = pretTotalEchipamente + pretEchipament[i];
		}
	}
	cout << "Fermierul cu numele: " << nume << " are echipamente in valoare de: " << pretTotalEchipamente<<" lei." << endl;
}



class Leguma {
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
		this->gataDeRecoltat = 0;
	}

	Leguma(const char* tipLeguma, float costKG) :id(nrLegume) {
		if (tipLeguma != NULL && strlen(tipLeguma) >= 3) {
			this->tipLeguma = new char[strlen(tipLeguma) + 1];
			strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
		}
		else if (tipLeguma != NULL) {
			this->tipLeguma = new char[strlen("Leguma") + 1];
			strcpy_s(this->tipLeguma, strlen("Leguma") + 1, "Leguma");
		}
		else this->tipLeguma = NULL;

		if (costKG >= 1)
			this->costKG = costKG;
		else this->costKG = 1;

		this->gataDeRecoltat = 0;
		nrLegume++;
	}

	Leguma(const char* tipLeguma, float costKG, bool gataDeRecoltat) :id(nrLegume) {
		if (tipLeguma != NULL && strlen(tipLeguma)>=3) {
			this->tipLeguma = new char[strlen(tipLeguma) + 1];
			strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
		}
		else if (tipLeguma != NULL) {
			this->tipLeguma = new char[strlen("Leguma") + 1];
			strcpy_s(this->tipLeguma, strlen("Leguma") + 1, "Leguma");
		}
		else this->tipLeguma = NULL;

		if (costKG >= 1)
			this->costKG = costKG;
		else this->costKG = 1;

		this->gataDeRecoltat = gataDeRecoltat;
		nrLegume++;
	}

	Leguma(const Leguma& leguma) :id(leguma.nrLegume) {
		if (leguma.tipLeguma != NULL && strlen(leguma.tipLeguma) >= 3) {
			this->tipLeguma = new char[strlen(leguma.tipLeguma) + 1];
			strcpy_s(this->tipLeguma, strlen(leguma.tipLeguma) + 1, leguma.tipLeguma);
		}
		else if (tipLeguma != NULL) {
			this->tipLeguma = new char[strlen("Leguma") + 1];
			strcpy_s(this->tipLeguma, strlen("Leguma") + 1, "Leguma");
		}
		else this->tipLeguma = NULL;

		if (leguma.costKG >= 1)
			this->costKG = leguma.costKG;
		else this->costKG = 1;
		this->gataDeRecoltat = leguma.gataDeRecoltat;
	}

	Leguma& operator= (const Leguma& leguma) {
		if (this != &leguma) {
			if (this->tipLeguma != NULL) 
				delete[]this->tipLeguma;

			if (leguma.tipLeguma != NULL && strlen(leguma.tipLeguma) >= 3) {
				this->tipLeguma = new char[strlen(leguma.tipLeguma) + 1];
				strcpy_s(this->tipLeguma, strlen(leguma.tipLeguma) + 1, leguma.tipLeguma);
			}
			else if (tipLeguma != NULL) {
				this->tipLeguma = new char[strlen("Leguma") + 1];
				strcpy_s(this->tipLeguma, strlen("Leguma") + 1, "Leguma");
			}
			else this->tipLeguma = NULL;

			if (leguma.costKG >= 1)
				this->costKG = leguma.costKG;
			else this->costKG = 1;

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

	float getCostKG() {
		return this->costKG;
	}

	bool getGataDeRecoltat() {
		return this->gataDeRecoltat;
	}

	static int getNrLegume() {
		return nrLegume;
	}

	void setTipLeguma(const char* tipLeguma) {
		if (tipLeguma != NULL) {
			delete[]this->tipLeguma;
		}
		if (tipLeguma != NULL && strlen(tipLeguma) >= 3) {
			this->tipLeguma = new char[strlen(tipLeguma) + 1];
			strcpy_s(this->tipLeguma, strlen(tipLeguma) + 1, tipLeguma);
		}
		else if (tipLeguma != NULL) {
			this->tipLeguma = new char[strlen("Leguma") + 1];
			strcpy_s(this->tipLeguma, strlen("Leguma") + 1, "Leguma");
		}
		else this->tipLeguma = NULL;
	}

	void setCostKG(float costKG) {
		if (costKG >= 1)
			this->costKG = costKG;
		else this->costKG = 1;
	}

	void setGataDeRecoltat(bool gataDeRecoltat) {
		 this->gataDeRecoltat = gataDeRecoltat;
	}
	
	static void setNrLegume(int nrLegume) {
		if (nrLegume > 0) {
			Leguma::nrLegume = nrLegume;
		}
		else Leguma::nrLegume = 0;
	}

	static float calculCostTotal(Leguma* leguma, int nrLegume) {
		float costTotal = 0;
		if (nrLegume <= 0 || leguma == NULL) {
			return costTotal;
		}
		for (int i = 0; i < nrLegume; i++) {
			if (leguma[i].getGataDeRecoltat()) {
				costTotal = costTotal + leguma[i].getCostKG();
			}
		}
		return costTotal;
	}

	Leguma operator+(const Leguma& leg) {
		Leguma result = leg;
		result.setTipLeguma("mix");
		result.setCostKG(this->getCostKG()+leg.costKG);
		result.setGataDeRecoltat(false);
		return result;
	}

	Leguma& operator++() {
		this->costKG += 1;
		return *this;
	}

	Leguma operator++(int) {
		Leguma copie = *this;
		this->costKG += 1;
		return copie;
	}

	explicit operator int() {
		return this->costKG;
	}


	Leguma* operator ->() {
		this->costKG = 8;
		return this;
	}

	void afisareLeguma() {
		cout << "ID: " << id << ", Tip leguma: " << tipLeguma << ", Cost KG: " << costKG << ", Gata de recoltat: " << gataDeRecoltat << endl;
	}

	friend void schimbaStadiulRecoltarii(Leguma& l);

	friend istream& operator>>(istream& in, Leguma& l);

	friend ostream& operator<<(ostream& out, const Leguma& l);


	void serializare(string numeFisier) {
		ofstream f(numeFisier, ios::out | ios::binary);

		int dimTip = strlen(this->tipLeguma);
		f.write((char*)&dimTip, sizeof(dimTip));
		f.write(this->tipLeguma, dimTip + 1);

		f.write((char*)&this->costKG, sizeof(this->costKG));

		f.write((char*)&this->gataDeRecoltat, sizeof(this->gataDeRecoltat));
	}

};
int Leguma::nrLegume = 0;

void schimbaStadiulRecoltarii(Leguma& l) {
	l.setGataDeRecoltat(!l.getGataDeRecoltat());
}


istream& operator>>(istream& in, Leguma& l)
{
	if (l.tipLeguma != NULL)
		delete[]l.tipLeguma;
	l.tipLeguma = new char[strlen(l.tipLeguma) + 1];
	strcpy_s(l.tipLeguma, strlen(l.tipLeguma) + 1, l.tipLeguma);

	cout << "Tip leguma: ";
	in >> l.tipLeguma;
	cout << "Cost KG: ";
	in >> l.costKG;
	cout << "Gata de recoltat (0-NU, 1-DA) : ";
	in >> l.gataDeRecoltat;
	cout << endl;
	return in;
}


ostream& operator<<(ostream& out, const Leguma& l)
{
	out << "ID: " << l.id << ", Tip leguma: " << l.tipLeguma << ", Cost KG: " << l.costKG << ", Gata de recoltat: " << l.gataDeRecoltat;
	out << endl;
	return out;
}



class Magazin {

	string nume;
	int nrVanzatori;
	float venitZilnic;
	int nrLegume;
	Leguma* vLegume;

public:
	Magazin() {
		this->nume = "Magazin";
		this->nrVanzatori = 0;
		this->venitZilnic = 0;
		this->nrLegume = 0;
		this->vLegume = NULL;
	}

	Magazin(string nume, int nrVanzatori, float venitZilnic, int nrLegume, Leguma* vLegume) {
		this->nume = nume;
		this->nrVanzatori = nrVanzatori;
		this->venitZilnic = venitZilnic;
		this->nrLegume = nrLegume;
		this->vLegume = new Leguma[this->nrLegume];
		for (int i = 0; i < this->nrLegume; i++) {
			this->vLegume[i] = vLegume[i];
		}
	}

	~Magazin() {
		if (this->vLegume != NULL) delete[]this->vLegume;
	}

	Magazin(const Magazin& m) {
		this->nume = m.nume;
		this->nrVanzatori = m.nrVanzatori;
		this->venitZilnic = m.venitZilnic;
		this->nrLegume = m.nrLegume;
		this->vLegume = new Leguma[this->nrLegume];
		for (int i = 0; i < this->nrLegume; i++) {
			this->vLegume[i] = m.vLegume[i];
		}
	}

	Magazin& operator=(const Magazin& m) {
		if (this != &m) {
			if (this->vLegume != NULL) delete[]this->vLegume;
			this->nume = m.nume;
			this->nrVanzatori = m.nrVanzatori;
			this->venitZilnic = m.venitZilnic;
			this->nrLegume = m.nrLegume;
			this->vLegume = new Leguma[this->nrLegume];
			for (int i = 0; i < this->nrLegume; i++) {
				this->vLegume[i] = m.vLegume[i];
			}
		}
		return *this;
	}


	string getNume() {
		return this->nume;
	}
	int getNrVanzatori() {
		return this->nrVanzatori;
	}
	float getVenitZilnic() {
		return this->venitZilnic;
	}
	int getNrLegume() {
		return this->nrLegume;
	}
	Leguma* getLeguma() {
		return this->vLegume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setNrVanzatori(int nrVanzatori) {
		this->nrVanzatori = nrVanzatori;
	}

	void setVenitZilnic(float venitZilnic) {
		 this->venitZilnic = venitZilnic;
	}

	void setLegume(int nrLegume, Leguma* vLegume) {
		if (this->vLegume != NULL) delete[]this->vLegume;
		this->nrLegume = nrLegume;
		this->vLegume = new Leguma[this->nrLegume];
		for (int i = 0; i < this->nrLegume; i++) {
			this->vLegume[i] = vLegume[i];
		}
	}

	Magazin operator++(int) {
		Magazin copie = *this;
		this->nrVanzatori++;
		this->venitZilnic += 300;
		return copie;
	}

	void operator()(Leguma nou) {
		Magazin aux = *this;
		if (this->vLegume != NULL) {
			delete[]this->vLegume;
		}
		this->nrLegume++;
		this->vLegume = new Leguma [this->nrLegume];
		for (int i = 0; i < aux.nrLegume; i++) {
			this->vLegume[i] = aux.vLegume[i];
		}
		this->vLegume[this->nrLegume - 1] = nou;
	}

	friend ostream& operator<<(ostream& out, const Magazin& m) {

		out << "Nume magazin: " << m.nume << ", Numar Vanzatori: " << m.nrVanzatori << ", Venit: " << m.venitZilnic << endl;
		out << "Numarul de legume aflate in magazin: " << m.nrLegume << endl;
		if (m.nrLegume > 0) {
			out << endl;
			out << "Legume: " << endl;
			for (int i = 0; i < m.nrLegume; i++) {
				out << m.vLegume[i];
			}
			out << endl;
		}
		return out;
	}

	
	friend ofstream& operator<<(ofstream& out, const Magazin& m) {
		out << "Nume magazin: " << m.nume << ", Numar Vanzatori: " << m.nrVanzatori << ", Venit: " << m.venitZilnic << endl;
		out << "Numarul de legume aflate in magazin: " << m.nrLegume << endl;
		if (m.nrLegume > 0) {
			out << endl;
			out << "Legume: " << endl;
			for (int i = 0; i < m.nrLegume; i++) {
				out << m.vLegume[i];
			}
			out << endl;
		}
		return out;
	}
};



void main() {

	cout << endl;
	cout << "FERMA" << endl << endl;

	string* tipSera = new string[3];
	tipSera[0] = "Rece";
	tipSera[1] = "Temperata";
	tipSera[2] = "Calda";

	float* temperatura = new float[3];
	temperatura[0] = 8.5;
	temperatura[1] = 18;
	temperatura[2] = 27;

	Ferma s1;
	Ferma s2(2000, Odobesti, false);
	Ferma s3(2010, Panciu, 3, tipSera, temperatura, true);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	

	cout << "Temperatura medie: " <<  Ferma::calculTemperaturaMedie(temperatura, 3) << endl << endl;

	cout <<"Judet: "<< Ferma::getJudet() << endl;
	cout << endl << endl;

	cout << "Constructorul de copiere" << endl;
	Ferma s4=s2;
	cout << s4 << endl;
	cout << endl;

	cout << "Operatorul =" << endl;
	s4 = s3;
	cout<<s4<<endl;
	cout << endl;

	cout << "Operatorul []" << "\nAccesam elementele celui de-al doilea vector";
	pair <string, float> fer = s3[1];
	cout << "\nTip sera: " << fer.first << ", Temperatura: " << fer.second;
	cout << endl << endl << endl;


	cout << "Afisam valorile obiectului s3 dupa modificari" << endl;

	cout << "An infiintare: " << s3.getAnInfiintare() << endl;

	s3.setLocalitate(Mandresti);
	cout << "Localitate: " << localitateString(s3.getLocalitate()) << endl;

	string tip[] = { "Rece", "Calda" };
	float temp[] = { 8, 29 };

	s3.setSera(2, tip, temp);
	cout << "Numar sere: " << s3.getNrSere() << endl;
	for (int i = 0; i < s3.getNrSere(); i++) {
		cout << "Tip sera " << i + 1 << ": " << s3.getTipSera()[i] << "; Temperatura " << i + 1 << ": " << s3.getTemperatura()[i] << endl;
	}

	s3.setArePanouriFotovoltaice(false);
	cout << "Are panouri fotovoltaice: " << s3.getArePanouriFotovoltaice() << endl;

	s3.setJudet("Galati");
	cout <<"Judet: "<< Ferma::getJudet() << endl << endl;
	cout << endl;

	cout << "Operatorul <<"<<"\nAfisare noua sera s3" << endl;
	cout << s3;
	cout << "Judet: " << Ferma::getJudet();

	cout << endl << endl;

	cout << "Operatorul!" << endl;
	cout << "s2 panouri fotovoltaice initial : " << s2.getArePanouriFotovoltaice() << endl;
	!s2;
	cout<<"s2 panouri fotovoltaice dupa operatorul! : "<< s2.getArePanouriFotovoltaice() << endl;
	cout << endl << endl;
	

	cout << "Operatorul >>"<<"\nCitim de la tastatura" << endl;
	cin >> s3;
	cout << endl;
	cout << s3 << endl << endl;


	cout << "Fisiere text --- Scrierea in fisier text(Afisarea in fisier text)" << endl;
	ofstream fOut("Ferma.txt", ios::out);
	fOut << s4;
	fOut.close();
	cout << endl << endl;

	cout << "Fisiere text --- Citirea din fisier text(Importarea din fisier text)" << endl;
	Ferma s5;
	cout << s5 << endl;
	ifstream fIn("Ferma.txt", ios::in);
	if (fIn) {
		fIn >> s5;
		cout << s5;
	}
	else {
		cout << "Fisierul cautat nu exista!" << endl;
	}

	cout << endl << endl << endl;



	cout << "FERMIER" << endl << endl;

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

	pretTotalEchipamente(f3.getNume(), f3.getNrEchipamente(), f3.getPretEchipamente());
	cout << endl;

	cout << "Numar fermieri: " << Fermier::getNrFermieri() << endl;
	cout << endl;

	cout << "Constructor de copiere" << endl;
	Fermier f4=f1;
	f4.afisareFermier();

	cout << "Operator =" << endl;
	f4 = f3;
	cout << f4 << endl;

	cout << "Operator >=" << endl;
	cout << "Varsta fermier 2: " << f2.getVarsta() << ", Varsta fermier 3: " << f3.getVarsta() << endl;
	if (f2 >= f3) {
		cout << "Fermierul 2 are o varsta mai mare sau egala decat Fermierul 3" << endl;
	}
	else
		cout << "Fermierul 2 are o varsta mai mica decat Fermierul 3" << endl;
	cout << endl;

	cout << "Operator()" << "\nModificam pretul primului echipament" << endl;
	Fermier f8("George Paun", 24, 4, pretEchipament);
	f8(0, 850);
	f8.afisareFermier();

	cout << "Operator +=" << "\nAdaugam un nou echipament cu pretul 2500" << endl;
	f3 += 2500;
	f3.afisareFermier();

	cout << "Operator -=" << "\nEliminam echipamentul cu pretul 1300" << endl;
	f3 -= 1300;
	f3.afisareFermier();
	cout << endl;

	cout << "Afisam valorile obiectului f3 dupa modificari" << endl;

	cout << "ID: "<<f3.getId() << endl;

	f3.setNume("Sandra Diac");
	cout << "Nume: "<<f3.getNume() << endl;

	f3.setVarsta(32);
	cout << "Varsta: "<<f3.getVarsta() << endl;

	int pret[] = { 99, 760, 1150, 1600, 2300 };
	f3.setEchipament(5, pret);
	cout << "Numar echipamente: " << f3.getNrEchipamente() << endl;
	for (int i = 0; i < f3.getNrEchipamente(); i++) {
		cout << "Pret echipament " << i + 1 << ": " << f3.getPretEchipamente()[i] << endl;
	}
	cout << endl;
	f3.setNrFermieri(10);
	cout << "Numar Fermieri: "<<Fermier::getNrFermieri() << endl << endl;
	cout << endl << endl;


	cout << "Fisier Binar - Scrierea(serializarea) in fisiere binare" << endl;
	f3.serializare("Fermier.bin");
	cout << endl;

	cout << "Fisier Binar - Citirea(deserializarea) din fisiere binare" << endl;
	Fermier f7;
	cout << f7;
	f7.deserializare("Fermier.bin");
	cout << f7 << endl << endl;


	Fermier::resetNrFermieri();
	cout << "Resetare Fermieri; Reincepem inregistrarea fermierilor" << endl;

	Fermier f5;
	f5.afisareFermier();
	Fermier f6("Bogdan Antal", 41, 2, pretEchipament);
	f6.afisareFermier();

	cout << endl << endl << endl;



	cout << "LEGUMA" << endl;
	cout << endl;

	Leguma l1;
	Leguma l2("Rosie",8.5);
	Leguma l3("Ardei", 9, true);
	

	l1.afisareLeguma();
	l2.afisareLeguma();
	l3.afisareLeguma();
	cout << endl;

	cout << "Numar legume: ";
	cout << Leguma::getNrLegume() << endl;
	cout << endl;

	cout << "Constructorul de copiere" << endl;
	Leguma l4=l2;
	l4.afisareLeguma();
	cout << endl;

	cout << "Operator =" << endl;
	l4 = l3;
	cout << l4 <<endl;
	cout << endl;

	cout << "Crestem costul/kg cu 1" << endl << endl;
	cout << "Operatorul ++ pre incrementare" << endl;
	Leguma copie = ++l3;
	cout << copie << endl;
	cout << l3 << endl << endl;
	cout << "Operatorul ++ post incrementare" << endl;
	Leguma copie2 = l2++;
	cout << copie2 << endl;
	cout << l2 << endl << endl;

	cout << endl;

	cout << "Operator +" <<"\nCostul tuturor legumelor/kg"<< endl;
	Leguma l6 = l1+l2+l3;
	l6.afisareLeguma();
	cout << endl;

	cout << "Operator cast" <<"\nAfisam costul KG ca numar intreg" << endl;
	cout << (int)l6 << endl;
	cout << endl;
	cout << endl;


	cout << "Afisam valorile obiectului l3 dupa modificari" << endl;

	cout << "ID: "<<l3.getId() << endl;

	l3.setTipLeguma("Salata");
	cout << "Tip leguma: "<<l3.getTipLeguma() << endl;

	l3.setCostKG(6.5);
	cout << "Cost kg: "<<l3.getCostKG() << endl;

	l3.setGataDeRecoltat(false);
	cout << "Este gata de recoltat (0-NU, 1-DA): "<<l3.getGataDeRecoltat() << endl;

	l3.setNrLegume(100);
	cout <<"Numar legume: "<<Leguma::getNrLegume() << endl << endl;
	cout << endl;
	

	cout << "Schimbam stadiul recoltarii" << endl;
	Leguma leguma[] = { l1, l2, l3};
	for (int i = 0; i < 3; ++i) {
		schimbaStadiulRecoltarii(leguma[i]);
	}
	for (int i = 0; i < 3; ++i) {
		leguma[i].afisareLeguma();
	}

	cout << endl;
	cout << "Costul total al legumelor gata de recoltat: " << Leguma::calculCostTotal(leguma, 3) << " lei" << endl;
	cout << endl;

	cout << "Operator ->" <<"\nModificam cost/kg al legumei l3" << endl;
	cout << l3->getCostKG() << endl;
	cout << l3;
	cout << endl << endl;

	cout << "Fisiere Binare - Scrierea(serializarea) in fisier binar" << endl<< endl;
	l4.serializare("Leguma.bin");

	cout << endl << endl;



	cout << "Vectori de tipul celor 3 clase";
	const int numarFerme = 1; 
	Ferma ferme[numarFerme];
	const int numarFermieri = 2;
	Fermier fermieri[numarFermieri];
	const int numarLegume = 2;
	Leguma legume[numarLegume];

	cout << "Introduceti informatii despre ferme:\n";
	for (int i = 0; i < numarFerme; i++) {
		cout << "Ferma " << i + 1 << ":\n";
		cin >> ferme[i];
		cout << ferme[i];
	}

	cout << "Introduceti informatii despre fermieri:\n";
	for (int i = 0; i < numarFermieri; i++) {
		cout << "Fermier " << i + 1 << ":\n";
		cin >> fermieri[i];
		cout << fermieri[i];
	}

	cout << "Introduceti informatii despre legume:\n";
	for (int i = 0; i < numarLegume; i++) {
		cout << "Leguma " << i + 1 << ":\n";
		cin >> legume[i];
		cout << legume[i];
	}
	cout << endl << endl;

	cout << "Matricea Legume" << endl;

	const int randuri = 2; 
	const int coloane = 2;

	Leguma matriceLegume[randuri][coloane];

	for (int i = 0; i < randuri; i++) {
		for (int j = 0; j < coloane; j++) {
			cout << endl;
			cout << "Introduceti date pentru leguma din pozitia [" << i << "][" << j << "]:\n";
			cin >> matriceLegume[i][j];
			cout << matriceLegume[i][j];
		}
	}
	cout << endl << endl << endl;



	cout << "MAGAZIN - relatie HAS A" << endl<<endl;

	Magazin m;
	cout << m << endl;
	cout << endl;

	Leguma l10("Ciuperci", 13, false);
	Leguma l11("Morcovi", 3.5, true);

	Leguma vLegume[] = { l2,l3,l10 };
	Magazin m1("Green M", 3, 3200, 3, vLegume);
	cout << m1 << endl;
	cout << endl;

	cout << "Constructor de copiere" << endl;
	Magazin m2 = m;
	cout << m2 << endl;

	cout << "Operator = si operator <<" << endl;
	m2 = m1;
	cout << m2 << endl;

	cout << "Afisam valorile lui m2 dupa modificari" << endl;
	m2.setNume("Natural Market");
	cout << "Nume: "<<m2.getNume() << endl;
	m2.setNrVanzatori(3);
	cout <<"Numar vanzatori: "<< m2.getNrVanzatori() << endl;
	m2.setVenitZilnic(4400);
	cout << "Venit: "<<m2.getVenitZilnic() << endl;
	Leguma v2Legume[] = { l2,l3,l10,l11 };
	m2.setLegume(4, v2Legume);
	cout << "Numar legume: "<<m2.getNrLegume() << endl;
	cout << "Legume: " << endl;
	for (int i = 0; i < m2.getNrLegume(); i++) {
		cout << m2.getLeguma()[i];
	}
	cout << endl << endl;


	cout << "Operatorul ++ post incrementare" << endl;
	cout << "Crestem numarul vanzatorilor cu 1 si venitul cu 300" << endl << endl;
	Magazin mcopie = m1++;
	cout << mcopie << endl;
	cout << m1 << endl << endl;;

	cout << "Operator ()" << endl;
	cout << "Adaugam o leguma" << endl << endl;
	m1(l11);
	cout << m1 << endl;

	cout << "Fisier Text -- operatorul << de afisare/iesire in fisier text" << endl;
	ofstream fileOut("Magazin.txt", ios::out);
	fileOut << m1;
	fileOut.close();
}

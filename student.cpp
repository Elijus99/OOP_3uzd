#include "libraries.h"
#include "student.h"
#include "functions.h"
#include <algorithm>


vector<int> readNd(std::istream& in) 
{
	vector<int> nd;
	bool valid_input = false;
	int temp, j = 0;
	nd.clear();
	while (true) {
		try {
			do {
				cout << "Iveskite " << j + 1 << "-o namu darbo rezultata (Iveskite -1, kai noresite uzbaigti rezultatu vedima)" << endl;
				in >> temp;
				if (temp == -1) {
					throw - 1;
				}
				if (temp > -1 && temp < 11 && cin.fail() == false) {
					nd.push_back(temp);
					j++;
				}
				if (!(valid_input = cin.good())) {
					cout << "That input is invalid!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (temp > 10 || temp < -1) {
					cout << "That input is invalid!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					valid_input = false;
				}
			} while (!valid_input);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (...) {
			cout << "Homework input operation has been stopped!" << endl;
			break;
		}
	}
	return nd;
}

stud stud::readStudent(std::istream& in)
{
	stud Studentas;
	string x;
	cout << "Iveskite studento varda" << endl;
	in >> x;
	Studentas.setVardas(x);
	cout << "Iveskite studento pavarde" << endl;
	in >> x;
	Studentas.setPav(x);
	string choice;
	bool valid_input = false;
	double egzaminas;
	do {
		cout << "Ar norite pazymius bei egzamino rezultata ivesti, ar juos sugeneruoti automatiskai? (Iveskite 'i' arba 'g')" << endl;
		in >> choice;
		if (choice == "i" || choice == "I" || choice == "G" || choice == "g") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (choice != "i" || choice != "I" || choice != "G" || choice != "g");
	if (choice == "i" || choice == "I") {
		Studentas.setNd(readNd(cin));
		do {
			cout << "Iveskite studento egzamino rezultata" << endl;
			in >> egzaminas;
			Studentas.setEgz(egzaminas);
			if (!(valid_input = cin.good())) {
				cout << "That input is invalid!" << endl;
				in.clear();
				in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid_input);
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else {
		int n;
		cout << "Kiek pazymiu norite sugeneruoti?" << endl;
		in >> n;
		vector<int> nd;
		nd.reserve(n);
		cout << "Sugeneruoti pazymiai: ";
		for (int j = 0; j < n; j++)
		{
			nd.push_back(RandomNumber());
			cout << nd[j] << " ";
		}
		egzaminas = RandomNumber();
		Studentas.setNd(nd);
		Studentas.setEgz(egzaminas);
		cout << endl;
		cout << "Egzamino rezultatas: " << egzaminas;
		cout << endl;
	}
	return Studentas;
}

double galBalas(double egzaminas, string GType, std::vector<int> nd)
{
	double vidurkis = 0;
	for (int j = 0; j < nd.size(); j++)
	{
		vidurkis += nd[j];
	}
	vidurkis = division(vidurkis, nd.size());
	std::sort(nd.begin(), nd.end());
	double mediana;
	if (nd.size() > 0) {
		if (nd.size() % 2 == 1) {
			mediana = nd[nd.size() / 2];
		}
		else {
			mediana = (double)(nd[nd.size() / 2 - 1] + nd[nd.size() / 2]) / 2;
		}
	}
	else {
		mediana = 0;
	}
	double galutinis;
	if (GType == "v" || GType == "V") {
		galutinis = 0.4 * vidurkis + 0.6 * egzaminas;
	}
	else if (GType == "m" || GType == "M") {
		galutinis = 0.4 * mediana + 0.6 * egzaminas;
	}
	return galutinis;
}

bool compareAlphabet(const stud& a, const stud& b)
{
	return a.vardas() < b.vardas();
};
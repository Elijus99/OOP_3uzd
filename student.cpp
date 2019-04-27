#include "libraries.h"
#include "student.h"
#include "functions.h"
#include <algorithm>

stud::stud(std::istream& in) {
	stud temp = readStudent(in);
	vard = temp.vardas();
	pav = temp.pavarde();
	nd_ = temp.nd();
	egzaminas_ = temp.egzaminas();
};

stud::stud(const stud &x2) {
	vard = x2.vard;
	pav = x2.pav;
	nd_ = x2.nd_;
	egzaminas_ = x2.egzaminas_;
	galutinis_ = x2.galutinis_;
};

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
	cout << "Iveskite studento varda" << endl;
	in >> Studentas.vard;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Iveskite studento pavarde" << endl;
	in >> Studentas.pav;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string choice;
	bool valid_input = false;
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
		Studentas.nd_ = readNd(cin);
		do {
			cout << "Iveskite studento egzamino rezultata" << endl;
			in >> Studentas.egzaminas_;
			if (!(valid_input = cin.good())) {
				cout << "That input is invalid!" << endl;
				in.clear();
				in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (Studentas.egzaminas_ > 10 || Studentas.egzaminas_ < 0) {
				cout << "That input is invalid!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				valid_input = false;
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
		Studentas.nd_ = nd;
		Studentas.egzaminas_ = RandomNumber();
		cout << endl;
		cout << "Egzamino rezultatas: " << Studentas.egzaminas_;
		cout << endl;
	}
	return Studentas;
}

void stud::printInfo()
{
	cout << endl;
	cout << vard << " " << pav << endl;
	cout << "Namu darbu rezultatai: ";
	for (int i = 0; i < nd_.size(); i++) {
		cout << nd_[i] << " ";
	}
	cout << endl;
	cout << "Egzamino rezultatas: " << std::defaultfloat << egzaminas_ << endl;
	cout << "Galutinis balas: " << std::fixed << setprecision(2) << galutinis_ << endl;
	cout << endl;
}

double stud::galBalas(string GType)
{
	double vidurkis = 0;
	for (int j = 0; j < nd_.size(); j++)
	{
		vidurkis += nd_[j];
	}
	vidurkis = division(vidurkis, nd_.size());
	std::sort(nd_.begin(), nd_.end());
	double mediana;
	if (nd_.size() > 0) {
		if (nd_.size() % 2 == 1) {
			mediana = nd_[nd_.size() / 2];
		}
		else {
			mediana = (double)(nd_[nd_.size() / 2 - 1] + nd_[nd_.size() / 2]) / 2;
		}
	}
	else {
		mediana = 0;
	}
	double galutinis;
	if (GType == "v" || GType == "V") {
		galutinis = 0.4 * vidurkis + 0.6 * egzaminas_;
	}
	else if (GType == "m" || GType == "M") {
		galutinis = 0.4 * mediana + 0.6 * egzaminas_;
	}
	return galutinis;
}

bool compareAlphabet(const stud& a, const stud& b)
{
	return a.vardas() < b.vardas();
};
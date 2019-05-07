//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include <algorithm>
#include <limits>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

StudentBase::StudentBase(std::istream& in) {
    StudentBase temp = readStudent(in);
    vard = temp.vardas();
    pav = temp.pavarde();
    nd_ = temp.nd();
    egzaminas_ = temp.egzaminas();
};

StudentBase::StudentBase(const StudentBase& x2) {
    vard = x2.vard;
    pav = x2.pav;
    nd_ = x2.nd_;
    egzaminas_ = x2.egzaminas_;
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

StudentBase StudentBase::readStudent(std::istream& in)
{
    StudentBase Studentas;
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

bool compareAlphabet(const StudentBase& a, const StudentBase& b)
{
    return a.vardas() < b.vardas();
};


StudentDerived::StudentDerived(const string& GType, std::istream& in) : StudentBase(in), galutinis_(0)
{
    galutinis_ = galBalas(GType);
}

StudentDerived::StudentDerived(const StudentDerived& x2)
    : StudentBase(x2)
{
    galutinis_ = x2.galutinis_;
}

void StudentDerived::printInfo()
{
    cout << endl;
    cout << vard << " " << pav << endl;
    cout << "Namu darbu rezultatai: ";
    for (int i : nd_)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Egzamino rezultatas: " << std::defaultfloat << egzaminas_ << endl;
    cout << "Galutinis balas: " << std::fixed << setprecision(2) << galutinis_ << endl;
    cout << endl;
}

double StudentDerived::galBalas(const string& GType)
{
    double vidurkis = 0;
    for (int j : nd_)
    {
        vidurkis += j;
    }
    vidurkis = division(vidurkis, nd_.size());
    std::sort(nd_.begin(), nd_.end());
    double mediana;
    if (!nd_.empty()) {
        if (nd_.size() % 2 == 1) {
            mediana = nd_[nd_.size() / 2];
        }
        else {
            mediana = double(nd_[nd_.size() / 2 - 1] + nd_[nd_.size() / 2]) / 2;
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

int RandomNumber()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution <int> gen(1, std::nextafter(10, DBL_MAX));
    return gen(mt);
}

double division(int a, int b)
{
    if (b == 0) {
        return 0;
    }
    return (double(a) / b);
}

void SortToGroups(std::vector<StudentDerived>& ls, std::vector<StudentDerived>& vargs)
{
    for (auto& l : ls)
    {
        if (l.galutinis() < 5.0) {
            vargs.push_back(l);
        }
    }
    ls.erase(std::remove_if(
        ls.begin(), ls.end(),
        [](const StudentDerived & x) {
            return x.galutinis() < 5.0;
        }), ls.end());
}

void generate(int n,const string& GType, std::vector<StudentDerived>& ls)
{
    StudentDerived student;
    for (int i = 0; i < n; i++)
    {
        student.setVardas("Vardas" + std::to_string(i + 1));
        student.setPav("Pavarde" + std::to_string(i + 1));
        vector<int> nd;
        nd.clear();
        for (int j = 0; j < 5; j++)
        {
            nd.push_back(RandomNumber());
        }
        student.setNd(nd);
        double egzaminas = RandomNumber();
        student.setEgz(egzaminas);
        student.setGal(student.galBalas(GType));
        ls.push_back(student);
        student.clearNd();
    }
}

//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
using std::string;
using std::vector;

class StudentBase {
protected:
    string vard;
    string pav;
    std::vector<int> nd_;
    double egzaminas_;
    StudentBase() : vard(""), pav(""), egzaminas_(0) {} //default constructor
    StudentBase(std::istream& in); //constructor
public:
    StudentBase(const StudentBase& x2); //copy constructor
    StudentBase& operator=(const StudentBase& other) {
        this->vard = other.vard;
        this->pav = other.pav;
        this->nd_ = other.nd_;
        this->egzaminas_ = other.egzaminas_;
        return *this;
    }; //copy assignment operator
    ~StudentBase() = default; //default destructor

    void setVardas(string name) { vard = name; }
    void setPav(string surname) { pav = surname; }
    void setEgz(double egzaminas) { egzaminas_ = egzaminas; }
    void setNd(vector<int> nd) { nd_ = nd; }
    void clearNd() { nd_.clear(); }
    inline string vardas() const { return vard; }
    inline string pavarde() const { return pav; }
    inline double egzaminas() const { return egzaminas_; }
    inline std::vector<int> nd() const { return nd_; }
    StudentBase readStudent(std::istream& in);
};

class StudentDerived : public StudentBase
{
private:
    double galutinis_;
public:
    StudentDerived() : galutinis_(0) {}
    StudentDerived(const string& GType, std::istream& in);
    StudentDerived(const StudentDerived& x2);
    StudentDerived& operator=(const StudentDerived& other) {
        this->vard = other.vard;
        this->pav = other.pav;
        this->nd_ = other.nd_;
        this->egzaminas_ = other.egzaminas_;
        this->galutinis_ = other.galutinis_;
        return *this;
    };
    ~StudentDerived() = default;
    void setGal(double gal) { galutinis_ = gal; }
    inline double galutinis() const { return galutinis_; }
    void printInfo();
    double galBalas(const string& GType);
};

bool compareAlphabet(const StudentBase& a, const StudentBase& b);
int RandomNumber();
double division(int a, int b);
void SortToGroups(std::vector<StudentDerived>& ls, std::vector<StudentDerived>& vargs);
void generate(int n, const string& GType, std::vector<StudentDerived>& ls);

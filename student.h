#pragma once
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "libraries.h"

class stud {
private:
	string vard;
	string pav;
	std::vector<int> nd_;
	double egzaminas_;
	double galutinis_;
public:
	stud() : egzaminas_(0) {} //default constructor
	stud(std::istream& in); //constructor
	stud(const stud &x2); //copy constructor
	stud& operator=(const stud& other) {
		this->vard = other.vard;
		this->pav = other.pav;
		this->nd_ = other.nd_;
		this->egzaminas_ = other.egzaminas_;
		this->galutinis_ = other.galutinis_;
		return *this;
	}; //copy assignment operator
	~stud() = default; //default destructor

	void setVardas(string name) { vard = name; }
	void setPav(string surname) { pav = surname; }
	void setEgz(double egzaminas) { egzaminas_ = egzaminas; }
	void setNd(vector<int> nd) { nd_ = nd; }
	void setGal(double gal) { galutinis_ = gal; }
	void clearNd() { nd_.clear(); }
	inline string vardas() const { return vard; }
	inline string pavarde() const { return pav; }
	inline double egzaminas() const { return egzaminas_; }
	inline std::vector<int> nd() const { return nd_; }
	inline double galutinis() const { return galutinis_; }
	stud readStudent(std::istream& in);
	void printInfo();
	double galBalas(string GType);
};

bool compareAlphabet(const stud& a, const stud& b);

#endif

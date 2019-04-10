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
	stud() {
		egzaminas_ = 0; 
	}
	stud(std::istream& in) {
		stud temp = readStudent(in);
		vard = temp.vardas();
		pav = temp.pavarde();
		nd_ = temp.nd();
		egzaminas_ = temp.egzaminas();
	};
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
};

double galBalas(double egzaminas, string GType, std::vector<int> nd);
bool compareAlphabet(const stud& a, const stud& b);

#endif

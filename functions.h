#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "libraries.h"
#include "student.h"
void ivedimas(string &GType, std::vector<stud> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
void isvedimas(std::vector<stud> ls, std::vector<stud> vargs, int VSize, int PSize, string GType);
bool exist(string fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::vector<stud> &ls);
void SortToGroups(std::vector<stud> &ls, std::vector<stud> &vargs);
void InputFromFiles(string fileName, int &VSize, int &PSize, std::vector<stud> &ls, string GType);
void OutputToFiles(std::vector<stud> &ls, std::vector<stud> vargs,string GType, int VSize, int PSize);

#endif
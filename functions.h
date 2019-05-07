#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "student.h"
#include "StudentDerived.h"
void ivedimas(string &GType, std::vector<StudentDerived> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
void isvedimas(const std::vector<StudentDerived>& ls, const std::vector<StudentDerived>& vargs, int VSize, int PSize, const string &GType);
bool exist(const string &fileName);
double division(int a, int b);
int RandomNumber();
void generate(int n, const string &OutputFileName, const string &GType, std::vector<StudentDerived> &ls);
void SortToGroups(std::vector<StudentDerived> &ls, std::vector<StudentDerived> &vargs);
void InputFromFiles(const string &fileName, int &VSize, int &PSize, std::vector<StudentDerived> &ls, const string &GType);
void OutputToFiles(std::vector<StudentDerived> &ls, const std::vector<StudentDerived>& vargs, const string& GType, int VSize, int PSize);

#endif
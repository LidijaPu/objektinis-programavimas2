#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED

#include "mylib.h"
#include "stud.h"


void generuotiStudentuDuomenis(const string& failoPavadinimas, int kiekis);
void rusiuotiStudentus(const string& failoPavadinimas, int pasirinkimas, int rusiuotiPagal, const string& filePrefix, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai);
void surusioti_failai(vector<Studentas>& studentai, const string& failoPavadinimas);
bool palyginimas_vardas(const Studentas& a, const Studentas& b);
void rusiavimas_vardas(vector<Studentas>& studentai);
bool palyginimas_pavarde(const Studentas& a, const Studentas& b);
void rusiavimas_pavarde(vector<Studentas>& studentai);
bool palyginimas_pazimys(const Studentas& a, const Studentas& b);
void rusiavimas_pazimys(vector<Studentas>& studentai);
void matuotiVeikimoGreiti(const string& failoPavadinimas, int kiekis, int pasirinkimas, int rusiuotiPagal);




#endif
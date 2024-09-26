#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "mylib.h"


struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
};

void isvestis(const vector<Studentas>& studentai, int pasirinkimas);
double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas);
double galutineMediana(vector<int> namu_darbai, int egzaminas);
void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai);
void generuotiAtsitiktiniusRezultatus(Studentas& s);
bool palyginimas(const Studentas& a, const Studentas& b);
void rusiavimas(vector<Studentas>& studentai);

#endif

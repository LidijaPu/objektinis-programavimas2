#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "mylib.h"
#include "stud.h"
#include "failai.h"

void isvestisList(const list<Studentas>& studentaiList, int pasirinkimas);
void nuskaitytiIsFailoList(const string& name, list<Studentas>& studentaiList, int pasirinkimas);
void rusiavimasList(list<Studentas>& studentaiList);
void rusiuotiStudentusList(const string& failoPavadinimas, int pasirinkimas, int rusiuotiPagal, const string& filePrefix,
    list<Studentas>& vargsiukaiList, list<Studentas>& kietiakiaiList);
void surusioti_failaiList(list<Studentas>& studentaiList, const string& failoPavadinimas);
void rusiavimas_vardasList(list<Studentas>& studentaiList);
void rusiavimas_pavardeList(list<Studentas>& studentaiList);
void rusiavimas_pazimysList(list<Studentas>& studentaiList);
void matuotiVeikimoGreitiList(const string& failoPavadinimas, int kiekis, int pasirinkimas, int rusiuotiPagal);

#endif

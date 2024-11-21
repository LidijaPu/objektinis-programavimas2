#ifndef STUD_H
#define STUD_H

#include "mylib.h";


class Studentas {
private:
    string vardas_;
    string pavarde_;
    int egzaminas_;
    vector<int> nd_;
    double galutinis_;

public:
    Studentas() : vardas_(""), pavarde_(""), egzaminas_(0), galutinis_(0.0) {}

    Studentas(const string& vardas, const string& pavarde, const vector<int>& namu_darbai, int egzaminas)
        : vardas_(vardas), pavarde_(pavarde), nd_(namu_darbai), egzaminas_(egzaminas), galutinis_(0.0) {}


    ~Studentas() {
        // std::cout << "Studentas " << vardas_ << " " << pavarde_ << " sunaikintas." << std::endl;
    }


    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    const vector<int>& getNamuDarbai() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinis() const { return galutinis_; }


    void setGalutinis(double g) { galutinis_ = g; }
    void setNamuDarbai(const vector<int>& nd) { nd_ = nd; }
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }


    static double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas);
    static double galutineMediana(vector<int> namu_darbai, int egzaminas);
};


void isvestis(const vector<Studentas>& studentai, int pasirinkimas);
void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai);
void generuotiAtsitiktiniusRezultatus(Studentas& s);
bool palyginimas(const Studentas& a, const Studentas& b);
void rusiavimas(vector<Studentas>& studentai);

#endif

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
        : vardas_(vardas), pavarde_(pavarde), nd_(namu_darbai), egzaminas_(egzaminas) {
        galutinis_ = galutinisVidurkis(nd_, egzaminas_);
    }

    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), egzaminas_(other.egzaminas_),
        nd_(other.nd_), galutinis_(other.galutinis_) {}

    Studentas& operator=(const Studentas& other) {
        if (this == &other) return *this;
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinis_ = other.galutinis_;
        return *this;
    }

    ~Studentas() {
        nd_.clear();
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


 friend ostream& operator<<(ostream& out, const Studentas& s) {
     if (&out == &cout) {
         out << "Vardas: " << s.vardas_ << ", Pavarde: " << s.pavarde_ << "\n";
         out << "Egzaminas: " << s.egzaminas_ << "\n";
         out << "Namu darbu pazymiai: ";
         for (int nd : s.nd_) out << nd << " ";
         out << "\nGalutinis: " << fixed << setprecision(2) << s.galutinis_ << "\n";
     }
     else {
         out << s.vardas_ << " " << s.pavarde_ << " " << s.egzaminas_ << " ";
         for (int nd : s.nd_) out << nd << " ";
     }
     return out;
 }





};


void isvestis(const vector<Studentas>& studentai, int pasirinkimas);
void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai);
void generuotiAtsitiktiniusRezultatus(Studentas& s);
bool palyginimas(const Studentas& a, const Studentas& b);
void rusiavimas(vector<Studentas>& studentai);

#endif

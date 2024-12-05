#ifndef STUD_H
#define STUD_H

#include "mylib.h";

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() {}

    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }

    virtual void isvestiInformacija() const = 0; 
};



class Studentas : public Zmogus {
private:
    vector<int> nd_;
    int egzaminas_;
    double galutinis_;

public:
    Studentas() : Zmogus(), egzaminas_(0), galutinis_(0.0) {}

    Studentas(const string& vardas, const string& pavarde, const vector<int>& namu_darbai, int egzaminas)
        : Zmogus(vardas, pavarde), nd_(namu_darbai), egzaminas_(egzaminas) {
        galutinis_ = galutinisVidurkis(nd_, egzaminas_);
    }
 

    Studentas(const Studentas& other)
        : Zmogus(other), nd_(other.nd_), egzaminas_(other.egzaminas_), galutinis_(other.galutinis_) {}

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
    }



    const vector<int>& getNamuDarbai() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinis() const { return galutinis_; }

    void setGalutinis(double g) { galutinis_ = g; }
    void setNamuDarbai(const vector<int>& nd) { nd_ = nd; }
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }

    void isvestiInformacija() const override {
        cout << "Studentas: " << vardas_ << " " << pavarde_
            << ", galutinis balas: " << galutinis_ << endl;
    }

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
            out << left << setw(15) << s.pavarde_
                << setw(15) << s.vardas_;
            for (int nd : s.nd_) {
                out << setw(5) << nd;
            }
            out << setw(10) << s.egzaminas_;
        }
        return out;
    }



    friend istream& operator>>(istream& in, Studentas& s) {
        if (&in == &cin) {
            cout << "Iveskite studento pavarde: ";
        }
        in >> s.pavarde_;

        if (&in == &cin) {
            cout << "Iveskite studento varda: ";
        }
        in >> s.vardas_;

        if (&in == &cin) {
            cout << "Iveskite namu darbu balus (ivesti neigiama skaiciu, norint baigti):\n";
        }
        s.nd_.clear();
        int balas;
        while (in >> balas && balas >= 0) {
            s.nd_.push_back(balas);
            if (&in == &cin) {
                cout << "Namu darbu balas: ";
            }
        }

        if (&in == &cin) {
            cout << "Iveskite egzamino bala: ";
        }
        in.clear();
        in >> s.egzaminas_;

        s.galutinis_ = Studentas::galutinisVidurkis(s.nd_, s.egzaminas_);

        return in;
    }




    static Studentas generuotiStudentuDuomenis() {
        Studentas s;
        s.vardas_ = "Vardas" + to_string(rand() % 100 + 1);
        s.pavarde_ = "Pavarde" + to_string(rand() % 100 + 1);
        s.egzaminas_ = rand() % 10 + 1;

        for (int i = 0; i < 3; i++) {
            s.nd_.push_back(rand() % 10 + 1);
        }

        s.galutinis_ = Studentas::galutinisVidurkis(s.nd_, s.egzaminas_);
        return s;
    }


    static vector<Studentas> nuskaitytiIsFailo(const string& failoVardas) {
        ifstream failas(failoVardas);
        vector<Studentas> studentai;

        if (!failas) {
            cerr << "Klaida: Nepavyko atidaryti failo '" << failoVardas << "'.\n";
            return studentai;
        }

        string praleistiEilute;
        getline(failas, praleistiEilute);
        Studentas s;
        while (failas >> s) {
            studentai.push_back(s);
        }

        if (failas.bad()) {
            cerr << "Klaida: Failo skaitymo metu įvyko klaida.\n";
        }

        failas.close();
        return studentai;
    }


    static void rasytiIFaila(const vector<Studentas>& studentai, const string& failoVardas) {
        ofstream failas(failoVardas);
        if (!failas) {
            cerr << "Nepavyko sukurti failo: " << failoVardas << endl;
            return;
        }

        failas << left << setw(15) << "Pavarde"
            << setw(15) << "Vardas"
            << setw(5) << "ND1"
            << setw(5) << "ND2"
            << setw(5) << "ND3"
            << setw(10) << "Egzaminas" << endl;

        for (const auto& s : studentai) {
            failas << s << endl;
        }

        failas.close();
    }
};

void isvestis(const vector<Studentas>& studentai, int pasirinkimas);
void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai);
void generuotiAtsitiktiniusRezultatus(Studentas& s);
bool palyginimas(const Studentas& a, const Studentas& b);
void rusiavimas(vector<Studentas>& studentai);

#endif

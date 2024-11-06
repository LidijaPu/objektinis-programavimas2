#include "stud.h"
#include "failai.h"


void atmintis(const vector<Studentas>& v, const string& name) {
    size_t memory_in_bytes = v.capacity() * sizeof(Studentas);
    cout << "Naudojama atmintis " << name << ": " << memory_in_bytes << " baitai" << endl;
}

void generuotiStudentuDuomenis(const string& failoPavadinimas, int kiekis) {
    ofstream failas(failoPavadinimas);

    failas << left
        << setw(15) << "Pavarde"
        << setw(15) << "Vardas"
        << setw(6) << "ND1"
        << setw(6) << "ND2"
        << setw(6) << "ND3"
        << setw(6) << "ND4"
        << setw(6) << "ND5"
        << setw(10) << "Egzaminas"
        << endl;

    for (int i = 1; i <= kiekis; ++i) {
        Studentas s;
        s.vardas = "Vardas" + to_string(i);
        s.pavarde = "Pavarde" + to_string(i);

        generuotiAtsitiktiniusRezultatus(s);


        failas << left
            << setw(15) << s.pavarde
            << setw(15) << s.vardas;

        for (const auto& pazymys : s.namu_darbai) {
            failas << setw(6) << pazymys;
        }

        failas << setw(10) << s.egzaminas << endl;
    }

    failas.close();
}


void nuskaitytiStudentus(const string& failoPavadinimas, vector<Studentas>& studentai, int pasirinkimas) {
    ifstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string vardas, pavarde;
    vector<int> namuDarbai(5);
    int egzaminas;
    string praleistiEilute;
    getline(failas, praleistiEilute);

    while (failas >> pavarde >> vardas >> namuDarbai[0] >> namuDarbai[1] >> namuDarbai[2] >> namuDarbai[3] >> namuDarbai[4] >> egzaminas) {
        Studentas s;
        s.vardas = vardas;
        s.pavarde = pavarde;
        s.namu_darbai = namuDarbai;
        s.egzaminas = egzaminas;
        s.galutinis = (pasirinkimas == 1) ? galutinisVidurkis(s.namu_darbai, s.egzaminas) : galutineMediana(s.namu_darbai, s.egzaminas);
        studentai.push_back(s);
    }
    failas.close();
}

void rusiuotiStudentus(vector<Studentas>& studentai, int pasirinkimas, int rusiuotiPagal, int strategija,
    vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai) {

    if (strategija == 1) {
        for (const auto& studentas : studentai) {
            if (studentas.galutinis < 5.0) {
                vargsiukai.push_back(studentas);
            }
            else {
                kietiakiai.push_back(studentas);
            }
        }
    }
    else if (strategija == 2) {
        auto it = remove_if(studentai.begin(), studentai.end(),
            [&vargsiukai](Studentas& studentas) {
                if (studentas.galutinis < 5.0) {
                    vargsiukai.push_back(studentas);
                    return true;
                }
                return false;
            });
        studentai.erase(it, studentai.end());
        kietiakiai = move(studentai);        

        vector<Studentas>().swap(studentai);
    }
    else if (strategija == 3) {
        auto it = stable_partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.galutinis < 5.0; });
        vargsiukai.assign(studentai.begin(), it);
        kietiakiai.assign(it, studentai.end());

        vector<Studentas>().swap(studentai);
    }

    if (rusiuotiPagal == 1) {
        rusiavimas_vardas(vargsiukai);
        rusiavimas_vardas(kietiakiai);
    }
    else if (rusiuotiPagal == 2) {
        rusiavimas_pavarde(vargsiukai);
        rusiavimas_pavarde(kietiakiai);
    }
    else if (rusiuotiPagal == 3) {
        rusiavimas_pazimys(vargsiukai);
        rusiavimas_pazimys(kietiakiai);
    }
    else {
        cout << "Neteisingas pasirinkimas." << endl;
    }
}




void surusioti_failai(vector<Studentas>& studentai, const string& failoPavadinimas) {
    ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        cerr << "Klaida: nepavyko sukurti failo " << failoPavadinimas << endl;
        return;
    }

    failas << left
        << setw(20) << "Pavarde"
        << setw(20) << "Vardas"
        << setw(10) << "Galutinis"
        << endl;


    for (const auto& studentas : studentai) {
        failas << left
            << setw(20) << studentas.pavarde
            << setw(20) << studentas.vardas
            << setw(10) << fixed << setprecision(2) << studentas.galutinis
            << endl;
    }

    failas.close();
}

bool palyginimas_vardas(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

void rusiavimas_vardas(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), palyginimas_vardas);
}

bool palyginimas_pavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
}

void rusiavimas_pavarde(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), palyginimas_pavarde);
}

bool palyginimas_pazimys(const Studentas& a, const Studentas& b) {
    return a.galutinis < b.galutinis;
}

void rusiavimas_pazimys(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), palyginimas_pazimys);
}

void matuotiVeikimoGreiti(const string& failoPavadinimas, int kiekis, int pasirinkimas, int rusiuotiPagal, int strategija) {
    cout << "Matuojamas veikimo greitis su failu: " << failoPavadinimas << "\n";

    auto total_start = high_resolution_clock::now();


    auto start = high_resolution_clock::now();
    vector<Studentas> studentai;
    nuskaitytiStudentus(failoPavadinimas, studentai, pasirinkimas);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << duration << "s\n";


    vector<Studentas> vargsiukai, kietiakiai;
    start = high_resolution_clock::now();
    rusiuotiStudentus(studentai, pasirinkimas, rusiuotiPagal, strategija, vargsiukai, kietiakiai);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Studentu rusiavimas i dvi grupes uztruko: " << fixed << setprecision(6) << duration << "s\n";

    start = high_resolution_clock::now();
    string vargsiukaiFailas = "vargsiukai_" + to_string(kiekis) + ".txt";
    surusioti_failai(vargsiukai, vargsiukaiFailas);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu irasymas i faila '" << vargsiukaiFailas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";

    start = high_resolution_clock::now();
    string kietiakiaiFailas = "kietiakiai_" + to_string(kiekis) + ".txt";
    surusioti_failai(kietiakiai, kietiakiaiFailas);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu irasymas i faila '" << kietiakiaiFailas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";

    auto total_end = high_resolution_clock::now();
    auto total_duration = duration_cast<microseconds>(total_end - total_start).count() / 1e6;
    cout << "Bendras uzduociu atlikimo laikas: " << fixed << setprecision(6) << total_duration << "s\n\n";

    atmintis(studentai, "studentai");
    atmintis(vargsiukai, "vargsiukai");
    atmintis(kietiakiai, "kietiakiai");
    cout << "\n" << endl;
}



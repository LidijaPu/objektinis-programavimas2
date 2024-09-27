#include "stud.h"

void isvestis(const vector<Studentas>& studentai, int pasirinkimas) {
    cout << left << setw(15) << "Pavarde"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Galutinis (Vid.)"
        << left << setw(20) << "Galutinis (Med.)" << endl;

    cout << "---------------------------------------------------------------" << endl;

    for (const auto& s : studentai) {
        if (s.namu_darbai.empty()) {
            cerr << "Klaida: Studentas " << s.vardas << " " << s.pavarde << " neturi namu darbu balu." << endl;
            continue;
        }
        double galutinisVid = galutinisVidurkis(s.namu_darbai, s.egzaminas);
        double galutinisMed = galutineMediana(s.namu_darbai, s.egzaminas);

        cout << left << setw(15) << s.pavarde
            << left << setw(15) << s.vardas;

        if (pasirinkimas == 1) {
            cout << fixed << setprecision(2) << setw(20) << galutinisVid
                << setw(20) << "-" << endl;
        }
        else if (pasirinkimas == 2) {
            cout << setw(20) << "-"
                << fixed << setprecision(2) << setw(20) << galutinisMed << endl;
        }
    }
}

double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas) {
    if (namu_darbai.empty()) return 0.0;
    double sum = accumulate(namu_darbai.begin(), namu_darbai.end(), 0);
    double vidurkis = sum / namu_darbai.size();
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

double galutineMediana(vector<int> namu_darbai, int egzaminas) {
    if (namu_darbai.empty()) return 0.0;
    sort(namu_darbai.begin(), namu_darbai.end());
    double mediana;
    int dydis = namu_darbai.size();

    if (dydis % 2 == 0) {
        mediana = (namu_darbai[dydis / 2 - 1] + namu_darbai[dydis / 2]) / 2.0;
    }
    else {
        mediana = namu_darbai[dydis / 2];
    }

    return 0.4 * mediana + 0.6 * egzaminas;
}

void generuotiAtsitiktiniusRezultatus(Studentas& s) {
    int namuDarbaiCount = rand() % 10 + 1;
    cout << "Sugeneruoti " << namuDarbaiCount << " nam darbu balai: \n";
    for (int i = 0; i < namuDarbaiCount; i++) {
        int balas = rand() % 10 + 1;
        s.namu_darbai.push_back(balas);
        cout << balas << " ";
    }
    cout << endl;

    s.egzaminas = rand() % 10 + 1;
    cout << "Sugeneruotas egzamino ivertinimas: " << s.egzaminas << endl;
}

void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai) {
    try {
        ifstream failas(failoPavadinimas);

        if (!failas.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo!");
        }

        string eilute;
        getline(failas, eilute);  
    
        string vardas, pavarde;
        while (failas >> vardas >> pavarde) {
            Studentas s;
            s.vardas = vardas;
            s.pavarde = pavarde;
    
            int balas;
            vector<int> namuDarbai;
    
            
            while (failas >> balas) {
                if (balas == -1) { 
                    break;
                }
                namuDarbai.push_back(balas);
            }
    
            if (!namuDarbai.empty()) {
                s.egzaminas = namuDarbai.back();  
                namuDarbai.pop_back();  
            }
            else {
                throw runtime_error("Klaida faile: nerasta namu darbu arba egzamino balo.");
            }
    
            s.namu_darbai = namuDarbai;
            studentai.push_back(s);

            
            failas.clear();
        }
    
        failas.close();
    }
    catch (const ifstream::failure& e) {
    cerr << "Klaida: nepavyko nuskaityti failo. Priezastis: " << e.what() << endl;
    throw;
    }
     catch (const runtime_error& e) {
        cerr << "Klaida: " << e.what() << endl;
        throw;
    }
}


bool palyginimas(const Studentas& a, const Studentas& b) {
    if (a.pavarde == b.pavarde) {
        return a.vardas < b.vardas;
    }
    return a.pavarde < b.pavarde;
}

void rusiavimas(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), palyginimas);
}

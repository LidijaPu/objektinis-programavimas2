#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <fstream>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
};

double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas);
double galutineMediana(vector<int> namu_darbai, int egzaminas);
void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai);
void generuotiAtsitiktiniusRezultatus(Studentas& s);

int main() {
    vector<Studentas> studentai;
    int n, nd_kiekis;

     cout << "Ar norite įvesti duomenis ranka (1), skaityti iš failo (2), ar generuoti atsitiktinai (3)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "Įveskite studentų skaičių: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Įveskite studento " << i + 1 << " vardą: ";
            cin >> s.vardas;
            cout << "Įveskite studento " << i + 1 << " pavardę: ";
            cin >> s.pavarde;
    
           cout << "Įveskite namų darbų balus (norėdami baigti įvestį, įveskite neigiamą reikšmę):" << endl;

        while (true) {
            int rezultatas;
            cout << "Namų darbų balas: ";
            cin.clear();
            cin >> rezultatas;

            if (!cin || rezultatas < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break; 
            }
            s.namu_darbai.push_back(rezultatas);
        }

        cout << "Įveskite egzamino balą: ";
        cin >> s.egzaminas;
        studentai.push_back(s);
    }
  } else if (pasirinkimas == 2) {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(failoPavadinimas, studentai);

        
    } else if (pasirinkimas == 3) {
        cout << "Įveskite studentų skaičių: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Įveskite studento " << i + 1 << " vardą: ";
            cin >> s.vardas;
            cout << "Įveskite studento " << i + 1 << " pavardę: ";
            cin >> s.pavarde;

            generuotiAtsitiktiniusRezultatus(s);

            studentai.push_back(s);
        }
    }
    
    cout << "Ar norite skaičiuoti galutinį balą pagal vidurkį (1) ar medianą (2)?";
    cin >> pasirinkimas;
   
    cout << left << setw(15) << "Pavardė" 
         << left << setw(15) << "Vardas" ;
    if (pasirinkimas == 1){
        cout << left << setw(20) << "Galutinis (Vid.)"
             << left << setw(20) << "Galutinis (Med.)" << endl;
    } else if (pasirinkimas ==2) {
        cout << left << setw(20) << "Galutinis (Vid.)" 
             << left << setw(20) << "Galutinis (Med.)" << endl;
    }
    cout << "---------------------------------------------------------------" << endl;


    for (const auto& s : studentai) {
        double galutinis = galutinisVidurkis(s.namu_darbai, s.egzaminas);
        double galutinisMed = galutineMediana(s.namu_darbai, s.egzaminas);
        
        cout << left << setw(15) << s.pavarde 
             << left << setw(15) << s.vardas;
        
         if (pasirinkimas == 1) {
            cout << fixed << setprecision(2) << setw(20) << galutinisVid 
                 << setw(20) << "-" << endl;
        } else if (pasirinkimas == 2) {
            cout << setw(20) << "-" 
                 << fixed << setprecision(2) << setw(20) << galutinisMed << endl;
        }
    }
    
    return 0;
}

//---------------------------------------------------------

double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas) {
    double sum = 0;

    if (!namu_darbai.empty()) {
        for (int rezultatas : namu_darbai) {
            sum += rezultatas;
        }
        double vidurkis = sum / namu_darbai.size();  
        return 0.4 * vidurkis + 0.6 * egzaminas;     
    }
    return 0.6 * egzaminas;
}

double galutineMediana(vector<int> namu_darbai, int egzaminas) {
   sort(namu_darbai.begin(), namu_darbai.end());
    double mediana;
    int dydis = namu_darbai.size();
    
    if (dydis % 2 == 0) {
        mediana = (namu_darbai[dydis / 2 - 1] + namu_darbai[dydis / 2]) / 2.0;
    } else {
        mediana = namu_darbai[dydis / 2];
    }
    
    return 0.4 * mediana + 0.6 * egzaminas;
}

void generuotiAtsitiktiniusRezultatus(Studentas& s) {
    int namuDarbaiCount = rand() % 10 + 1;
    cout << "Sugeneruoti " << namuDarbaiCount << " namų darbų balai: \n";
    for (int i = 0; i < namuDarbaiCount; i++) {
        int balas = rand() % 10 + 1;
        s.namu_darbai.push_back(balas); 
        cout << rand() % 10 + 1<< " ";
    }
    cout << endl;

    s.egzaminas = rand() % 10 + 1; 
    cout << "Sugeneruotas egzamino įvertinimas: " << s.egzaminas  << endl;
}

void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai) {
    ifstream failas(failoPavadinimas);
    if (failas.is_open()) {
        string eilute;
        
        getline(failas, eilute);

        string vardas, pavarde;
        while (failas >> vardas >> pavarde) {
            Studentas s;
            s.vardas = vardas;
            s.pavarde = pavarde;
            
            int balas;
            while (failas >> balas) {
                s.namu_darbai.push_back(balas);
            }
            s.egzaminas = s.namu_darbai.back(); 
            s.namu_darbai.pop_back(); 

            studentai.push_back(s);
            failas.clear(); 
        }
        failas.close();
    } else {
        cout << "Nepavyko atidaryti failo!" << endl;
    }
}



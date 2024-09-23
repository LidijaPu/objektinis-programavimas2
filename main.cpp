#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
};

double galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas);
double galutineMediana(vector<int> namu_darbai, int egzaminas);

int main() {
    vector<Studentas> studentai;
    int n, nd_kiekis;

    cout << "Įveskite studentų skaičių: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Studentas s;
        cout << "Įveskite studento " << i + 1 << " vardą: ";
        cin >> s.vardas;
        cout << "Įveskite studento " << i + 1 << " pavardę: ";
        cin >> s.pavarde;

        cout << "Įveskite namų darbų kiekį: ";
        cin >> nd_kiekis;
        s.namu_darbai.resize(nd_kiekis);

        for (int j = 0; j < nd_kiekis; j++) {
            cout << "Įveskite namų darbų balą (" << j + 1 << "): ";
            cin >> s.namu_darbai[j];
        }

        cout << "Įveskite studento " << i + 1 << " egzamino balą: ";
        cin >> s.egzaminas;
        studentai.push_back(s);
    }

   
    cout << left << setw(15) << "Pavardė" 
         << left << setw(15) << "Vardas" 
         << left << setw(15) << "Galutinis (Vid.)" << endl;
         << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << "---------------------------------------------" << endl;


    for (const auto& s : studentai) {
        double galutinis = galutinisVidurkis(s.namu_darbai, s.egzaminas);
        double galutinisMed = galutineMediana(s.namu_darbai, s.egzaminas);
        
        cout << left << setw(15) << s.pavarde 
             << left << setw(15) << s.vardas 
             << fixed << setprecision(2) << setw(20) << galutinisVid 
             << setw(20) << galutinisMed << endl;
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



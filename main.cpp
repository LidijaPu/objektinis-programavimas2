#include "mylib.h"
#include "stud.h"

int main() {
    vector<Studentas> studentai;
    int n, pasirinkimas;

    cout << "Ar norite ivesti duomenis ranka (1), skaityti is failo (2), ar generuoti atsitiktinai (3)? ";
    while(!(cin>>pasirinkimas)||(pasirinkimas<1 || pasirinkimas > 3)){
        cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        
    if (pasirinkimas == 1) {
        cout << "Iveskite studentu skaiciu: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Klaida: Prasome ivesti tik skaiciu: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Iveskite studento " << i + 1 << " varda: ";
            cin >> s.vardas;
            cout << "Iveskite studento " << i + 1 << " pavarde: ";
            cin >> s.pavarde;
        
            cout << "Iveskite namu darbu balus (noredami baigti ivesti, iveskite neigiama skaiciu):" << endl;
            while (true) {
                int rezultatas;
                cout << "Namu darbu balas: ";
                cin >> rezultatas;
                if (rezultatas < 0) break;
                if (rezultatas >= 1 && rezultatas <= 10) s.namu_darbai.push_back(rezultatas);
                else cout << "Klaida: Prasome ivesti skaiciu tarp 1 ir 10." << endl;
            }
            cout << "Iveskite egzamino bala: ";
            while (!(cin >> s.egzaminas) || s.egzaminas < 1 || s.egzaminas > 10) {
                cout << "Klaida: Prasome ivesti skaicių nuo 1 iki 10: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            studentai.push_back(s);
        }
        int galutinis;
        cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
        while (!(cin >> galutinis) || (galutinis != 1 && galutinis != 2)) {
            cout << "Klaida: Prasome ivesti 1 arba 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        isvestis(studentai, galutinis); 
    }
    else if (pasirinkimas == 2) {
        string failoPavadinimas;
        cout << "Iveskite failo pavadinima: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(failoPavadinimas, studentai);
    }
    
    int galutinis;
    cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
    while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
        cout << "Klaida: Prasome ivesti 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    rusiavimas(studentai);
    isvestis(studentai, galutinis);

}

else if (pasirinkimas == 3) {
    vector<int> kiekiai = { 1000, 10000, 100000, 1000000, 10000000 };

    cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
    while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
        cout << "Klaida: Prasome ivesti 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int rusiuotiPagal;
    cout << "Ar norite rusiuoti studentus pagal varda (1), pavarde (2) ar pazymi (3)\n? ";
    while (!(cin >> rusiuotiPagal) || (rusiuotiPagal < 1 || rusiuotiPagal > 3)) {
        cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int kiekis : kiekiai) {
        string failoPavadinimas = "studentai_" + to_string(kiekis) + ".txt";
        matuotiVeikimoGreiti(failoPavadinimas, kiekis, pasirinkimas, rusiuotiPagal);  
    }
}

return 0;
}





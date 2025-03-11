# objektinis-programavimas



### Programos įdiegimo ir paleidimo instrukcija
**1.** Atsisiųskite V1.0 releas'o zip failą.
<br> **2.** Sukurkite direktorija su pavadinimu *"StudentuRusiavimas"* ir išskleiskite į ją atsiųstą zip failą.
<br> **3.** Jei dar neturite įdiekite CMake: [cmake.org](https://cmake.org/download/).
<br> **4.** Direktorijoje *"build"* (rasite tarp atsiustų failų), atidarykite terminalą ir komandinėje eilutėje įrašykite ***"cmake"*** arba jei idiegtas MinGW rasykite ***"cmake -G "MinGW Makefiles" .."***.
<br> **5.** Po to terminalo komandinėje eilutėje įrašykite ***"make"*** arba ***"mingw32-make"** ir *"build"* direktorijoje atsiras *"StudentuRusiavimas.exe"* failas. Programą galite paleisti paspaudus ant jo arba terminalo komandinėje eilutėje įrašius ***"./Sort.exe"**.
<br> **Pastaba.** Pirmą kartą paleidžaint programą ir norėdami atlinkti analizę būtina sugeneruoti naujus failus.


### Naudojimo instrukcija
**1.** Pasirinkite ar norite Paleisti programą (1) ar Demonstruoti programą (2).
**2.** Pasirinkite konteinerį: vector (1) ar list (2).
<br> **3.** Ar norite ivesti duomenis ranka (1), skaityti is failo (2), ar generuoti atsitiktinai/matuoti laika (3)?
* (1) Įveskite studentų skaičių; Įveskite studento vardą, pavardę; Įveskite namų darbu balus (įvesti neigiamą skaičiu, norint baigti); Įveskite egzamino balą; Pasirinkite kaip skaičiuoti galutinį balą, pagal vidurkį (1) ar medianą (2).
* (2) Įveskite failo pavadinimą; Pasirinkite kaip skaičiuoti galutinį balą, pagal vidurkį (1) ar medianą (2).
* (3) Pasirinkite ar norite generuoti naujus failus (1) ar naudoti jau sugeneruotus failus (2); Kaip skaičiuoti galutinį balą, pagal vidurkį (1) ar medianą (2); Kaip rušiuoti studentus pagal vardą (1), pavardę (2) ar pažymį (3)?; Kurią strategiją naudoti (1, 2, 3).



### Programos versijos ir analizė
### _V1.1_
1.0 versijos failai buvo paimti kaip pagrindas ir pakoreguoti taip, kad duomenų tipas "struct" pakeistas į "class" tipą, o fukcijos pakoreguotos pagal reikalavimus. 

**Bendro vykdymo laiko palyginimas**
| Versija            | Realizacija  | Strategija  | **100000**  | **1000000**  |
|----------------------------|-------------|-------------|-------------|--------------|
| **V1.0**      | struct  | 1 | 0.769003s  | 7.896289s    |
| **V1.1**      | class   |1  | 0.792843s  | 8.092771s    | 

<br>

**Eksperimentinė analizė atlikta, įvertinant kompiliatoriaus optimizavimo lygius, nurodytus flag'ais: O1, O2, O3.**
|              | **V1.0 exe failo dydis**    | **V1.0 greitis 100000**   | **V1.0 greitis 1000000**  | **V1.1 exe failo dydis**  | **V1.1 greitis 100000** | **V1.1 greitis 1000000** |
|----------------------------|-------------|-------------|-------------|--------------|--------------|--------------|
| **O1**      | 84 KB  | 0.742152s |  7.722517s |  83 KB  |  0.856720s  | 8.180151s |
| **O2**      |  99 KB | 0.827442s  | 8.589541s |  97 KB  | 0.787644s  | 8.041095s |
| **O3**       | 101 KB  |  0.733198s  | 7.443694s  |  100 KB   | 0.880193s | 8.220264s|



### _V1.2_
V1.2 programoje įgyvendinti visi Rule of Three reikalavimai, taip pat perdengti įvesties ir išvesties operatoriai.

**Realizuota "Rule of Three"**
- **Destruktorius**: Užtikrina, kad studento objektui sunaikinus, būtų atlaisvinta atmintis, kurią užima namų darbų balų vektorius.

- **Kopijavimo konstruktorius**: Naudojamas kopijuoti duomenis iš vieno Studentas objekto į kitą.

- **Priskyrimo operatorius**: Leidžia tinkamai priskirti vieno studento duomenis kitam studentui, tuo pačiu išvalant seną informaciją.
  
<br> Be to programoje padarytas atskiras pasirinkimas demonstracijai, noritiems pamatyti kaip veikia šie metodai.


### _V1.5_
Versijoje 1.5 buvo sukurta bazinė abstrakti klasė **Zmogus**, kuri atitinka visus "Rule of Three" reikalavimus. Taip pat **Studentas** tapo išvestine klase, paveldinčia bazinės klasės savybes.


Kadangi **Zmogus** yra abstrakti klasė, jos objektų kurti negalima. Objekto kūrimas galimas tik per **Studentas** klasę, kuri paveldi iš **Zmogus**. Studentas klasė realizuoja visas bazinės klasės savybes bei turi savo specifinius metodus.

### _V2.0_
Naudojant **Doxygen**, sukurta programos dokumentacija, **html** ir **pdf** formatais Taip pat atlikti **Unit testai**, naudojant **Google Test** framework'ą, kuriais patikrinta funkcijos **galutinisVidurkis** skaičiavimo tikslumą ir **Studentas** klasės konstruktoriaus veikimą, užtikrinant, kad reikšmės (vardas, pavardė, galutinis pažymys) priskiriamos teisingai. 

```cpp
// Testuoja funkcijos galutinisVidurkis skaičiavimo tikslumą
TEST(StudentasTest, GalutinisVidurkis) {
    vector<int> nd = { 8, 9, 10 };
    int egzaminas = 9;          
    ASSERT_NEAR(Studentas::galutinisVidurkis(nd, egzaminas), 9, 0.01);
}

// Testuoja Studentas klasės konstruktoriaus veikimą
TEST(StudentasTest, SukurimoTestas) {
    Studentas s("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
    ASSERT_NEAR(s.getGalutinis(), 9, 0.01);
}
```

![image](https://github.com/user-attachments/assets/1eebf326-70e0-4572-90b4-34899202f400)



### Kompiuterio parametrai:  
CPU - Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz  
RAM - 12GB  
HDD - 476GB  





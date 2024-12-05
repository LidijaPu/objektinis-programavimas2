# objektinis-programavimas

Naudojimo, įdiegimo ir paleidimo instrukcija parengta čia: https://github.com/LidijaPu/objektinis-programavimas2/blob/v1.0/README.md

### _V1.5_
Versijoje 1.5 buvo sukurta bazinė abstrakti klasė **Zmogus**, kuri atitinka visus "Rule of Three" reikalavimus. Taip pat **Studentas** tapo išvestine klase, paveldinčia bazinės klasės savybes.


Kadangi **Zmogus** yra abstrakti klasė, jos objektų kurti negalima. Objekto kūrimas galimas tik per **Studentas** klasę, kuri paveldi iš **Zmogus**. Studentas klasė realizuoja visas bazinės klasės savybes bei turi savo specifinius metodus.

Bandant sukurti Zmogus klasės objektą, programa nesukompiliuos, o kompiliatorius pateiks klaidos pranešimą:
![image](https://github.com/user-attachments/assets/11650c31-b69d-4e25-8769-7f8a1ee38b31)

Norėdami pamatyti šią klaidą, galite iš main.cpp failo pašalinti šį komentarą (33 eilutė):
//      Zmogus zmogus("Vardas", "Pavarde");


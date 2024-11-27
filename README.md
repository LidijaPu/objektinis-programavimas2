# objektinis-programavimas

Naudojimo, įdiegimo ir paleidimo instrukcija parengta čia: https://github.com/LidijaPu/objektinis-programavimas2/blob/v1.0/README.md

### _V1.2_
V1.2 programoje įgyvendinti visi Rule of Three reikalavimai, taip pat perdengti įvesties ir išvesties operatoriai.

**Realizuota "Rule of Three"**
- **Destruktorius**: Užtikrina, kad studento objektui sunaikinus, būtų atlaisvinta atmintis, kurią užima namų darbų balų vektorius.

- **Kopijavimo konstruktorius**: Naudojamas kopijuoti duomenis iš vieno Studentas objekto į kitą.

- **Priskyrimo operatorius**: Leidžia tinkamai priskirti vieno studento duomenis kitam studentui, tuo pačiu išvalant seną informaciją.

```cpp
Studentas originalus("Vardas", "Pavarde", {10, 9, 8}, 9);
Studentas kopija = originalus; // Kopijuoja originalo duomenis
Studentas priskirtas;
priskirtas = originalus; // Priskiria originalo duomenis
```
![image](https://github.com/user-attachments/assets/3ca22657-d731-46ea-bbc0-42360d7b1e07)




**Perdegti įvesties/išvesties operatoriai**<br>
**_Įvesties_**
- Įvestis rankiniu būdu (cin)
   
![image](https://github.com/user-attachments/assets/8b28c0a0-b651-42d8-9fbe-49d64fe08c87)

- Duomenų generavimas (Studentas::generuotiStudentuDuomenis())

![image](https://github.com/user-attachments/assets/9d0e3c99-74f5-4e9b-8306-6bdd11a55664)

- Studentų duomenų nuskaitymas iš failo

![image](https://github.com/user-attachments/assets/6d75d8da-a050-4abc-ab45-45f467e0797a)

**_Išvesties_**
- Išveda duomenis į ekraną
- Išveda duomenis į failą


<br>
<br>
<br>

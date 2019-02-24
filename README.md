# 2 užduotis. Duomenų apdorojimas
## Programos tikslas
Programa nuskaito mokinio vardą, pavardę,egzamino įvertinimą ir namų darbų įvertinimus, tuomet, paskaičiavusi galutinį studento pažymį, programa lentelėje išveda visų studentų galutinius pažymius, vardus ir pavardes.
## Makefile komandos  
-make paleidimas: sukuria programos paleidimo failą `programa.exe` (jeigu nebūna sukurtas prieš tai, tuomet ši komanda sukuria ir function.o failą).  
-make funkcijos: sukurią failą `function.o`.   
-make valymas: ištrina programos paleidimo failą `programa.exe` ir visus failus su pabaiga `.o`.  
## Programos paleidimas   
-Įjungti terminalą (komandinę eilutę) ir įvesti komandą `make paleidimas`.   
-Tuomet, parašyti komandą `./programa` (arba paleisti sukurtą faila `programa.exe`).  
## Išvedimo pavyzdys
```shell
Vardas Pavardė  Galutinis
------------------------
Matas  Čenys   8.80
------------------------
```
## Programos naudojimas
Norint, kad programa nuskaitytų duomenis iš failo, reikia papildyti prie programos prisegtą failą „kursiokai.txt“. Pirmoji failo eilute yra skirta stulpelių aprašymams, todėl į ją negalima įrašyti duomenų, o nuo antrosios eilutės galima įrašinėti duomenis. Lygiuotė ar vienodas skaičius pažymių yra nebūtini (vienas studentas gali turėti daugiau įvertinimų už kitus ir atvirkščiai), tačiau egzamino įvertinimas turi būti paskutinis skaičius eilutėje.
Tekstinio failo pavyzdys:
```shell
Vardas   Pavarde   ND1   ND2   ND3   Egzaminas
Matas    Cenys     8     9     6     9
Arvydas  Sabonis   10    7           10
```
## Versijų istorija
### [v0.3]() - (2019-02-24)  
**Pridėta**  
-makefile patogesniam programos paleidimui ir naudojimui.  
-header failas, kuriame yra laikomos visų funkcijų deklaracijos ir struktūros aprašymas.  
-function.cpp failas, kuriame laikomi visų funkcijų aprašymai.  
**Koreguota**  
-Programa papildyta  įvesties apsaugomis (pvz. programa nutraukia darbą jei neranda tinkamo .txt failo, galutinį mokinio pažymį padaro 0, jeigu nėra įvesti namų darbų įvertinimai).  
-Patobulinta duomenų saugojimo struktūra.
-Papildytas README.md failas (paleidimo instrukcija, v0.3 aprašymas).
### [v0.2](https://github.com/MatasC/Objektinis-programavimas/releases/tag/0.2) - (2019-02-17)  
**Pridėta**  
-Tekstinis failas studentų duomenims įvesti kursiokai.txt  
**Koreguota**  
-Programoje pridėta galimybė nuskaityti mokinių duomenis iš tekstinio failo.  
-Pridėtas mokinių rūšiavimas pagal vardą (jei vardai vienodi, tai pagal pavardę) prieš spausdinimą.  
-Patobulintas duomenų įvedimas ranka taip, kad duomenys vistiek būtų išrikiuoti prieš spasudinant.  
-Papildytas README.md failas.  
### [v0.1](https://github.com/MatasC/Objektinis-programavimas/releases/tag/0.1) - (2019-02-16)  
**Pridėta**    
-Sukurtas README.md failas  
-Pridėta programos versija atlikta su C masyvais.  
-pridėta programos versija su vector tipo C++ konteineriais.  
**Koreguota**  
-README.md pridėtas trumpas programos aprašymas.  
-pridėta funkcija atsitiktinai sugeneruoti mokinio pažymius (naudojant C++11 standarto generavimo funkcijas).  
-versijoje su vector konteineriais pridėta struktūra mokinių duomenims saugoti (taip pat vector tipo).  
-Pridėta galimybė galutinį balą skaičiuoti naudojant medianą, vietoje vidurkio.  

# 2 užduotis. Duomenų apdorojimas
## Programos tikslas
Programa nuskaito mokinio vardą, pavardę,egzamino įvertinimą ir namų darbų įvertinimus, tuomet, paskaičiavusi galutinį studento pažymį, programa lentelėje išveda visų studentų galutinius pažymius, vardus ir pavardes.  
**Nuo v0.4 programos tikslas yra ir patikrinti kaip sparčiai programa gali atlikti šią užduotį ir kaip jos sparta priklauso nuo pradinių duomenų failo dydžio**  
## Makefile komandos  
-make paleidimas: sukuria programos paleidimo failą `programa.exe` (jeigu nebūna sukurtas prieš tai, tuomet ši komanda sukuria ir function.o failą).  
-make funkcijos: sukurią failą `function.o`.   
-make valymas: ištrina programos paleidimo failą `programa.exe` ir visus failus su pabaiga `.o` arba `.txt`.  
## Programos paleidimas   
-Įjungti terminalą (komandinę eilutę) ir įvesti komandą `make paleidimas`.   
-Tuomet, parašyti komandą `./programa` (arba paleisti sukurtą faila `programa.exe`).  
**Windows operacinėje sistemoje šios komandos neveikia, reikia naudoti `g++ -o programa 2_uzduotis_vektoriai.cpp function.cpp`**  
## Išvedimo pavyzdys
```shell
Vardas Pavardė  Galutinis
------------------------
Matas  Čenys   8.86
```
## Programos naudojimas
Norint, kad programa nuskaitytų duomenis iš failo, reikia papildyti prie programos prisegtą failą „kursiokai.txt“. Pirmoji failo eilute yra skirta stulpelių aprašymams, todėl į ją negalima įrašyti duomenų, o nuo antrosios eilutės galima įrašinėti duomenis. Lygiuotė ar vienodas skaičius pažymių yra nebūtini (vienas studentas gali turėti daugiau įvertinimų už kitus ir atvirkščiai), tačiau egzamino įvertinimas turi būti paskutinis skaičius eilutėje.
Tekstinio failo pavyzdys:
```shell
Vardas   Pavarde   ND1   ND2   ND3   Egzaminas
Matas    Cenys     8     9     6     9
Arvydas  Sabonis   10    7           10
```
## Programos veikimo rezultatai
### v0.4
Tikrintos programos turėjo po 100, 1 000, 10 000, 100 000, 1 000 000 eilučių ir 10 namų darbų pažymių. Studentų skirstymas buvo neteisingas ir buvo pataisytas versijoje v0.5 (iki v0.5 studentai buvo išskirstomi prieš pat išvedimą if'u patikrinant jų galutinį pažymį). Taip parašyta programa, eilučių skaičiui padidėjus 10 kartų, sulėtėdavo apytiksliai 10 (paskutinės dvi iteracijos sulėtėdavo netgi šiek tiek daugiau nei 10 kartų). daugiausiai laiko užimdavo failų sugeneravimas ir išvedimas (kadangi atrinkimas į gerus ir blogus buvo atliekamas išvedant duomenis).
### v0.5
Tikrintos programos turėjo tiek pat eilučių ir duomenų (100, 1 000, 10 000, 100 000, 1 000 000), tačiau buvo naudoti trys skirtingi konteineriai, failai nebebuvo generuojami, o duomenų atrinkimui sukurta atskira funkcija. Eilučių skaičiui esant ne didesniam nei 10 000, programų veikimo laikai buvo labai panašūs (nebuvo galima pastebėti, kad kažkuris konteineris dirbtų ženkliai greičiau nei kitas, o ir vienas konteineris kartais netgi aplenkdavo kitą), tačiau didėjant eilučių skaičiui vis labiau ryškėjo list konteinerio pranašumai prieš vector ir deque (kurie atliko užduotį labai panašiais laikais, nors vector dažnai aplenkdavo deque, net jeigu ir skirtumas nebudavo labai didelis), kuris su 1 000 000 eilučių failą įveikė 3 kartus greičiau nei vector ar deque. Taip pat verta paminėti ir list rikiavimo komandos list::sort pranašumą prieš std::sort, kuris buvo naudotas vector ir deque rikiavimui, nes list::sort buvo viena iš priežasčių padėjusių list'ui taip stipriai aplenkti vector ir deque paskutinėje iteracijoje.
Taip pat verta paminėti, kad šioje versijoje buvo pastebėta ir sutvarkyta atminties naudojimo problema (neefektyviai naudojama atmintis, nereikalingos informacijos saugojimas), kuri sumažino programos veikimo laiką maždaug 20% (list atveju, programos sulėtėjimas buvo dar didesnis, kurio dėka problema ir buvo pastebėta).
## Versijų istorija
### [v0.5](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.5) - (2019-03-12)  
**Pridėta**  
-duomenų failai.  
**1 000 000 eilučių failo neleido įkelti git'as dėl dydžio apribojimų, todėl prieš paleidžiant programą reikia sugeneruoti dar vieną failą arba sumažinti for iteracijų skaičių**  
**Koreguota**  
-Išskaidytas function.cpp failas (sukurti list.cpp, deque.cpp, vector.cpp) tam, kad būtų lengviau atskirti, kuri funkcija yra skirta kuriam konteineriui.  
-Pataisytas makefile tam, kad veiktų su naujai perdarytu function.cpp failu (sukuria tris skirtingus .exe failus trims konteineriams).  
-**Stipriai pakeista duomenų saugojimo struktūra siekiant sumažinti programos atminties naudojimą.**  
-Pridėta funkcija, kuri išskirsto studentus į gerus ir blogus.  
-**Dauguma funkcijų perrašytos siekiant sumažinti atminties naudojimą.**  
-**Išvalyta visa iteracijos metu nereikalinga informacija (po galutinio skaičiavimo ištrinami namų darbų pažymiai, nebeskaičiuojami galutiniai ir pagal medianą ir pagal vidurkį, o tik pagal pasirinktą kriterijų)**  
-Panaikintas duomenų failų generavimas programos veikimo metu.  
#### v0.4.1 - (2019-03-02)  
**Koreguota**  
-Pataisyti medianos ir vidurkio duomenų tipai (buvo int, pakeisti į double). Ši klaida buvo nuo v0.1, tačiau tik šioje versijoje buvo pataisyta.
### [v0.4](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.4) - (2019-03-02)
**Koreguota**  
-function.cpp patobulintos funkcijos, kad programa galėtų sugeneruoti pradinių duomenų failą ir sutvarkytus duomenis, pagal nurodytą kriterijų, išspausdintų į du naujus failus (`blogi.txt` ir `geri.txt`).  
-function.h pridėta `<chrono>` biblioteka, taip pat pataisyta duomenų saugojimo struktūra (mediana ir vidurkis buvo int tipo).  
Pagrindinėje programoje pridėtos komandos, kurios paskaičiuoja, kaip greitai programa sukūrė pradinių duomenų failą ir kaip greitai ji apdorojo ir išvedė duomenis į naujus tekstinius failus.  
-Programos spartos duomenys yra išvedami į tekstinį failą (jame pažymėta kiek laiko buvo kuriamas atitinkamo dydžio failas ir per kiek laiko jis buvo apdorotas).  
-README.md papildymas (v0.4 aprašymas, programos tikslo ir paleidimo patikslinimai, nuorodos į versijas 0.3 ir 0.4).  
### [v0.3](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.3) - (2019-02-24)  
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

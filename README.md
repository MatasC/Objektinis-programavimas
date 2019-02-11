# Pirmoji užduotis „Pasisveikinimas“
## Programos tikslas
Programa atspausdina įrėmintą pasisveikinimą su vartotoju, kuris yra sudarytas iš 5 eilučių:
-pirmoji eilutė sudaryta iš simbolių *.
-antrosios eilutės pirmas ir paskutinis simboliai yra *, o visi likę simboliai yra tarpai.
-trečioje eilutėje pasisveikinimas su vartotoju (bet eilutė prasideda ir pasibaigia simboliu *).
-ketvirta ir penkta eilutės yra atitinkamai identiškos pirmai ir antrai.
## Naudojimasis programa
Vartotojas iš pradžių įveda savo vardą, pvz. **Matas**, tuomet įveda norimą rėmelio dydį (nuo 1 iki 10), pvz **3**, tuomet programa išveda jam tokį rėmelį:
```shell
Koks Jūsų vardas: Matas
Įveskite rėmelio dydį (nuo 1 iki 10): 3

***********************
*                     *
*                     *
*                     *
*   Sveikas, Matas!   *
*                     *
*                     *
*                     *
***********************
```
## Įdiegimas
### (Unix kompiuteryje) naudojant `Clang`kompiliatorių 
- `git clone https://github.com/MatasC/Objektinis-programavimas.git`
- `cd Objektinis-programavimas`
- `clang++ -std=c++11 Pasisveikinimas.cpp -o pasisveikinimas`
- `./pasisveikinimas`
### Windows kompiuteryje
- `git clone https://github.com/MatasC/Objektinis-programavimas.git`
- `cd Objektinis-programavimas`
- `g++ -o Pasisveikinimas.cpp pasisveikinimas`
- `./pasisveikinimas`
## Versijų istorija
### [v1.0](https://github.com/MatasC/Objektinis-programavimas/releases/tag/v1.0) - (2019-02-11)

**Pridėta**

- Atsirado galimybė kontroliuoti rėmelio dydį

**Koreguota**

- Papildytas **README** failas

### [v0.2](https://github.com/MatasC/Objektinis-programavimas/releases/tag/v0.2) - (2019-02-11)

**Pridėta**

- Papildyta programa taip, kad atpažįsta vartotojo lytį ir pagal ją pakoreguoja sveikinimo tekstą

### [v0.1](https://github.com/MatasC/Objektinis-programavimas/releases/tag/v0.1) - (2019-02-11)

***Pridėta***

- Pirminė programos versija
- **README** failas

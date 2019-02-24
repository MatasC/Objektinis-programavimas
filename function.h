#ifndef FUNCTION
#define FUNCTION
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
#include<algorithm>
#include<vector>
#include<sstream>
#include<ctype.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
struct duomenys {
    string vardas;
    string pavarde;
    int egzaminas;
    int vidurkis;
    int mediana;
    double Vid_galutinis;
    double Med_galutinis;
    std::vector<int> namu_darbai;
    };

bool tikrinimas(duomenys, duomenys);
int ilgiausias(int, int);
void skaitymas(vector <duomenys>&, int&, int&);
void generavimas(vector <duomenys>&, int);
void isvedimas(vector <duomenys>&, char&, int&, int&);
void vidurkis(vector <duomenys>&, int);
void mediana(vector <duomenys>&, int);
void ivedimas_ranka( vector <duomenys>& ,int& , int&);
#endif // FUNCTION

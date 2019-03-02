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
#include<chrono>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
struct duomenys {
    string vardas;
    string pavarde;
    int egzaminas;
    double vidurkis;
    double mediana;
    double Vid_galutinis;
    double Med_galutinis;
    std::vector<int> namu_darbai;
    };

bool tikrinimas(duomenys, duomenys);
int ilgiausias(int, int);
void skaitymas(vector <duomenys>&, int&, int&);
void generavimas(std::ofstream&, int);
void isvedimas(vector <duomenys>&, char&, int&, int&, int, int);
void vidurkis(vector <duomenys>&, int);
void mediana(vector <duomenys>&, int);
#endif // FUNCTION

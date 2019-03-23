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
#include<list>
#include<deque>
#include<iterator>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::list;
using std::deque;

struct duomenys {
    string vardas;
    string pavarde;
    double egzaminas;
    double Galutinis;
    vector <double> namu_darbai;
};

bool tikrinimas(duomenys, duomenys);
bool tikrinimas_gal(duomenys, duomenys);
bool tikrinimas_5(duomenys);
int ilgiausias(int, int);
char Ivestis_kr(char);

void skaitymas(vector <duomenys>&, int&, int&, int, char&);
void skaitymas(deque <duomenys>&, int&, int&, int, char&);
void skaitymas(list <duomenys>&, int&, int&, int, char&);

void generavimas(std::ofstream&, int);

void isvedimas(vector <duomenys>&, vector <duomenys>&, int&, int&);
void isvedimas(deque <duomenys>&, deque <duomenys>&, int&, int&);
void isvedimas(list <duomenys>&, list <duomenys>&, int&, int&, int);

void galutinis(vector <duomenys>&, int, char&);
void galutinis(deque <duomenys>&, int, char&);
void galutinis(duomenys&, char&);

void atrinkimas_1(vector <duomenys>&, vector <duomenys>&, vector <duomenys>&);
void atrinkimas_2(vector <duomenys>&, vector<duomenys>&);
void atrinkimas_1(deque <duomenys>&, deque <duomenys>&, deque <duomenys>&);
void atrinkimas_2(deque <duomenys>&, deque <duomenys>&);
void atrinkimas_1(list <duomenys>&, list <duomenys>&, list <duomenys>&);
void atrinkimas_2(list <duomenys>&, list <duomenys>&);

#endif // FUNCTION

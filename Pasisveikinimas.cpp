#include<iostream>
#include<stdio.h>
using namespace std;
void Remelio_spausdinimas(string sveikinimas, int tarpai,int eilute)
{
    string eil1="", eil2="", eil3="" , eil4="", eil5="";
    for(int i=0;i<eilute;i++)
    {
        eil1+="*";
        eil5+="*";
    }
    eil2+="*";
    eil4+="*";
    for(int e=0;e<eilute-2;e++)
    {
        eil2+=" ";
        eil4+=" ";
    }
    eil2+="*";
    eil4+="*";
    eil3+="*";
    for(int i=0;i<tarpai;i++)
    {
        eil3+=" ";
    }
    eil3+=sveikinimas;
    for(int i=0;i<tarpai;i++)
    {
        eil3+=" ";
    }
    eil3+="*";
    cout<<eil1<<endl<<eil2<<endl<<eil3<<endl<<eil4<<endl<<eil5<<endl;
}
int main()
{
    string vardas, sveikinimas;
    int tarpai=-1;
    printf("Koks Jusu vardas: ");
    cin>>vardas;
    printf("Iveskite remelio dydi (nuo 1 iki 10): ");
    while(tarpai<=0 || tarpai>10)
    {
        cin>>tarpai;
    }
    printf("\n");
    sveikinimas = "Sveikas, " + vardas + "!";
    const int eilute = sveikinimas.size() + tarpai*2+2;
    Remelio_spausdinimas(sveikinimas,tarpai,eilute);
}

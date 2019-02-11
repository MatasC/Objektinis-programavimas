#include<iostream>
#include<stdio.h>
using std::cin;
using std::cout;
using std::string;
using std::endl;
void Remelio_spausdinimas(string sveikinimas, int tarpai,int eilute, int plotis)
{
    for(int i=0;i<plotis;i++)
    {
        if(i==0 || i==plotis-1)
        {
            for(int w=0;w<eilute;w++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        else if(i==tarpai+1)
        {
            cout<<"*";
            for(int w=0;w<tarpai;w++)
                cout<<" ";
            cout<<sveikinimas;
            for(int w=0;w<tarpai;w++)
                cout<<" ";
                cout<<"*"<<endl;
        }
        else
        {
            cout<<"*";
            for(int w=0;w<eilute-2;w++)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
    }
}
int main()
{
    string vardas, sveikinimas;
    int tarpai=-1;
    printf("Koks Jusu vardas: ");
    cin>>vardas;
    if(vardas.back() == 's')
    {
        sveikinimas = "Sveikas, " + vardas + "!";
    }
    else
    {
        sveikinimas = "Sveika, " + vardas + "!";
    }

    printf("Iveskite remelio dydi (nuo 1 iki 10): ");
    while(tarpai<=0 || tarpai>10)
    {
        cin>>tarpai;
    }
    printf("\n");
    const int eilute = sveikinimas.size() + tarpai*2+2;
    const int plotis = tarpai*2+3;
    Remelio_spausdinimas(sveikinimas,tarpai,eilute,plotis);
}

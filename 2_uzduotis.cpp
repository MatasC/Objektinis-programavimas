#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    int n,n_namu_darbu;
    int *namu_darbai = new int[1];
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    cout<<"Iveskite kiek bus mokiniu: ";cin>>n;
    string vardas[n], pavarde[n];
    char pasirinkimas;
    double vidurkis[n], mediana[n]; int egzaminas[n];
    int ilgiausias_vardas=6, ilgiausia_pavarde=7,tikrinamas_ilgis=0;
    for(int i=0;i<n;i++)
    {
        vidurkis[i]=0;
        n_namu_darbu=0;
        cout<<"Iveskite "<<i+1<<"-ojo mokinio varda: ";cin>>vardas[i];
        cout<<"Iveskite "<<i+1<<"-ojo mokinio pavarde: ";cin>>pavarde[i];
        tikrinamas_ilgis = vardas[i].length();
        ilgiausias_vardas = std::max(ilgiausias_vardas,tikrinamas_ilgis);
        tikrinamas_ilgis = pavarde[i].length();
        ilgiausia_pavarde = std::max(ilgiausia_pavarde,tikrinamas_ilgis);
        cout<<"Ar sugeneruoti mokinio pazymius ir egzamino ivertinima(t/n): ";cin>>pasirinkimas;
        switch(pasirinkimas)
        {
        case 'n':
            {
                int temp;
                cout<<"Iveskite mokinio pazymius: ";cin>>temp;
                do
                {
                    cin>>temp;
                    if(temp>0 && temp<11)
                    {
                        int *temp2=new int [n_namu_darbu+1];
                        for(int w=0;w<n_namu_darbu;w++)
                        {
                            temp2[w]=namu_darbai[w];
                        }
                        temp2[n_namu_darbu]=temp;
                        delete []namu_darbai;
                        namu_darbai=temp2;
                        n_namu_darbu++;
                    }
                }while (temp>0 && temp<11);
                cout<<"Iveskite egzamino ivertinima: ";cin>>egzaminas[i];
                break;
            }
        case 't':
            {
                int temp;
                int pazymiu_skaicius = uniform_dist(el);
                for(int e=0;e<pazymiu_skaicius;e++)
                {
                    temp = uniform_dist(el);
                    int *temp2=new int [n_namu_darbu+1];
                    for(int w=0;w<n_namu_darbu;w++)
                    {
                        temp2[w]=namu_darbai[w];
                    }
                    temp2[n_namu_darbu]=temp;
                    delete []namu_darbai;
                    namu_darbai=temp2;
                    n_namu_darbu++;
                }
                egzaminas[i] = uniform_dist(el);
                break;
            }
        default:
            {
                cout<<"Programa nesuprato Jusu ivesto atsakymo, prasome paleisti programa is naujo.";
            }
        }
        for(int w=0;w<n_namu_darbu;w++)
        {
            vidurkis[i]+=namu_darbai[w];
        }
        vidurkis[i]=vidurkis[i]/n_namu_darbu*1.0;
        for(int w=0;w<n_namu_darbu-1;w++)
        {
            for(int e=w+1;e<n_namu_darbu;e++)
            {
                if(namu_darbai[w]>namu_darbai[e])
                    std::swap(namu_darbai[w],namu_darbai[e]);
            }
        }
        if(n_namu_darbu%2==0)
        {
            mediana[i]=(namu_darbai[n_namu_darbu/2-1]+namu_darbai[n_namu_darbu/2])/2.0;
        }
        else
        {
            mediana[i]=namu_darbai[n_namu_darbu/2]*1.0;
        }
    }
    cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
    cin>>pasirinkimas;
    system("pause");
    switch(pasirinkimas)
    {
    case 'm':
        {
            cout<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
            for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            {
                cout<<"-";
            }
            cout<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<std::setw(ilgiausias_vardas+2)<<std::left<<vardas[i]<<std::setw(ilgiausia_pavarde+2)<<std::left<<pavarde[i]<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<0.4*mediana[i]+0.6*egzaminas[i]<<endl;
            }
            for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            {
                cout<<"-";
            }
            cout<<endl;
            break;
        }
    case 'v':
        {
            cout<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
            for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            {
                cout<<"-";
            }
            cout<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<std::setw(ilgiausias_vardas+2)<<std::left<<vardas[i]<<std::setw(ilgiausia_pavarde+2)<<std::left<<pavarde[i]<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<0.4*vidurkis[i]+0.6*egzaminas[i]<<endl;
            }
            for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            {
                cout<<"-";
            }
            cout<<endl;
            break;
        }
    default:
        {
            cout<<"Programa negali isvesti galutinio pazymio pagal jusu pasirinkta kriteriju.";
            break;
        }
    }
    system("pause");
}

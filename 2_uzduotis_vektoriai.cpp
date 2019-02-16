#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
#include<algorithm>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::endl;
struct duomenys {
    string vardas;
    string pavarde;
    int egzaminas;
    int vidurkis;
    int mediana;
    std::vector<int> namu_darbai;
    };
int main()
{
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    int n;
    cout<<"Iveskite kiek bus mokiniu: ";cin>>n;
    std::vector <duomenys> studentai;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7,tikrinamas_ilgis=0;
    char pasirinkimas;
    for(int i=0;i<n;i++)
    {
        studentai.push_back(duomenys());
        studentai[i].vidurkis = 0;
        cout<<"Iveskite "<<i+1<<"-ojo mokinio varda: ";cin>>studentai[i].vardas;
        cout<<"Iveskite "<<i+1<<"-ojo mokinio pavarde: ";cin>>studentai[i].pavarde;
        tikrinamas_ilgis = studentai[i].vardas.length();
        ilgiausias_vardas = std::max(ilgiausias_vardas,tikrinamas_ilgis);
        tikrinamas_ilgis = studentai[i].pavarde.length();
        ilgiausia_pavarde = std::max(ilgiausia_pavarde,tikrinamas_ilgis);
        cout<<"Ar sugeneruoti mokinio pazymius ir egzamino ivertinima(t/n): ";cin>>pasirinkimas;
        switch(pasirinkimas)
        {
        case 'n':
            {
                int temp;
                cout<<"Iveskite mokinio pazymius: ";
                do
                {
                    cin>>temp;
                    if(temp>0 && temp<11)
                    {
                        studentai[i].namu_darbai.push_back(temp);
                    }
                }while (temp>0 && temp<11);
                cout<<"Iveskite egzamino ivertinima: ";cin>>studentai[i].egzaminas;
                break;
            }
        case 't':
            {
                int temp;
                int pazymiu_skaicius = uniform_dist(el);
                for(int w=0;w<pazymiu_skaicius;w++)
                {
                    temp = uniform_dist(el);
                    studentai[i].namu_darbai.push_back(temp);
                }
                studentai[i].egzaminas = uniform_dist(el);
                break;
            }
        default:
            {
                cout<<"Programa nesuprato Jusu ivesto atsakymo, prasome paleisti programa is naujo.";
            }
        }
        for(int w=0;w<studentai[i].namu_darbai.size();w++)
        {
            studentai[i].vidurkis+=studentai[i].namu_darbai[w];
        }
        studentai[i].vidurkis=studentai[i].vidurkis/studentai[i].namu_darbai.size()*1.0;
        std::sort(studentai[i].namu_darbai.begin(),studentai[i].namu_darbai.end());
        if(studentai[i].namu_darbai.size()%2==0)
        {
            studentai[i].mediana=(studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2-1]+studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2])/2.0;
        }
        else
        {
            studentai[i].mediana=studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2]*1.0;
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
                cout<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<0.4*studentai[i].mediana+0.6*studentai[i].egzaminas<<endl;
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
                cout<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<0.4*studentai[i].vidurkis+0.6*studentai[i].egzaminas<<endl;
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

#include "function.h"

bool tikrinimas(duomenys stud1, duomenys stud2)
{
    return stud1.vardas>stud2.vardas;
}

bool tikrinimas_gal(duomenys stud1, duomenys stud2)
{
    return stud1.Galutinis > stud2.Galutinis;
}

int ilgiausias(int tikrinamas_ilgis, int ilgiausias_vardas)
{
    return std::max(ilgiausias_vardas,tikrinamas_ilgis);
}

void skaitymas(deque <duomenys> &studentai, int &ilgiausias_vardas, int &ilgiausia_pavarde, int i, char &pasirinkimas)
{
    std::ifstream in;
    in.open("mokiniai" + std::to_string(i+1) + ".txt");
    try {
        if (!in) throw std::runtime_error("Failo atidarymo klaida\n");
    }
    catch(const std::runtime_error& e)
    {
        cout<<e.what();
        exit(0);
    }
    int temp=0, temp_nd;
    string eilute;
    while(getline(in,eilute))
    {
        std::istringstream skaitymas(eilute);
        studentai.push_back(duomenys());
        skaitymas>>studentai[temp].vardas;
        skaitymas>>studentai[temp].pavarde;
        ilgiausias_vardas = ilgiausias(studentai[temp].vardas.length(),ilgiausias_vardas);
        ilgiausia_pavarde = ilgiausias(studentai[temp].pavarde.length(),ilgiausia_pavarde);
        for(int i=0;i<10;i++)
        {
            skaitymas>>temp_nd;
            studentai[temp].namu_darbai.push_back(temp_nd);
        }
        skaitymas>>studentai[temp].egzaminas;
        try {
            if(studentai[temp].namu_darbai.size() == 0) throw std::runtime_error("Mokinio namu darbu skaicius lygus nuliui, todel jo galutinis pazymys bus laikomas 0\n");
        }
        catch (const std::runtime_error& e)
        {
            cout<<e.what();
            studentai[temp].Galutinis = 0;
        }
        galutinis(studentai, temp, pasirinkimas);
        studentai[temp].namu_darbai.clear();
        temp++;
    }
    in.close();
}

void isvedimas(deque <duomenys> &blogi, deque <duomenys> &geri, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    std::ofstream out1("geri.txt");
    std::ofstream out2("blogi.txt");
    out1<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
    for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
        out1<<"-";
    out1<<endl;
    out2<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
    for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
        out2<<"-";
    out2<<endl;
    for(auto i : geri)
        out1<<std::setw(ilgiausias_vardas+2)<<std::left<<i.vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<i.pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<i.Galutinis<<endl;
    for(auto i : blogi)
        out2<<std::setw(ilgiausias_vardas+2)<<std::left<<i.vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<i.pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<i.Galutinis<<endl;
    out1.close();
    out2.close();
}

void atrinkimas_1(deque <duomenys>& studentai, deque <duomenys>& blogi, deque <duomenys>& geri)
{
    for(auto i : studentai)
    {
        if(i.Galutinis >= 5)
            geri.push_back(i);
        else if(i.Galutinis < 5)
            blogi.push_back(i);
    }
}

void atrinkimas_2(deque <duomenys>& studentai, deque <duomenys> &blogi)
{
    std::sort(studentai.begin(), studentai.end(), tikrinimas_gal);
    int svertinis = 0;
    for(auto i : studentai)
    {
        if(i.Galutinis < 5)
            blogi.push_back(i);
        else 
            svertinis++;

    }
    studentai.resize(svertinis);
    std::sort(blogi.begin(), blogi.end(), tikrinimas);
    std::sort(studentai.begin(), studentai.end(), tikrinimas);
}

void galutinis(deque <duomenys> &studentai, int i, char &pasirinkimas)
{
    if(pasirinkimas == 'm')
    {
        if(studentai[i].namu_darbai.size() == 0)
        {
            exit(0);
        }
        else
        {
            double mediana = 0;
            std::sort(studentai[i].namu_darbai.begin(),studentai[i].namu_darbai.end());
            if(studentai[i].namu_darbai.size()%2==0)
            {
                mediana=(studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2-1]+studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2])/2.0;
            }
            else
            {
                mediana=studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2]*1.0;
            }
            studentai[i].Galutinis = mediana*0.4+0.6*studentai[i].egzaminas;
        }
    }
    else if(pasirinkimas == 'v')
    {
        if(studentai[i].namu_darbai.size() == 0)
        {
            exit(0);
        }
        else
        {
            double vidurkis = 0;
            for(int w=0;w<studentai[i].namu_darbai.size();w++)
            {
                vidurkis+=studentai[i].namu_darbai[w];
            }
            vidurkis/=double(studentai[i].namu_darbai.size());
            studentai[i].Galutinis = vidurkis*0.4+0.6*studentai[i].egzaminas;
        }
    }
}
#include "function.h"

bool tikrinimas(duomenys stud1, duomenys stud2)
{
    return stud1.vardas < stud2.vardas;
}

bool tikrinimas_gal(duomenys stud1, duomenys stud2)
{
    return stud1.Galutinis < stud2.Galutinis;
}

bool tikrinimas_5(duomenys stud1)
{
    return stud1.Galutinis == 5;
}

int ilgiausias(int tikrinamas_ilgis, int ilgiausias_vardas)
{
    return std::max(ilgiausias_vardas,tikrinamas_ilgis);
}

void generavimas(std::ofstream& in, int skaicius)
{
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    for(int w=0;w<skaicius;w++)
    {
        in<<"Vardas"<<w<<"  Pavarde"<<w<<"  ";  
        for(int w=0;w<10;w++)
        {
            in<<uniform_dist(el)<<" ";
        }
        in<<uniform_dist(el)<<endl;;
    }
}

char Ivestis_kr(char pasirinkimas)
{
    cin>>pasirinkimas;
    while(pasirinkimas != 'v')
    {
        if(pasirinkimas == 'm' || pasirinkimas == '2' || pasirinkimas == '1')
            break;
        cout<<"Neteisingas kriterijus. Bandykite dar karta."<<endl;
        cin>>pasirinkimas;
    }
    return pasirinkimas;
}

void galutinis(vector <duomenys> &studentai, int i,char &pasirinkimas)
{
    switch(pasirinkimas)
    {
        case 'm':
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
            break;
        }
        case 'v':
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
            break;
        }
    }
}


void skaitymas(vector <duomenys> &studentai, int &ilgiausias_vardas, int &ilgiausia_pavarde, int i, char &pasirinkimas)
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

void atrinkimas_1(vector <duomenys>& studentai, vector <duomenys>& blogi, vector <duomenys>& geri)
{
    sort(studentai.begin(), studentai.end(), tikrinimas_gal);
    std::vector<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
    std:copy(studentai.begin(),it,std::back_inserter(blogi));
    std::copy(it,studentai.end(),std::back_inserter(geri));
}
void atrinkimas_2(vector <duomenys>& studentai, vector<duomenys> &blogi)
{
    sort(studentai.begin(), studentai.end(), tikrinimas_gal);
    std::vector<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
    std::copy(it,studentai.end(),std::back_inserter(blogi));
    studentai.resize(studentai.size()-blogi.size());
}
void isvedimas(vector <duomenys> &blogi, vector <duomenys> &geri, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    std::ofstream out1("geri.txt");
    std::ofstream out2("blogi.txt");
    out1<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
    out2<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
    for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
        out1<<"-";
        out2<<"-";
    out1<<endl;
    out2<<endl;
    for(auto i : geri)
        out1<<std::setw(ilgiausias_vardas+2)<<std::left<<i.vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<i.pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<i.Galutinis<<endl;
    for(auto i : blogi)
        out2<<std::setw(ilgiausias_vardas+2)<<std::left<<i.vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<i.pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<i.Galutinis<<endl;
    out1.close();
    out2.close();
}
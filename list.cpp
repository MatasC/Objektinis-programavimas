#include"function.h"
bool tikrinimas(duomenys stud1, duomenys stud2)
{
    return stud1.vardas<stud2.vardas;
}

bool tikrinimas_gal(duomenys stud1, duomenys stud2)
{
    return stud1.Galutinis > stud2.Galutinis;
}
bool tikrinimas_5(duomenys stud1)
{
    return stud1.Galutinis == 5;
}
int ilgiausias(int tikrinamas_ilgis, int ilgiausias_vardas)
{
    return std::max(ilgiausias_vardas,tikrinamas_ilgis);
}

void galutinis(duomenys& studentai, char& pasirinkimas)
{
    if(pasirinkimas == 'm')
    {
        if(studentai.namu_darbai.size() == 0)
        {
            exit(0);
        }
        else
        {
            double mediana = 0;
            std::sort(studentai.namu_darbai.begin(),studentai.namu_darbai.end());
            if(studentai.namu_darbai.size()%2==0)
            {
                mediana=(studentai.namu_darbai[studentai.namu_darbai.size()/2-1]+studentai.namu_darbai[studentai.namu_darbai.size()/2])/2.0;
            }
            else
            {
                mediana=studentai.namu_darbai[studentai.namu_darbai.size()/2]*1.0;
            }
            studentai.Galutinis = mediana*0.4+0.6*studentai.egzaminas;
        }
    }
    else if(pasirinkimas == 'v')
    {
        if(studentai.namu_darbai.size() == 0)
        {
            exit(0);
        }
        else
        {
            double vidurkis = 0;
            for(int w=0;w<studentai.namu_darbai.size();w++)
            {
                vidurkis+=studentai.namu_darbai[w];
            }
            vidurkis/=double(studentai.namu_darbai.size());
            studentai.Galutinis = vidurkis*0.4+0.6*studentai.egzaminas;
        }
    }
}

void skaitymas(list <duomenys> &studentai, int &ilgiausias_vardas, int &ilgiausia_pavarde, int i, char &pasirinkimas)
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
    int temp_nd;
    string eilute;
    duomenys laikinas;
    while(getline(in,eilute))
    {
        std::istringstream skaitymas(eilute);
        skaitymas>>laikinas.vardas;
        skaitymas>>laikinas.pavarde;
        ilgiausias_vardas = ilgiausias(laikinas.vardas.length(), ilgiausias_vardas);
        ilgiausia_pavarde = ilgiausias(laikinas.pavarde.length(), ilgiausia_pavarde);
        for(int i=0;i<10;i++)
        {
            skaitymas>>temp_nd;
            laikinas.namu_darbai.push_back(temp_nd);
        }
        skaitymas>>laikinas.egzaminas;
        galutinis(laikinas, pasirinkimas);
        laikinas.namu_darbai.clear();
        studentai.push_back(laikinas);
    }
    in.close();
}

void atrinkimas_1(list <duomenys> &studentai, list <duomenys> &geri, list <duomenys> &blogi)
{
    studentai.sort(tikrinimas);
    for(auto i : studentai)
    {
        if(i.Galutinis >= 5)
            geri.push_back(i);
        else if(i.Galutinis < 5)
            blogi.push_back(i);
    }
}

void atrinkimas_2(list <duomenys>& studentai, list <duomenys>& blogi)
{
    studentai.sort(tikrinimas_gal);
    std::list<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
    blogi.splice(blogi.begin(),studentai,it,studentai.end());
    studentai.resize(studentai.size()-blogi.size());
}

void isvedimas(list <duomenys> &geri, list <duomenys> &blogi, int &ilgiausias_vardas, int &ilgiausia_pavarde, int skaicius)
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
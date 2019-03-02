#include "function.h"
bool tikrinimas(duomenys stud1, duomenys stud2)
{
    if(stud1.vardas<stud2.vardas)
        return 1;
    else if(stud1.vardas == stud2.vardas && stud1.pavarde<stud2.pavarde)
        return 1;
    else
        return 0;
}
int ilgiausias(int tikrinamas_ilgis, int ilgiausias_vardas)
{
    return std::max(ilgiausias_vardas,tikrinamas_ilgis);
}
void skaitymas(vector <duomenys> &studentai, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    std::ifstream in;
    in.open("mokiniai.txt");
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
        while(skaitymas)
        {
            skaitymas>>temp_nd;
            studentai[temp].namu_darbai.push_back(temp_nd);
        }
        studentai[temp].egzaminas = studentai[temp].namu_darbai.back();
        studentai[temp].namu_darbai.erase(studentai[temp].namu_darbai.end()-1);
        studentai[temp].namu_darbai.erase(studentai[temp].namu_darbai.end()-1);
        try {
            if(studentai[temp].namu_darbai.size() == 0) throw std::runtime_error("Mokinio namu darbu skaicius lygus nuliui, todel jo galutinis pazymys bus laikomas 0\n");
        }
        catch (const std::runtime_error& e)
        {
            cout<<e.what();
            studentai[temp].Med_galutinis = 0;
            studentai[temp].Vid_galutinis = 0;
        }
        vidurkis(studentai, temp);
        mediana(studentai, temp);
        temp++;
    }
    std::sort(studentai.begin(),studentai.end(),tikrinimas);
    in.close();
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
void isvedimas(vector <duomenys> &studentai, char &pasirinkimas, int &ilgiausias_vardas, int &ilgiausia_pavarde, int skaicius, int w)
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
    if(pasirinkimas == 'm')
    {
        for(int i=0;i<skaicius;i++)
        {
            if(studentai[i].Med_galutinis>=5)
                out1<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Med_galutinis<<endl;
            if(studentai[i].Med_galutinis<5)
                out2<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Med_galutinis<<endl;
        }
    }
    else if(pasirinkimas == 'v')
    {
        for(int i=0;i<skaicius;i++)
        {
            if(studentai[i].Vid_galutinis>=5)
                out1<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Vid_galutinis<<endl;
            if(studentai[i].Vid_galutinis<5)
                out2<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Vid_galutinis<<endl;
        }
    }
    else
    {
        cout<<"Neteisingas kriterijus"<<endl;
    }
    out1.close();
    out2.close();
}
void vidurkis(vector <duomenys> &studentai, int i)
{
    if(studentai[i].namu_darbai.size() == 0)
    {
        studentai[i].vidurkis = 0;
    }
    else
    {
        for(int w=0;w<studentai[i].namu_darbai.size();w++)
        {
            studentai[i].vidurkis+=studentai[i].namu_darbai[w];
        }
        studentai[i].vidurkis/=double(studentai[i].namu_darbai.size());
        studentai[i].Vid_galutinis = studentai[i].vidurkis*0.4+0.6*studentai[i].egzaminas;
    }
}
void mediana(vector <duomenys> &studentai, int i)
{
    if(studentai[i].namu_darbai.size() == 0)
    {
        studentai[i].mediana = 0;
    }
    else
    {
        std::sort(studentai[i].namu_darbai.begin(),studentai[i].namu_darbai.end());
        if(studentai[i].namu_darbai.size()%2==0)
        {
            studentai[i].mediana=(studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2-1]+studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2])/2.0;
        }
        else
        {
            studentai[i].mediana=studentai[i].namu_darbai[studentai[i].namu_darbai.size()/2]*1.0;
        }
        studentai[i].Med_galutinis = studentai[i].mediana*0.4+0.6*studentai[i].egzaminas;
    }
}

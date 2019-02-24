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
    in.open("kursiokai.txt");
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
    getline(in,eilute);
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
void generavimas(vector <duomenys> &studentai, int i)
{
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    int temp;
    int pazymiu_skaicius = uniform_dist(el);
    for(int w=0;w<pazymiu_skaicius;w++)
    {
        temp = uniform_dist(el);
        studentai[i].namu_darbai.push_back(temp);
    }
    studentai[i].egzaminas = uniform_dist(el);
}
void isvedimas(vector <duomenys> &studentai, char &pasirinkimas, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    if(pasirinkimas == 'm')
    {
        cout<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
        for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            cout<<"-";
        cout<<endl;
        for(int i=0;i<studentai.size();i++)
            cout<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Med_galutinis<<endl;
        for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            cout<<"-";
        cout<<endl;
    }
    else if(pasirinkimas == 'v')
    {
        cout<<std::setw(ilgiausias_vardas+2)<<std::left<<"Vardas"<<std::setw(ilgiausia_pavarde+2)<<std::left<<"Pavarde  "<<std::left<<"Galutinis"<<endl;
        for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            cout<<"-";
        cout<<endl;
        for(int i=0;i<studentai.size();i++)
            cout<<std::setw(ilgiausias_vardas+2)<<std::left<<studentai[i].vardas<<std::setw(ilgiausia_pavarde+2)<<std::left<<studentai[i].pavarde<<std::fixed<<std::setprecision(2)<<std::setw(4)<<std::left<<studentai[i].Vid_galutinis<<endl;
        for(int i=0;i<ilgiausias_vardas+ilgiausia_pavarde+13;i++)
            cout<<"-";
        cout<<endl;
    }
    else
    {
        cout<<"Neteisingas kriterijus"<<endl;
    }
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
        studentai[i].vidurkis/=studentai[i].namu_darbai.size()*1.0;
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
void ivedimas_ranka( vector <duomenys> &studentai,int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    int n;
    cout<<"Iveskite kiek bus mokiniu: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        studentai.push_back(duomenys());
        cout<<"Iveskite "<<i+1<<"-ojo mokinio varda: ";cin>>studentai[i].vardas;
        cout<<"Iveskite "<<i+1<<"-ojo mokinio pavarde: ";cin>>studentai[i].pavarde;
        ilgiausias_vardas = ilgiausias(studentai[i].vardas.length(),ilgiausias_vardas);
        ilgiausia_pavarde = ilgiausias(studentai[i].pavarde.length(),ilgiausia_pavarde);
        char g_pasirinkimas;
        cout<<"Ar sugeneruoti mokinio pazymius ir egzamino ivertinima(t/n): ";cin>>g_pasirinkimas;
        switch(g_pasirinkimas)
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
                try {
                    if(studentai[i].namu_darbai.size() == 0) throw std::runtime_error("Mokinio namu darbu skaicius lygus nuliui, todel jo galutinis pazymys bus laikomas 0\n");
                }
                catch(std::runtime_error& e)
                {
                    cout<<e.what();
                    studentai[i].Med_galutinis = 0;
                    studentai[i].Vid_galutinis = 0;
                }
                break;
            }
        case 't':
            {
                generavimas(studentai, i);
                break;
            }
        default:
            {
                cout<<"Programa nesuprato Jusu ivesto atsakymo, prasome paleisti programa is naujo."<<endl;
            }
        }
        vidurkis(studentai, i);
        mediana(studentai, i);
    }
    std::sort(studentai.begin(),studentai.end(),tikrinimas);
}

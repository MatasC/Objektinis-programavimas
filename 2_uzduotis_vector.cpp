#include"function.h"
int main()
{
    char pasirinkimas, pasirinkimas_str;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7, skaicius = 100;
    vector <duomenys> studentai, geri, blogi;
    std::ofstream lout;
    cout<<"Ar studentus skirstyti pagal pirma (1), ar pagal antra (2) strategija: ";
    pasirinkimas_str=Ivestis_kr(pasirinkimas_str);
    switch(pasirinkimas_str)
    {
        case '2':
        {
            lout.open("Laiku_suvestine.txt", std::fstream::app);
            lout<<"2 strategija - Vector: "<<endl;
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            pasirinkimas = Ivestis_kr(pasirinkimas);
            for(int i=0;i<5;i++)
            {
                auto pradzia = std::chrono::high_resolution_clock::now();
                studentai.reserve(skaicius);
                skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde, i, pasirinkimas);
                atrinkimas_2(studentai,blogi);
                isvedimas(studentai,blogi,ilgiausias_vardas,ilgiausia_pavarde);
                studentai.clear();
                blogi.clear();
                skaicius*=10;
                auto pabaiga = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> skirtumas = pabaiga-pradzia;
                lout<<skaicius/10<<" eiluciu failo apdorojimo laikas = "<<skirtumas.count()<<" s."<<endl; 
            }
            lout.close();
            break;
        }
        case '1':
        {

            lout.open("Laiku_suvestine.txt", std::fstream::app);
            lout<<"1 strategija - Vector: "<<endl;
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            pasirinkimas = Ivestis_kr(pasirinkimas);
            for(int i=0;i<5;i++)
            {
                auto pradzia = std::chrono::high_resolution_clock::now();
                studentai.reserve(skaicius);
                skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde, i, pasirinkimas);
                atrinkimas_1(studentai,blogi,geri);
                isvedimas(blogi,geri,ilgiausias_vardas,ilgiausia_pavarde);
                studentai.clear();
                blogi.clear();
                geri.clear();
                skaicius*=10;
                auto pabaiga = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> skirtumas = pabaiga-pradzia;
                lout<<skaicius/10<<" eiluciu failo apdorojimo laikas = "<<skirtumas.count()<<" s."<<endl; 
            }
            lout.close();
            break;
        }  
    }
}

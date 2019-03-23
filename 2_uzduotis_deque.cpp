#include"function.h"
int main()
{
    char pasirinkimas, pasirinkimas_str;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7, skaicius = 100;
    deque <duomenys> studentai, geri, blogi;
    std::ofstream lout;
    cout<<"Ar studentus skirstyti pagal pirma (1), ar pagal antra (2) strategija: ";
    cin>>pasirinkimas_str;
    while(pasirinkimas_str != '1')
    {
        if(pasirinkimas_str == '2')
            break;
        cout<<"Neteisingas kriterijus. Bandykite dar karta."<<endl;
        cin>>pasirinkimas_str;
    }
    switch(pasirinkimas_str)
    {
        case '1':
        {
            lout.open("Laiku_suvestine.txt", std::fstream::app);
            lout<<"1 strategija - deque: "<<endl;
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            cin>>pasirinkimas;
            while(pasirinkimas != 'v')
            {
                if(pasirinkimas == 'm')
                break;
                cout<<"Neteisingas kriterijus. Bandykite dar karta."<<endl;
                cin>>pasirinkimas;
            }
            for(int i=0;i<5;i++)
            {
                auto pradzia = std::chrono::high_resolution_clock::now();
                skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde, i, pasirinkimas);
                atrinkimas_1(studentai,blogi,geri);
                isvedimas(blogi,geri,ilgiausias_vardas,ilgiausia_pavarde);
                studentai.clear();
                geri.clear();
                blogi.clear();
                skaicius*=10;
                auto pabaiga = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> skirtumas = pabaiga-pradzia;
                lout<<skaicius/10<<" eiluciu failo apdorojimo laikas = "<<skirtumas.count()<<" s."<<endl; 
            }
            lout.close();
            break;
        }
        case '2':
        {
            lout.open("Laiku_suvestine.txt", std::fstream::app);
            lout<<"2 strategija - deque: "<<endl;
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            cin>>pasirinkimas;
            while(pasirinkimas != 'v')
            {
                if(pasirinkimas == 'm')
                break;
                cout<<"Neteisingas kriterijus. Bandykite dar karta."<<endl;
                cin>>pasirinkimas;
            }
            for(int i = 0;i < 5;i++)
            {
                auto pradzia = std::chrono::high_resolution_clock::now();
                skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde, i, pasirinkimas);
                atrinkimas_2(studentai, blogi);
                //cout<<studentai.size()<<"  "<<blogi.size()<<endl;
                isvedimas(blogi, studentai, ilgiausias_vardas, ilgiausia_pavarde);
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
    }
}

#include"function.h"
int main()
{
    char pasirinkimas;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7, skaicius = 100;
    list <duomenys> studentai,geri, blogi;
    std::ofstream lout;
    lout.open("Laiku_suvestine.txt", std::fstream::app);
    lout<<"List: "<<endl;
    cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
    cin>>pasirinkimas;
    for(int i=0;i<5;i++)
    {
        auto pradzia = std::chrono::high_resolution_clock::now();
        skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde, i, pasirinkimas);
        atrinkimas(studentai,geri,blogi);
        isvedimas(geri,blogi,ilgiausias_vardas,ilgiausia_pavarde,skaicius);
        studentai.clear();
        blogi.clear();
        geri.clear();
        skaicius*=10;
        auto pabaiga = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas = pabaiga-pradzia;
        lout<<skaicius/10<<" eiluciu failo apdorojimo laikas = "<<skirtumas.count()<<" s."<<endl; 
    }
    lout.close();
}

#include"function.h"
int main()
{
    char pasirinkimas;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7, skaicius = 100;
    std::vector <duomenys> studentai;
    std::ofstream lout("Laiku_suvestine.txt");
    cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
    cin>>pasirinkimas;
    for(int i=0;i<5;i++)
    {
        std::ofstream out;
        out.open("mokiniai.txt"); 
        auto pradzia_txt = std::chrono::high_resolution_clock::now();
        generavimas(out,skaicius);
        auto pabaiga_txt = std::chrono::high_resolution_clock::now();
        auto pradzia = std::chrono::high_resolution_clock::now();
        studentai.reserve(skaicius);
        skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde);
        isvedimas(studentai,pasirinkimas,ilgiausias_vardas,ilgiausia_pavarde,skaicius,i);
        studentai.clear();
        skaicius*=10;
        out.close();
        auto pabaiga = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas = pabaiga-pradzia;
        std::chrono::duration<double> skirtumas_txt = pabaiga_txt-pradzia_txt;
        lout<<skaicius/10<<" eiluciu failo sukurimo laikas = "<<skirtumas_txt.count()<<" s, o apdorojimo laikas = "<<skirtumas.count()<<" s."<<endl; 
    }
    lout.close();
}

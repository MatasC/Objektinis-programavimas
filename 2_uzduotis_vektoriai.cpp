#include"function.h"
int main()
{
    char pasirinkimas_duomenims, pasirinkimas;
    int ilgiausias_vardas=6, ilgiausia_pavarde=7;
    std::vector <duomenys> studentai;
    cout<<"Ar nuskaityti duomenis is failo, ar ivesite ranka (f/r)? ";cin>>pasirinkimas_duomenims;
    switch(pasirinkimas_duomenims)
    {
    case 'r':
        {
            ivedimas_ranka(studentai,ilgiausias_vardas,ilgiausia_pavarde);
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            cin>>pasirinkimas;
            isvedimas(studentai,pasirinkimas,ilgiausias_vardas,ilgiausia_pavarde);
            break;
        }
    case 'f':
        {
            skaitymas(studentai,ilgiausias_vardas,ilgiausia_pavarde);
            cout<<"Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
            cin>>pasirinkimas;
            isvedimas(studentai,pasirinkimas,ilgiausias_vardas,ilgiausia_pavarde);
            break;
        }
    default:
        {
            cout<<"Programa nesuprato Jusu ivesto simbolio. Bandykite dar karta."<<endl;
            break;
        }
    }
}

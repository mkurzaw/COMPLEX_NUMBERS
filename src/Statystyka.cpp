#include <iostream>
#include "Statystyka.hh"
using namespace std;

void Wyswietl(Statystyka S)
{
    cout<<"Liczba poprawnych odpowiedzi: "<<S.dobrze<<endl; // poprawne odp
    cout<<"Liczba blednych odpowiedzi: "<< S.wszystkie-S.dobrze; // niepoprawne odp 
    cout<<endl<<"Procentowo :"<<S.dobrze*100.0/S.wszystkie<<"%"<<endl;
}
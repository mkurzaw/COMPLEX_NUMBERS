#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


ostream  &operator <<(ostream& Str,WyrazenieZesp  WyrZ)
{
        Str<<(WyrZ.Arg1); //wyswietlanie pierwszego argumentu
    switch(WyrZ.Op) // wyswietlanie znaku matematycznego
    {
        case Op_Dodaj:
        Str<<"+";
        break;
        case Op_Odejmij:
        Str<<"-";
        break;
        case Op_Mnoz:
        Str<<"*";
        break;
        case Op_Dziel:
        Str<<"/";
        break;
    }
    Str<<(WyrZ.Arg2); //wysietlanie drugieo arg
    return Str;
}
void Wyswietl(WyrazenieZesp  WyrZ)
{
    Wyswietl(WyrZ.Arg1); //wyswietlanie pierwszego argumentu
    switch(WyrZ.Op)  // wyswietlanie znaku matematycznego
    {
        case Op_Dodaj:
        cout<<"+";
        break;
        case Op_Odejmij:
        cout<<"-";
        break;
        case Op_Mnoz:
        cout<<"*";
        break;
        case Op_Dziel:
        cout<<"/";
        break;
    }
    Wyswietl(WyrZ.Arg2); //wysietlanie drugieo arg
}
LZespolona Oblicz(WyrazenieZesp  WyrZ) //obliczenia dla juz przeciazonych operatorow
{
    LZespolona Wynik;
    switch(WyrZ.Op)
    {
        case Op_Dodaj:
        Wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
        case Op_Odejmij:
        Wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
        case Op_Mnoz:
        Wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
        case Op_Dziel:
        Wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;
    }
    return Wynik;

}

bool Wczytaj(WyrazenieZesp &WyrZ) //wczytywanie kolejnego dzialania mat
{
    bool test;
    test=Wczytaj(WyrZ.Arg1);
    if(!test) // jesli nie zostal podany 1 argument zwroc blad
    {
        return false;
    }

    char znak;
    cin >> znak;
    switch (znak) //jesli zaden z podanych znakow zwroci blad
    {
    case '+':
       WyrZ.Op=Op_Dodaj;
        break;
         case '-':
       WyrZ.Op=Op_Odejmij;
        break;
         case '*':
       WyrZ.Op=Op_Mnoz;
        break;
         case '/':
       WyrZ.Op=Op_Dziel;
        break;
    
    default:
    return false;
        break;
    }

        test=Wczytaj(WyrZ.Arg2);
    if(!test) // jesli nie zostal podany 2 argument zwroc blad
    {
        return false;
    }
  return true;
}
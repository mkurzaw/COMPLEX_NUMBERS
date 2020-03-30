#include <iostream>
#include <math.h>
#include "LZespolona.hh"

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)//operator dla dodawania liczb zespolonych
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)//operator dla odejmowania
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)//operator dla mnozenia
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}
LZespolona operator / (LZespolona Sprz, double Mod2)// operator dla dzielenia
{
 LZespolona Wynik;
  Wynik.re = Sprz.re/Mod2;
  Wynik.im = Sprz.im/Mod2;
  return Wynik;

}
LZespolona  operator / (LZespolona  Skl1, LZespolona Skl2)
{
    LZespolona  Wynik;

  Wynik=Skl1*Sprzezenie(Skl2)/ Modul2(Skl2);
  return Wynik;
}

LZespolona Sprzezenie(LZespolona Skl1)
{
  Skl1.im=Skl1.im*(-1);
  return Skl1 ;

}
double Modul2(LZespolona Skl2)
{
  double Mod2;
  Mod2 = pow(Skl2.re,2) + pow(Skl2.im,2);
  return Mod2;
  
}
void Wyswietl(LZespolona Wynik) //wyswietla wynik
{
  
 cout<<"("<<Wynik.re<<showpos<<" "<<Wynik.im<<noshowpos<<"i)"; // showpos pokazuje plus jesli liczba jest dodatnia

}

bool Wczytaj(LZespolona &Zm) //wczytywanie liczby zespolonej
{
   char znak ;
   cin>>znak;
   if(znak!='(') // sprawdzanie czy liczba zespolona jest podana w nawiasie
   {
     return false; // jesli nie ustawia sie blad
   }
   cin>>Zm.re;
   if(cin.bad()) // funkcja bad() zwraca nam satus bitu bledu badbit true jesli popelnilismy blad a false gdy poszlo wszystko ok
   {
      return false;
   }
      cin>>Zm.im;
   if(cin.bad()) // funkcja bad() zwraca nam satus bitu bledu badbit true jesli popelnilismy blad a false gdy poszlo wszystko ok
   {
      return false;
   }
   cin>>znak; // sprawdzanie poprawnosci zapisu liczbys zespolonej
   if (znak!='i')
   {
     return false;
   }
   cin>>znak; // sprawdzanie poprawnosci zapisu liczbys zespolonej
   if (znak!=')')
   {
     return false;
   }
return true;
}
ostream &operator <<(ostream& Str,LZespolona Skl1) //operator dla strumienia wyjsciowego 
{
   Str<<"("<<Skl1.re<<showpos<<" "<<Skl1.im<<noshowpos<<"i)";
   return Str;
}
istream &operator >>(istream& Str, LZespolona &Skl1) // operator dla wejscia 
{
     char znak ;
   Str>>znak;
   if(znak!='(')
   {
     Str.setstate(ios_base::badbit); // kiedy ten if sie wykona setstate ustawi statsu bitu bledu na true 
     return Str;
   }
   Str>>Skl1.re;
   if(Str.bad()) // funkcja bad() zwraca nam satus bitu bledu badbit true jesli popelnilismy blad a false gdy poszlo wszystko ok
   {
      return Str;
   }
      Str>>Skl1.im;
   if(Str.bad()) // funkcja bad() zwraca nam satus bitu bledu badbit true jesli popelnilismy blad a false gdy poszlo wszystko ok
   {
      return Str;
   }
   Str>>znak; 
   if (znak!='i')
   {
     Str.setstate(ios_base::badbit); // kiedy ten if sie wykona setstate ustawi statsu bitu bledu na true
     return Str;
   }
   Str>>znak;
   if (znak!=')')
   {
     Str.setstate(ios_base::badbit); // kiedy ten if sie wykona setstate ustawi statsu bitu bledu na true
     return Str;
   }
return Str;
}
#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

ostream &operator <<(ostream& Str,LZespolona Skl1); //przeciazenie wyjscia
istream &operator >>(istream& Str, LZespolona &Skl1);//przeciazenie dla wejscia ampersand bo zmieniamy wartosc
bool Wczytaj(LZespolona &Skl1);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Sprz, double Mod2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
void Wyswietl(LZespolona Wynik);
LZespolona Sprzezenie(LZespolona Skl1m);
double Modul2(LZespolona Skl2);
#endif

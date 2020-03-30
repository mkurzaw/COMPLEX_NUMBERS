#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;




int main(int argc, char **argv)
{
  

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  Statystyka S = {0,0};
  LZespolona wynik, odp;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) // petla bedzie sie wykonywac dopoki w bazie beda dostepne pytania
   {
       cout<<"podj wynik : "<<WyrZ_PytanieTestowe<<endl;
          wynik=Oblicz(WyrZ_PytanieTestowe);
        for( int i=0; i<3;i++) // sa 3 szanse jezeli odpowiedz nie bedzie liczba
        {
       cout<<"twoaj odp :" ;
       cin>>odp;
       if(cin.bad())
       {
         cout<<"jeszcze raz"<<endl;
       }
       else
       {
         break;
       }
       cin.clear(); /// czysci ustawienia obiektu cin
       cin.ignore(1024,'\n'); /// jesli podales dlugi ciag i cos zostalo w buforze pamieci zostaje wyczyszczone az do znaku nowej lini (enter)
        }

       if(wynik.im==odp.im && wynik.re==odp.re) //wynik ma sie zgadzac z poprawna odp, jesli tak +1 pkt
       {
         cout<<"dobrze :)"<<endl;
         S.dobrze++;
         S.wszystkie++;
       }
       else
       {
          cout<<"zle :("<<endl;
         S.wszystkie++;
       }
       
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
   Wyswietl(S);
}
/* Mikolaj Kurzawski 29.03.2020 Test arytmetyki licz zespolonych
  Program ma za zadanie wykonac krotki test arytmetyki liczb zespolonych 
  Dostepne sa 2 zestawy pytan latwe i trudne. Pytania mozna modyfikowac w Bazie Testow. 
  W makefile domyslnie ustawiony jest test latwy, aby wlaczyc trudny trzeba wpisac w terminalu .// test_arytm_zesp trudny
  Jezeli na pytanie wpiszemy bledny ciag znakow to mamy 3 szanse.
  Po zakonczeniu testu pokazuje sie nam liczba poprawnych, blednych opdowiedzi i wynik w procentach.
*/
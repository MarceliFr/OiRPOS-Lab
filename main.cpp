#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <limits>
#include <vector>
#include <fstream>

using namespace std;

void euklides(int a, int b);
void funkcja_eulera(int D);
bool czy_pierwsza(int n);
void oblicz_nwd();
void enter_esc();
void wczytaj_pierwsze(vector <int> & pierwsze);
void zapisz_pierwsze();

int main()
{

    euklides(26,98);
    return 0;
}

void wczytaj_pierwsze( vector <int> & pierwsze)
{
    fstream plik;
    plik.open("liczby pierwsze.txt", ios::in);
    if(!plik)
    {
        cout << "Nie mozna otworzyc pliku" << endl;
        exit(0);
    }
    string liczba;
    while (!plik.eof())
    {
        getline(plik, liczba);
        pierwsze.push_back(stoi(liczba));
    }
    plik.close();
}

//bool czy_pierwsza(int n)
//{
//    vector <int> pierwsze;
//    wczytaj_pierwsze(pierwsze);
//
//    if (n > pierwsze[pierwsze.size()-1] && n < pierwsze[pierwsze.size()-1] * pierwsze[pierwsze.size()-1])
//    {
//        for (int i = pierwsze[pierwsze.size()-1]; i <= n; i+=2)
//        {
//            if (n % pierwsze);
//        }
//    }
//
//    return true;
//}

//void zapisz_pierwsze()
//{
//    int n;
//	cout<<"podaj liczbe do ktorej wyznaczamy liczby pierwsze: ";
//	cin>>n;
//	if (czy_pierwsza(n))
//        cout << "liczba " << n << " jest pierwsza";
//    cout << "liczba " << n << " nie jest pierwsza";
//    return;
//
//
//
//    //int liczba = 1;
//    //plik << liczba << " ";
//    //plik.close();
//}

void funkcja_eulera(int D)
{

}

void enter_esc()
{
    char enter = 0;
    cout << "\nENTER aby kontynuowac ...ESCAPE aby zakonczyc\n";
    while (enter != 13 && enter !=27)
    {
        if (kbhit())
            enter = getch();
        if (enter == 27)
            exit(0);
    }
}

void oblicz_nwd()
{
    int a , b;
    while (true)
    {
        system ("cls");
        cout << "OBLICZANIE NWD (a,b) ..... (a,b) < 2147483648 \n";
        while(true)
        {
            cout << "podaj liczbe a: "; cin >> a;
            if(cin.fail())
            {
                cout << "nie wprowadzono liczby lub liczba jest za duza\n";
                cin.clear(); cin.ignore(INT_MAX,'\n');
            }
            else
                break;
        }
        while(true)
        {
            cout << "podaj liczbe b: "; cin >> b;
            if(cin.fail())
            {
                cout << "nie wprowadzono liczby lub liczba jest za duza\n";
                cin.clear(); cin.ignore(INT_MAX,'\n');
            }
            else
                break;
        }
        cout << endl;
        euklides(a,b);                              // wywolanie funkcji
        enter_esc();
    }
    return;
}

void euklides(int a, int b)
{
    int k =0, i = 0, wynik = 0, ile_razy =0  , miesci = 0 , reszta = 0, NWD = 0;
    int nwd [100][4] = {0};

    string wyswietl = "";
    string znak_0, znak_2;
    string L_0, L_1, L_2, L_3, W_NWD;

    a = abs (a);
    b = abs (b);

    if (a > b)
    {
        k = a; a = b; b = k;
    }
    else if (a == b)
    {
        NWD = a;
        cout << "NWD (" << a << "," << b << ") = " << NWD << endl;
        return ;
    }

    wynik = b;
    ile_razy = b / a;
    miesci = a;
    reszta = wynik - ile_razy * miesci;

    if (reszta == 0)
    {
        NWD = a;
        cout << "NWD (" << a << "," << b << ") = " << NWD << " ....... poniewaz:\n";
        cout << wynik << " = " << ile_razy << " * " << miesci << " + " << reszta << endl;
        return ;
    }

    while (wynik != 1 && reszta != 0)
    {
        nwd [i][0] = wynik;
        nwd [i][1] = ile_razy;
        nwd [i][2] = miesci;
        nwd [i][3] = reszta;
        wynik = nwd [i][2];
        ile_razy = nwd [i][2] / nwd [i][3];
        miesci = nwd [i][3];
        reszta = wynik - ile_razy * miesci;
        i++;
    }

    k = i - 1;
    NWD = nwd [k][3];
    int odwroc_nwd [i][4] = {0,0,0,0};

    for (int x = 0; x < i; x++)
    {
        odwroc_nwd [x][0] = 1;
        odwroc_nwd [x][1] = nwd [i - x - 1][0];
        odwroc_nwd [x][2] = 0 - nwd [i - x - 1][1];
        odwroc_nwd [x][3] = nwd [i - x - 1][2];
    }

    for (int x = 1; x < i; x++)
    {
        odwroc_nwd [x][0] = odwroc_nwd [x][0] * odwroc_nwd [x - 1][2];
        odwroc_nwd [x][2] = odwroc_nwd [x][2] * odwroc_nwd [x - 1][2] + odwroc_nwd [x - 1][0];;
    }

    cout << "NWD (" << a << "," << b << ") = " << NWD << " ....... poniewaz:\n";

    for (int x = 0; x < i; x++)
        cout << nwd [x][0] << " = " << nwd [x][1] << " * " << nwd [x][2] << " + " << nwd [x][3] << endl;

    // wyswietlanie odwroconego euklidesa
    if (odwroc_nwd [k][0] < 0)
        znak_0 = " - ";
    else
        znak_0 = " + ";

    if (odwroc_nwd [k][2] < 0)
        znak_2 = " - ";
    else
        znak_2 = " + ";

    L_0 = to_string (abs (odwroc_nwd [k][0]));
    L_1 = to_string (odwroc_nwd [k][1]);
    L_2 = to_string (abs (odwroc_nwd [k][2]));
    L_3 = to_string (odwroc_nwd [k][3]);
    W_NWD = to_string(NWD);

    wyswietl = W_NWD + " =" + znak_0 + L_0 + " * " + L_1 + znak_2 + L_2 + " * "+ L_3;

    cout << "\nZ ODWROCONEGO ALGORYTMU EUKLIDESA .....\n";
    cout << wyswietl << endl;
}

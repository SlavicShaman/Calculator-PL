#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;
float liczba1, liczba2, wynik;
int wybor;
string dzialanie;
fstream plik; /*file variable called wszystkie_wyniki*/

int main()
{
	cout << "Calc booting up";
	Sleep(1000); cout << "."; 	Sleep(1000); cout << "."; 	Sleep(1000); cout << "." << endl;
	cout << "Witaj w kalkulatorze!" << endl;
	cout << "Podaj pierwsz\245 liczb\251: ";
	cin >> liczba1;
	cout << "Podaj drug\245 liczb\251: ";
	cin >> liczba2;

	cout << "   MENU" << endl;
	cout << "1. Dodawanie" << endl;
	cout << "2. Odejmowanie" << endl;
	cout << "3. Mno\276enie" << endl;
	cout << "4. Dzielenie" << endl;
	cout << "5. Pot\251gowanie" << endl;

	cout << "Jakie dzia\210anie chcesz wykona\206? " << endl;
	cin >> wybor;
	

	switch (wybor)
	{
		case 1:
		{
			wynik = liczba1 + liczba2;
			dzialanie = "dodawanie";
			break;
		}
		case 2:
		{
			wynik = liczba1 - liczba2;
			dzialanie = "odejmowanie";
			break;
		}
		case 3:
		{
			wynik = liczba1 * liczba2;
			dzialanie = "mno\276enie";
			break;
		}
		case 4:
		{
			if (liczba2 == 0)
			{
				cout << "Nie dziel przez zero!";
				break;
			}
			else
			{
				wynik = liczba1 / liczba2;
				dzialanie = "dzielenie";
				break;
			}
			
		}
		case 5:
		{
			wynik = pow(liczba1, liczba2);
			dzialanie = "pot\251gowanie";
			break;
		}
		default:
		{
			cout << "Nie ma takiej opcji!" << endl;
			break;
		}
	}

	if (wynik != 0)
	{
		cout <<"Wynik: " << wynik;
	}



	plik.open("wyniki.txt", ios::out | ios::app); /*ios::app appends the outed data to the existing data in a file, without erasing the previous existing data
													ios::in would read data from a given file			*/
	if (plik.good() == false)
	{
		cout << "Plik nie istnieje. Tworzenie pliku";
		Sleep(1000); cout << "."; 	Sleep(1000); cout << "."; 	Sleep(1000); cout << "." << endl;
		
	}


	plik << "Pierwsza liczba: " << liczba1 << ", " << "druga liczba: " << liczba2 << ", " << "dzia\210anie: " << dzialanie << ", " << "wynik = " << wynik << endl;

	plik.close();
	
	
	return 0;
}
	
#include <Windows.h>	//windows		liczenie
#include <cstdlib>	//linux windows 	liczenie
#include <conio.h>	//aby program sie nie zamykał
#include <iostream>	//potrzebny do wprowadzania danych wejściowych i wyjściowych



void gotoxy(int X, int Y); //gotoxy ustawia położenie kursora na ekranie
void Powitanie(); 		// kolejna funkcja
void Wprowadzanie(float &size, char &znak);
void Tworzenie_figury(float size, float x, float y, char znak);
void Ruch(float size, float &x, float &y, char znak);


using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Polish");
    float x = 1, y = 1;
    float size;
    char znak;
    system("cls");

    Powitanie();
    Wprowadzanie(size, znak);
    Tworzenie_figury(size, x, y, znak);
    Ruch(size, x, y, znak);
    _getch();

    return 0;
}


void Powitanie()				// ekran początkowy
{
	cout << "===============================================================================" << endl;
    	cout << "= Program do tworzenia figury, który umożliwia poruszanie obiektem po konsoli =" << endl;
    	cout << "==================  powiększania go i pomniejszania  ==========================" << endl;
    	cout << "===============================================================================" << endl;
    	cout << "============================  Udanej zabawy !  ================================" << endl;
    	cout << "===============================================================================" << endl;
	cout << "=================  Wcisnij dowolny klawisz, aby rozpoczšć  ====================" << endl;
	cout << "===============================================================================" << endl;
    _getch();
}



void Wprowadzanie(float &size, char &znak)
{
    system("cls");
    int max = 20, min = 5, rozmiar;
    do
    {
    cout << "Podaj rozmiar figury z zakresu 5-20: ";				//rozmiar figury
    cin >> rozmiar;
    } 
    
	while (rozmiar < min || rozmiar > max);
    size = rozmiar;

    cout << "Podaj znak, którym narysujesz figurę: ";				// wybór znaku
    cin >> znak;

}



void Tworzenie_figury(float size, float x, float y, char znak)			// rysowanie figury
{
    system("cls");

    for (int i = 1; i < size / 2; i++)														// rysowanie figury
	{
		gotoxy(x + i, y + size - i), cout << znak;
		
        	gotoxy(x + i, y + i), cout << znak;																		

		gotoxy(x + size / 2, y + size / 2), cout << znak; 
	}
	
    gotoxy(10, 25), 
	cout << "Instrukcja:" << endl; 															// instrukcja w oknie poruszania figury
	cout << "Górna strzalka - ruch w góre; Dolna strzałka - ruch w dol" << endl;
	cout << "Prawa strzalka - ruch w prawo; Lewa strzałka - ruch w lewo" << endl;
	cout << "Przycisk '-' pomniejszanie figury; Przycisk '+' powiększanie figury" << endl;
	cout << "ESC: wyjscie";
}



void Ruch(float size, float &x, float &y, char znak)     // przesuwanie figury po konsoli
{
    int max = 23;
    char klawisz;
    

    do
    {
        klawisz = _getch();

        switch (klawisz)
        {
        
		case '+':   	// powiększanie
        {
            size++;

            if (size < 5 || size > max)
                size--; y--;
            break;
        }

        case '-':  		// pomniejszanie
        {
            size--;
            if (size < 5 || size > max)
                size++;
            break;
        }
        
        case 77:     		// w prawo            
        {
        	x++;
            break;
        }

        case 75:    		// w lewo       
        {
            x--;
            break;
        }

      
        case 80:  		// w górę
        {
            y++;
            break;
        }  
		
		case 72:  	// w dół
        {
            y--;
            break;
        }
        }
            Tworzenie_figury(size, x, y, znak); 

    } while (klawisz != 27);

}
void gotoxy(int X, int Y)
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

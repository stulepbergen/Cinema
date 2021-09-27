#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <windows.h>
#include "Print.h"
#include "Film.h"
#include "BankCheck.h"
#include "BuyTicOff.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu()
{
	SetConsoleTextAttribute(hConsole, 2);
	cout << "~~~~MENU~~~~\n";
	cout << "1.Print a ticket\n";
	cout << "2.Buy a ticket\n";
	int choice;
	cout << "Make a choice: "; cin >> choice;
	if(choice == 1)
	{
		cout << "Enter your phone number: ";
		string number;
		cin >> number;
		Print c(number);
		cout << "\nNumber of the ticket: " << c.getNumber();
		string p;
		cout << "\nPodtverdite nomer please: ";
		cin >> p;
		cout << c.Podtverzhdenie(p);
		c.Ticket();
	}
	if(choice == 2)
	{
		int fill;
		do{
			cout << "\nPASSENGERS - 0\nFROZEN - 1\nHELLO_JULIE - 2\nAFTER - 3";
			cout << "\nWhich film do you want to watch?";
			cin >> fill;
		}while(fill > 3);
		Film f(fill);
		f.getInfoFilm();

		BuyTicOff a;
		a.inputfile();
		a.output();
		a.search();
		a.search2();
		a.spot();
		a.printTicket();
	}
}

int main() {
	SetConsoleTextAttribute(hConsole, 9);
	cout << " ________________________________________________" << endl;
	cout << "|   |   |   |   |   |                            |" << endl;
	cout << "|   |   |   |   |   |                     _______|" << endl;
	cout << "|   | k | i | n | o |                    |toilet |" << endl;
	cout << "|___|___|___|___|___|                    |_______|" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                         _______|" << endl;
	cout << "|______ ______________                   |       |" << endl;
	cout << "| cafe |       |      |                  | Ward  |" << endl;
	cout << "|______|_______|______|                  |__robe_|" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|     scores                                     |" << endl;
	cout << "|_______________________                  bank   |" << endl;
	cout << "|   |     |       |     |         in      _ _ _  |" << endl;
	cout << "|___|_____|_______|_____|_________| |____|_|_|_|_|" << endl;

	while(true){	
		cout << "[1] Menu\n[2] exit\n";
		int choose; cin >> choose;
		if(choose == 1) Menu();
		else if(choose == 2) break;
	}
		return 0;
}


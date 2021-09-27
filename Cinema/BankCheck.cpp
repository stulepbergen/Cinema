#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <windows.h>
#include "BankCheck.h"
using namespace std;

void BankCheck::Bsearch(int price)
{
	ifstream fin;
 	Bank t;
 	char file[15] = "BankDB.txt";
 	if(b != 0) { delete[] b; n = 0; b = 0; }
 	fin.open(file);
 	if(!fin.is_open()) { cout << file << "File is not found!\n"; getch(); return; }
 	n = 0;
 	do
	{
		fin >> t.name >> t.pin >> t.balance;
  		n++;
   	}  while(fin.good());
	n--;
 	fin.close();
 	b = new Bank[n];
 	if(b == 0) { cout << "No memory!\n"; n = 0; getch(); return; }
 	fin.open(file);
 	if(!fin.is_open()) { cout << file << "File is not found!\n"; getch(); return; }
  	for(int i = 0; i < n; i++)
 	{
	 	fin >> b[i].name >> b[i].pin >> b[i].balance;
 	}
 	fin.close();

	int p, c = 0;
	if(b == 0) { cout << "Array is empty!\n"; getch(); return; }
 	f = 0;
 	back:
 	cout << "Enter pin: "; cin >> p;
 	for (int i = 0; i < n; i++)
 	{
 		if(b[i].pin == p)
	    {
			b[f] = b[i];
			c++;
	    }
	}
    if(c == 0) { cout << "Pin is wrong!\n"; goto back; }
 	cout << "Hello, " << b[f].name << "!" <<
	"On your account " << b[f].balance << "tg." << endl;
 	if(price > b[f].balance) cout << "Not enough to buy!" << endl;
 	else cout << "The remainder: " << b[f].balance-price << endl;
    getch();
	return;
}

void BankCheck::Boutput()
{
 	if(b == 0) { cout << "Array is empty!\n"; getch(); return; }
	cout.setf(ios::left);
 	cout << "\n~~~~~~~~~~~Data Base <<Bank>>~~~~~~~~~~~~\n" << endl;
	for(int i = 0; i < n; i++)
   	{
		cout.setf(ios::left);
	 	cout << setw(22) << b[i].name <<
		setw(10) << b[i].pin <<
		setw(6) << b[i].balance << endl;
	}
    getch();
}

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <windows.h>
#include "BuyTicOff.h"
#include "BankCheck.h"
using namespace std;

void BuyTicOff::inputfile()
{
	ifstream fin;
	int i;
 	Ticket t;
 	char file[15] = "terminalDB.txt";
 	if(px != 0L) { delete[] px; n=0; px=0; }
 	fin.open(file);
 	if(!fin.is_open()) { cout << file << "File is not found!\n"; getch(); return; }
 	n = 0;
 	do
	{
		fin >> t.date >> t.time >> t.nameFilm >> t.format >> t.numHall >> t.cost;
  		n++;
   	}  while(fin.good());
	n--;
 	fin.close();
 	px = new Ticket[n];
 	if(px == 0) { cout << "No memory!\n"; n=0; getch(); return; }
 	fin.open(file);
 	if(!fin.is_open()) { cout << file << "File is not found!\n"; getch(); return; }
  	for(i = 0; i < n; i++)
 	{
	 	fin >> px[i].date >> px[i].time >> px[i].nameFilm >> px[i].format >> px[i].numHall >> px[i].cost;
 	}
 	fin.close();
}

void BuyTicOff::output()
{
 	if(px == 0) { cout << "Array is empty!\n"; getch(); return; }
	cout.setf(ios::left);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
 	cout << "\n~~~~~~~~~~~~~~~~Data Base <<TERMINAL>>~~~~~~~~~~~~~~~~~~\n" << endl;
 	cout << "   " << setw(13) << "Date" <<
	setw(9) << "Time" <<
	setw(13) << "Name film" <<
	setw(8) << "Format" <<
	setw(6) << "Hall" <<
	setw(8) << "Cost" << endl;
	for(int i = 0; i < n; i++)
   	{
		cout.setf(ios::left);
	 	cout << setw(15) << px[i].date <<
		setw(10) << px[i].time <<
		setw(15) << px[i].nameFilm <<
		setw(7) << px[i].format <<
		setw(5) << px[i].numHall <<
		setw(5) << px[i].cost << endl;
	}
    getch();
}

void BuyTicOff::search()
{
	char h[15];
	if(px == NULL) { cout << "Array is empty!\n"; getch(); return; }
	film:
 	cout << "Enter name of the film: "; cin >> h;
 	f = 0;
 	for (int i = 0; i < n; i++)
    if(strcmp(px[i].nameFilm, h) == 0)
    {
		px[f] = px[i];
        f++;
    }
    if(f == 0) { cout << "There is no such film in our cinema!\n"; goto film; }
    result();
	return;
}

void BuyTicOff::result()
{
 	if(px == NULL) { cout << "Array is empty!\n"; getch(); return; }
 	system("CLS");
	cout.setf(ios::left);
 	cout << "   " << setw(13) << "Date" <<
	setw(9) << "Time" <<
	setw(13) << "Name film" <<
	setw(8) << "Format" <<
	setw(6) << "Hall" <<
	setw(8) << "Cost" << endl;
	for(int i = 0; i < f; i++)
   	{
		cout.setf(ios::left);
	 	cout << setw(15) << px[i].date <<
		setw(10) << px[i].time <<
		setw(15) << px[i].nameFilm <<
		setw(7) << px[i].format <<
		setw(5) << px[i].numHall <<
		setw(5) << px[i].cost << endl;
	}
    getch();
}

void BuyTicOff::search2()
{
	char h[15];
	int c = 0;
	if(px == NULL) { cout << "Array is empty!\n"; getch(); return; }
	date:
 	cout << "Choose the date: "; cin >> h;
 	for (int i = 0; i < f; i++)
    if(strcmp(px[i].date, h) == 0)
    {
		px[g] = px[i];
		c++;
    }
    if(c == 0) { cout << "The film " << px[g].nameFilm << " is not available on this date!\n"; goto date; }
    c = 0;

    char tm[6];
    timee:
    cout << "Choose the time: "; cin >> tm;
    for (int i = 0; i < f; i++)
    if(strcmp(px[i].date, h) == 0 && strcmp(px[i].time, tm) == 0)
    {
		px[g] = px[i];
		c++;
    }
    if(c == 0) { cout << "The film " << px[g].nameFilm << " is not available on this time!\n"; goto timee; }
	return;
}

void BuyTicOff::spot()
{
	int **matrix = new int *[9];
	for(int i = 1; i <= 9; i++)
	{
		matrix[i] = new int [12];
	}
	place:
	cout << "Choose the row(1-9): "; cin >> row;
	cout << "Choose the spot(1-12): "; cin >> spot1;
	for(int i = 1; i <= 9; i++)
	{
		//if(matrix[row][spot1] != -1)
		for(int j = 1; j <= 12; j++)
		{
			cout.setf(ios::left); 
			//matrix[i][j] = j;
//			matrix[7][5] = 0;
//			matrix[7][6] = 0;
//			matrix[4][4] = 0;
//			matrix[4][3] = 0;
//			matrix[6][8] = 0;
//			matrix[6][9] = 0;
//			matrix[6][10] = 0;
			//matrix[row][spot1] = 'x';
			cout << setw(3) << j << "|";
		} cout << '\n';
	} cout << endl;
	if(matrix[row][spot1] == 'x') { cout << "This place is already booked! Choose the other!\n"; goto place;}
	else 
	{
		cout << "Enter type of the ticket(adult, child): "; cin >> type;
		matrix[row][spot1] = 'x';
	}
	if(strcmp(type, "child") == 0) px[g].cost -= px[g].cost*0.2;
	BankCheck bank;
	bank.Bsearch(px[g].cost);
}

void BuyTicOff::printTicket()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	SetConsoleTextAttribute(hConsole, 11);
	cout.setf(ios::left);
	cout << "Here is your ticket please! Have a nice day!\n";
cout << "_________________________" <<
	 "\n|Date: " << setw(18) << right << px[g].date << "|" <<
	 "\n|Time: " << setw(18) << right << px[g].time << "|" <<
	 "\n|Film: " << setw(18) << right << px[g].nameFilm << "|" <<
	 "\n|Format: " << setw(16) << right << px[g].format << "|" <<
	 "\n|Hall: " << setw(18) << right << px[g].numHall << "|" <<
	 "\n|Row: " << setw(19) << right << row << "|" <<
	 "\n|Spot: " << setw(18) << right << spot1 << "|" <<
	 "\n|Type: " << setw(18) << right << type << "|" <<
	 "\n|Cost: " << setw(18) << right << px[g].cost <<  "|" <<
	 "\n|________________________|\n";
}

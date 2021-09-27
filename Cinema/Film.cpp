#include<iostream>
#include <windows.h>
#include "Film.h"
using namespace std;

Film::Film(int &f): film(static_cast<Films>(f)){}

void Film::getInfoFilm()
	{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		switch(film)
		{
		case PASSENGERS:
			cout << "\nPassengers";
			cout << "\nGenre:  Drama, Romance, Sci-Fi ";
			cout << "\nDirector: Morten Tyldum";
			cout << "\nWriter: Jon Spaihts";
			cout << "\nStars: Jennifer Lawrence, Chris Pratt, Michael Sheen";
			cout << "\nDescription: A malfunction in a sleeping pod on a spacecraft traveling to a distant colony planet wakes one passenger 90 years early.";
			break;
		case FROZEN:
			cout << "\nFrozen";
			cout << "\nGenre: Animation, Adventure, Comedy";
			cout << "\nDirectors: Chris Buck, Jennifer Lee";
			cout << "\nWriters: Jennifer Lee (screenplay by), Hans Christian Andersen (story inspired by: The Snow Queen)";
			cout << "\nStars: Kristen Bell, Idina Menzel, Jonathan Groff ";
			cout << "\nDescription: When the newly crowned Queen Elsa accidentally uses her power to turn things into ice to curse her home in infinite winter,"
			     << "her sister Anna teams up with a mountain man, his playful reindeer, and a snowman to change the weather condition..";
			break;
		case HELLO_JULIE:
			cout << "\nHello, Julie!";
			cout << "\nGenre: Comedy, Romance, Drama";
			cout << "\nDirector: Rob Reiner";
			cout << "\nWriters: Rob Reiner, Andrew Scheinman";
			cout << "\nStars: Madeline Carroll, Callan McAuliffe, Rebecca De Mornay";
			cout << "\nDescription: Two eighth-graders start to have feelings for each other despite being total opposites.";
			break;
		case AFTER:
			cout << "\nAfter";
			cout << "\nGenre: Romance, Drama";
			cout << "\nDirector: Jenny Gage";
			cout << "\nWriters:  Susan McMartin, Tamara Chestna";
			cout << "\nStars:  Josephine Langford, Hero Fiennes Tiffin, Khadijha Red Thunder";
			cout << "\nDescription: A young woman falls for a guy with a dark secret and the two embark on a rocky relationship. Based on the novel by Anna Todd.";
			break;
		}
	}


Film::~Film() {
	// TODO Auto-generated destructor stub
}

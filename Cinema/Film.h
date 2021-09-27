#ifndef FILM_H_
#define FILM_H_

class Film {
public:
	enum Films{
		PASSENGERS,
		FROZEN,
		HELLO_JULIE,
		AFTER
	};
private:
	Films film;
public:
	Film(int&);
	void getInfoFilm();

	virtual ~Film();
};

#endif /* FILM_H_ */

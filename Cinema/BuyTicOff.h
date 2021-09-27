#ifndef BUYTICOFF_H_
#define BUYTICOFF_H_

struct Ticket
{
	char date[12];
	char time[8];
	char nameFilm[15];
	char format[7];
	int numHall;
	int cost;
};

class BuyTicOff {
private:
  	Ticket *px;
  	int n;
  	int f;
  	int g;
  	int row;
  	int spot1;
  	char type[10];
public:

  BuyTicOff(){ n = 0; f = 0; g = 0; row = 0; spot1 = 0; px = 0; }
  ~BuyTicOff(){ n = 0; if(px != 0) delete []px; }
  void inputfile();
  void output();
  void search();
  void result();
  void search2();
  void printTicket();
  void spot();
};

#endif /* BUYTICOFF_H_ */


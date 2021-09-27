#ifndef BANKCHECK_H_
#define BANKCHECK_H_
struct Bank
{
	char name[22];
	int pin;
	int balance;
};

class BankCheck {
protected:
  	Bank *b;
  	int n;
  	int f;
public:
  	BankCheck(){ n = 0; f = 0; b = 0; }
  	~BankCheck(){ n = 0; if(b != 0) delete [] b; }
	void Boutput();
	void Bsearch(int);
};

#endif /* BANKCHECK_H_ */

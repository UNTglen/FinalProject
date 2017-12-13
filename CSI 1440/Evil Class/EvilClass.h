#ifndef EVILCLASS_H
#define EVILCLASS_H

class EvilClass
{
private:
	int n;
public:
	EvilClass();
	EvilClass(int);
	EvilClass(EvilClass&);
	~EvilClass();
	EvilClass operator= (EvilClass);
	int getN();
	void setN();
};

#endif
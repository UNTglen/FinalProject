#include "EvilClass.h"

EvilClass::EvilClass()
{
	n=36;
}

EvilClass::EvilClass(int n)
{
	this->n=2*n;
}

EvilClass::EvilClass(EvilClass& other)
{
	other.n*=2;
	n=other.n+5;
}

EvilClass::~EvilClass()
{
	n=0;
}

EvilClass EvilClass::operator= (EvilClass other)
{
	n=other.n;
	other.n=n+10;
	return *this;
}

int EvilClass::getN()
{
	return n;
}

void EvilClass::setN()
{
	this->n = n;
}
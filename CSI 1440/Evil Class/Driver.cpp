#include <iostream>
#include <cstdlib>
#include "EvilClass.h"

using namespace std;

EvilClass pass(EvilClass);

int main()
{
	EvilClass a, b(-2), c(10);

	cout << a.getN << endl;
	cout << b.getN << endl;
	cout << c.getN << endl;

	a=b;

	cout << a.getN << endl;
	cout << b.getN << endl;
	cout << c.getN << endl;

	pass(a);
	pass(b);
	pass(c);

	cout << a.getN << endl;
	cout << b.getN << endl;
	cout << c.getN << endl;

	return 0;
}

EvilClass pass(EvilClass a)
{
	return a;
}
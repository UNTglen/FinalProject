//*********************************************************
/** \File: ObjectIfc.hpp
*
*	\Author: Glen Newell
*	\Author helpers: NA
*
*	\class: ObjectIfc
*	\description: Provied a virtual tostring
*
*
*	<ul>
*	  <li>date modifide: 20070925<br>
*		file created
*	  </li>
*/
//*********************************************************
#ifndef PROJ3_OBJECTIFC_H
#define PROJ3_OBJECTIFC_H
#include <iostream>
using namespace std;

class ObjectIfc
{
public:
	virtual string toString() = 0;
};

#endif

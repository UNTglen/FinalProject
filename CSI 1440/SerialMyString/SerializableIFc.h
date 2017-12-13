#ifndef _SERIALIZABLEH
#define _SERIALIZABLEH

#include "IObjectStream.h"
#include "OObjectStream.h"

using namespace std;

class SerializableIfc
{
   public:
     virtual void writeObject(OObjectStream &)  = 0;
     virtual void readObject (IObjectStream &)  = 0;
};

#endif

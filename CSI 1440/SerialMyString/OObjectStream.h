#ifndef _OOBJECTSTREAM_H
#define _OOBJECTSTREAM_H

#include <iostream>
#include <fstream>

using namespace std;

class OObjectStream
{
   private:
      fstream out;
   public:
    OObjectStream(char* filename)
    {
		if(!this->open(filename))
			cout << filename << ":file could not open" << endl;
	}
    OObjectStream(string filename)
    {
		if(!this->open(filename.c_str()))
			cout << filename.c_str() << ":file could not open" << endl;
	}
    bool open(char* filename)
    {
        out.open(filename, ios::out | ios::trunc | ios::binary);
        return !(out.bad() || out.eof());
    }
    ostream &write(char *buffer, int streamsize)
    {
		return out.write(buffer, streamsize);
	}
    bool open(string filename)
    {
        return this->open(filename.c_str());
    }
    void close()
    {
		out.close();
	}
    ~OObjectStream()
    {
		this->close();
	}
};

#endif


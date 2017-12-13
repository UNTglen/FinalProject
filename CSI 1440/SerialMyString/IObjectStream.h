#ifndef _IOBJECTSTREAM_H
#define _IOBJECTSTREAM_H

#include <iostream>
#include <fstream>

using namespace std;


class IObjectStream
{
   private:
      fstream in;
   public:
    IObjectStream(char* filename)
    {
		if (!this->open(filename))
			cout << filename << ": could not open file" << endl;
	}
    IObjectStream(string filename)
    {
		if (!this->open(filename.c_str()))
			cout << filename.c_str() << ": could not open file" << endl;
	}
    bool open(char* filename)
    {
        in.open(filename, ios::in | ios::binary);
        return !(in.bad() || in.eof());
    }
    bool open(string filename)
    {
        return this->open(filename.c_str());
    }
    istream &read(char *buffer, int streamsize)
    {
		return in.read(buffer, streamsize);
	}
    void close()
    {
		in.close();
	}
    ~IObjectStream()
    {
		this->close();
	}
	bool eof()
	{
	    return in.eof();
	}
};

#endif


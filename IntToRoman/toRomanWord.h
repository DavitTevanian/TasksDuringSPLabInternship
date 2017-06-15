#ifndef _TOROMANWORD_
#define _TOROMANWORD_
#include <iostream>
#include <string>
using namespace std;

class Convert {
  public:
    Convert ();
    void Print ();
    void ConvertToRoman ( unsigned num );
  private:
    string _romanWord;
};

#endif //_TOROMANWORD_

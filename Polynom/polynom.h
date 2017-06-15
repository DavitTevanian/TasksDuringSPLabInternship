#ifndef _POLYNOM_
#define _POLYNOM_
#include <iostream>
#include <list>
#include <utility>
using namespace std;
typedef list < pair < int,int > > listPol;

class Polynom {

  public:
    Polynom() {}
    ~Polynom() {}
    void Print();
    void Pow();
    void Insert( const list < pair < int,int > > & inputPolynom );

  private:
    void Sort( listPol & polynom );
    listPol _polynom;
};

#endif //_POLYNOM_

#ifndef _FACTORIAL_
#define _FACTORIAL_
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 100000;

class Factorial {
public:
    Factorial();
    ~Factorial();
    void Print();
    void FactOfBigDigit( int  numner);
private:
    int* _vector;
    int _length;
    int _size;
    void _resize( int newSize);
    void _compute( int num);
};


#endif //_FACTORIAL_
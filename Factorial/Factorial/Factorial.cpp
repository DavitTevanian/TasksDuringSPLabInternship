#include "Factorial.h"

Factorial::Factorial():_size( MAX ), _length( 0 ){
    _vector = new int[_size];
    _vector[0] = 1;
}

Factorial::~Factorial(){
    delete[] _vector;
}

void Factorial::FactOfBigDigit( int number ){
    for( int i = 2; i <= number; ++i)
	    _compute(i);
}

void Factorial::_resize( int newSize ){
    int* newVector=new int [newSize];
    for( int i = 0; i < newSize; ++i )
        newVector[i]=_vector[i];
    _size = newSize;
    delete[] _vector;
    _vector=newVector;
}

void Factorial::Print(){
    for( int i = _length; i >= 0; --i)
		cout<<_vector[i];
    cout<<endl;
}

void Factorial::_compute( int num ) {
    long i,rem=0;
    int* temp=new int[_size];
    for( i = 0; i <= _length; ++i )
        temp[i]=_vector[i];

    for( i = 0; i <= _length; ++i ){
        _vector[i] = ( temp[i] * num + rem ) % 10;
        rem = ( temp[i] * num + rem ) / 10;
    }
    if( rem != 0 ){
        while( rem != 0 ){
            _vector[i] = rem % 10;
             rem = rem / 10;
             i++;
        }
    }
    _length = i-1; 
    if( _length >= _size - 1 )
	    _resize( _size * 2 );

}


#include "Vector.h"
#include <stdexcept>

template <typename T>
vector<T>::vector():_size( 100 ),_count( 0 ),_flag( true ) {
    _vector=new T[_size];
}

template <typename T>
vector<T>::vector(int size, const T& item ):_size( size ),_count( size ),_flag( false ) {
    _vector=new T[_size];
	for( int i = 0; i < _size; ++i)
		_vector[i] = item;
}

template <typename T>
vector<T>::~vector() {
    delete[] _vector;
}

template <typename T>
bool vector<T>::empty() {
    if( _count == 0 )
        return true;
    return false;
}

template <typename T>
int vector<T>::size() const {
    return _count;
}

template <typename T>
int vector<T>::capacity() const {
    return _size;
}


template <typename T>
T& vector<T>::operator[]( int index ) {
    if( index < 0 )
		throw out_of_range("Out of range");
    if( index >= _size )
        if( _flag )
            _resize( _size * 2);
		else 
            throw out_of_range("Out of range");
    return _vector[index];
}

template <typename T>
const T& vector<T>::operator[]( int index ) const {
    if( index < 0 || index >= _size )
        throw out_of_range("Out of range");
     return _vector[index];
}

template <typename T>
void vector<T>::push( const T & item ) {
    if( _count < _size )
        _vector[_count++]=item;
    else if( _flag ){
        _resize( _size * 2 );
        _vector[_count++]=item;
    }
	else if( !_flag )
        throw out_of_range("Out of range");
}

template <typename T>
void vector<T>::pop() {
    if( _count == 0)
        throw out_of_range("Out of range");
    else
        _count--;
}

template <typename T>
T& vector<T>::front() {
    if( _count == 0)
        throw out_of_range("Out of range");
    else
        return _vector[0];
}

template <typename T>
T& vector<T>::back() {
    if( _count == 0)
        throw out_of_range("Out of range");
    else
        return _vector[_count - 1];
}

template <typename T>
void vector<T>::_resize( int newSize ) {
    T* newVector=new T[newSize];
    
    for( int i = 0; i < newSize; ++i )
        newVector[i]=_vector[i];
    _size = newSize;
    delete[] _vector;
    _vector=newVector;
}

template <typename T>
vector<T>::vector( const vector<T>& src ) {
    _size=src._size;
    _count=src._count;
    _vector=new T[_size];
    for( int i = 0; i < _size; ++i) 
        _vector[i] = src._vector[i];
}

template <typename T>
vector<T>& vector<T>::operator=( const vector<T>& src ) {
    if( this == &src)
        return ( *this );
		
    delete[] _vector;

    _size=src._size;
    _count=src._count;
    _vector=new T[_size];
    for( int i = 0; i < _size; ++i) 
        _vector[i] = src._vector[i];

    return ( *this );
}


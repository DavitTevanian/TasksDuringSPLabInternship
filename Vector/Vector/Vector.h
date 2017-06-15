#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
using namespace std; 


template <typename T>
class vector {
public:
    class iterator{ 
    public:
	iterator( T* pointer):_pointer(pointer) {}
	iterator operator++() {
	    iterator it = *this;
	    _pointer ++;
	    return it;
	}
	iterator operator++(int garb) {
	    _pointer ++;
	    return *this;
	}
	T& operator*(){
            return *_pointer;
	}
	T* operator->(){
	    return _pointer;
	}
	bool operator==(const iterator& rhs){
	    return _pointer == rhs._pointer; 
	}

        bool operator!=(const iterator& rhs){
	    return _pointer != rhs._pointer; 
	}
    private:
	T* _pointer;
    };

    vector();
	inline bool operator==( const vector<T> & lhs ){
		if(lhs.size() == size()) {
        int count=0;
		for( int i = 0; i < lhs.size(); ++i)
			if( lhs[i] == _vector[i] )
                count++;
        if ( count == lhs.size() )
            return true;
        return false;
    }
    return false;
	}
    vector( int size, const T& item = T() );
    virtual ~vector();
    vector( const vector<T> & src );
    vector<T>& operator=( const vector<T> & src );
    void push( const T & item );
    void pop();
    T& front();
    T& back();
    bool empty();
    int size() const;
    int capacity() const;
    T& operator[]( int index );
    const T& operator[]( int index ) const;
	iterator begin(){
		return iterator(_vector);
	}
	iterator end(){
		return iterator(_vector + _size);
	}

protected:
    T* _vector; 
    int _size;  //size of vector
    int _count;  //count of elements in vector
    bool _flag;
    void _resize( int newSize );

};


#endif // _VECTOR_
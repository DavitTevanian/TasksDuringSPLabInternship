#include "polynom.h"
#include <map>

void Polynom::Insert ( const listPol & inputPolynom) {

  _polynom = inputPolynom; 

}

void Polynom::Print () {

  listPol::iterator it = _polynom.begin();
  if( it->first != 1 )
    cout<<it->first;
  if( it->second != 0 ) {
    if( it->second == 1 )
      cout<<"x";
    else 
      cout<<"x^"<<it->second;
  }
  ++it;

  for( ; it != _polynom.end(); ++it ) {
    if( it->first > 0 ) {
      cout<<"+";
      if( it->first != 1 )  
        cout<<it->first;
    }
    else { 
      if( it->first != -1 )
        cout<<it->first;
      else 
        cout<<"-";
    }
    if( it->second != 0 ) {
      if ( it->second == 1 )
        cout<<"x";
      else 
        cout<<"x^"<<it->second;
    }
  }

  cout<<endl;

}

void Polynom::Sort ( listPol & polynom ) {
  
  map < int,int > tempMap;
  for( listPol::const_iterator it = polynom.begin(); it != polynom.end(); ++it )
    tempMap.insert( make_pair( it->second,it->first));
  polynom.clear();
  for( map < int,int >::iterator it = tempMap.begin(); it != tempMap.end(); ++it )
    polynom.push_front( make_pair( it->second,it->first));
}

void Polynom::Pow () {

  listPol tempList;
  int coef,exp;

  listPol::iterator it = _polynom.begin();
  bool b = true; 
  while( it != _polynom.end() ) {

    for( listPol::iterator i = it; i != _polynom.end(); ++i ) {
      if(b) { 
        coef = it->first * i->first;
        exp = it->second<<1;
        b=false;
      }
      else {
        coef = 2 * it->first * i->first;
        exp = it->second + i->second;
      }
      tempList.push_back( make_pair (coef,exp));
    }
    b=true;
    ++it;
  }
   
  for( listPol::iterator iter = tempList.begin(); iter != tempList.end(); ++iter ) {

    for( listPol::iterator i = iter; i != tempList.end(); ++i ) {
      if(b) {  
        b = false;
        continue;
      }
      if( iter->second == i->second ) 
        iter->first += i->first;
    }
    b = true;
  }

  _polynom = tempList;
  Sort( _polynom );

}


int main () {

  Polynom pol;
  listPol inputPol; 

  inputPol.push_back( make_pair (-3,1));
  inputPol.push_back( make_pair (2,3));
  inputPol.push_back( make_pair (4,2));
  inputPol.push_back( make_pair (-1,5)); 
  inputPol.push_back( make_pair (3,0)); 

  pol.Insert( inputPol );
  pol.Pow();
  pol.Print();

  return 0;
}

#include "toRomanWord.h"

Convert::Convert (): _romanWord ("") { }

void Convert::Print () {
  cout<<_romanWord<<endl;
}

void Convert::ConvertToRoman ( unsigned num ) {

  if( num/1000 == 0 )
    _romanWord.append("");
  else
    for( unsigned i = 0; i < num/1000; ++i )
      _romanWord.append("M"); 

  num %= 1000;
  if( num/500 == 0 )
    _romanWord.append("");
  else
    _romanWord.append("D");

  num %= 500;
  if( num/100 == 0 )
    _romanWord.append("");
  else
    for( unsigned i = 0; i < num/100; ++i )
      _romanWord.append("C");

  num %= 100;
  if( num/50 == 0 )
    _romanWord.append("");
  else
    _romanWord.append("L");

  num %= 50;
  if( num/10 == 0 )
    _romanWord.append("");
  else
    for( unsigned i = 0; i < num/10; ++i )
      _romanWord.append("X");

  num %= 10;
  if( num/5 == 0 )
    _romanWord.append("");
  else
    _romanWord.append("V");

  num %= 5;
  if( num == 0 )
    _romanWord.append("");
  else
    for( unsigned i = 0; i < num; ++i )
      _romanWord.append("I");
}

int main() {

  Convert convert;
  unsigned num;
  cin>>num;
  convert.ConvertToRoman( num );
  convert.Print();
  return 0;

}

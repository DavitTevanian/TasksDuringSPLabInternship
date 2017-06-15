#include "romeMin.h"
#include <iostream>
#include <fstream>

RomeMin::RomeMin ():_romanWords ("") {}

RomeMin::~RomeMin () {}

void RomeMin::Print () { 

  cout<< _romanWords <<endl;

}

void RomeMin::AddToFile ( const string & fileName ) {

  ofstream outFile ( fileName.c_str(), ios::out );

  if ( !outFile.good() )
    cerr<< "File" + fileName + "can't open for write\n";

  else {
    outFile<< _romanWords;
    outFile.close();
  }
  
}

void RomeMin::_Check_I ( string & romeWord ) {

  string temp;
  int i, count = 1;
  bool check = false;
  size_t beg = romeWord.find_last_of ("I");
  size_t end = beg;

  if ( beg <= romeWord.size() ) {
    while ( (beg > 0) && (romeWord[--beg] == 'I') )
      ++count;
    if ( beg == 0 )
      check = true;
    for ( i = 0; i < count / 5; ++i )
      temp.append ("V");
    
    if ( count % 5 == 0 ) {
      if ( check )
        romeWord.replace ( beg, count, temp );
      else 
        romeWord.replace ( beg + 1, count, temp );   
    }

    else {
      if ( count % 5 == 4 ) {
        temp.append ("IV");
        if ( check )
          romeWord.replace ( beg, count, temp );
        else
          romeWord.replace ( beg + 1, count, temp );  
      }
      else {
        for ( i = 0; i < count % 5; ++i )
          temp.append ("I");
        if ( check )
          romeWord.replace ( beg, count, temp );
        else
          romeWord.replace ( beg + 1, count, temp );  
      }
    }
  }
 
}

void RomeMin::_Check_V ( string & romeWord ) {

  string temp;
  int i, count = 0;
  size_t beg = romeWord.find_last_of ("V");
  size_t end = beg;

  if ( beg <= romeWord.size() ) {
    if ( (romeWord[beg-1] == 'I') && ( romeWord[beg-2] == 'V') ) {
      beg -= 2;
      romeWord.replace ( beg, end - beg + 1, "IX");
    }
    while ( (beg > 0) && (romeWord[--beg] == 'V') )
      ++count;
    
    if ( count != 0 ) {
      for ( i = 0; i < count / 2; ++i )
        temp.append ("X");

      if ( count % 2 == 0 )
        romeWord.replace ( beg + 1, count, temp );

      else {
        temp.append ("V");
        romeWord.replace ( beg + 1, count, temp );
      }
    }
  }
  
}

void RomeMin::_Check_X ( string & romeWord ) {

  string temp;
  int i, count = 1;
  bool check = false;
  size_t beg = romeWord.find_last_of ("X");
  size_t end = beg;

  if ( beg <= romeWord.size() ) {
    if ( romeWord[beg-1] == 'I' ) {
      --beg;
      while ( (beg != 0) && (romeWord[--beg] == 'X') )
        ++count;
      --count;
    }
    else
      while ( (beg > 0) && (romeWord[--beg] == 'X') )
        ++count;
 
    if ( (beg == 0) && (romeWord[beg] == 'X') )
      check =true;

    for ( i = 0; i < count / 5; ++i )
      temp.append ("L");

    if ( count % 5 == 0 ) {
      if ( check )
        romeWord.replace ( beg, count, temp );
      else 
        romeWord.replace ( beg + 1, count, temp );
    }
     
    else {
      if ( count % 5 == 4 ) {
        temp.append ("XL");
        if ( check )
          romeWord.replace ( beg, count, temp );
        else
          romeWord.replace ( beg + 1, count, temp );
      }
      else {
        for ( i = 0; i < count % 5; ++i )
          temp.append ("X");
        if ( check )
          romeWord.replace ( beg, count, temp );  
        else 
          romeWord.replace ( beg + 1, count, temp );  
      }
    }
  } 
  
}

void RomeMin::_Check_L ( string & romeWord ) {

  string temp;
  int i, count = 0;
  size_t beg = romeWord.find_last_of ("L");
  size_t end = beg;

  if ( beg <= romeWord.size() ) { 
    if ( (romeWord[beg-1] == 'X') && ( romeWord[beg-2] == 'L') ) {
      beg -= 2;
      romeWord.replace ( beg, end - beg + 1, "XC");
    }
    
    while ( (beg > 0) && (romeWord[--beg] == 'L') )
      ++count;

    if ( count != 0 ) { 
      for ( i = 0; i < count / 2; ++i )
        temp.append ("C");

      if ( count % 2 == 0 )
        romeWord.replace ( beg + 1, count, temp );
      
      else {
        temp.append ("L");
        romeWord.replace ( beg + 1, count, temp );
      } 
    }
  }
  
}

void RomeMin::_Check_C ( string & romeWord ) {

  string temp;
  int i, count = 1;
  bool check = false;
  size_t beg = romeWord.find_last_of ("C");
  size_t end = beg;

  if ( beg <= romeWord.size() ) {
    if ( romeWord[beg-1] == 'X' ) {
      --beg;
      while ( (beg != 0) && (romeWord[--beg] == 'C') )
        ++count;
      --count;
    }
    else 
      while ( (beg > 0) && (romeWord[--beg] == 'C') )
        ++count;

    if ( (beg == 0) && (romeWord[beg] == 'C') )
      check = true;

    for ( i = 0; i < count / 5; ++i )
      temp.append ("D");

    if ( count % 5 == 0 ) {
      if ( check )
        romeWord.replace ( beg, end - beg, temp );
      else 
        romeWord.replace ( beg + 1, count, temp );  
    }

    else {
      if ( count % 5 == 4 ) {
        temp.append ("CD");
        if ( check )
          romeWord.replace ( beg, count, temp );
        else
          romeWord.replace ( beg + 1, count, temp );  
      }
  
      else {
        for ( i = 0; i < count % 5; ++i )
          temp.append ("C");
        if ( check )
          romeWord.replace ( beg, count, temp );  
        else 
          romeWord.replace ( beg + 1, count, temp );  
      }
    }
  }
  
}

void RomeMin::_Check_D ( string & romeWord ) {
 
  string temp;
  int i, count = 0;
  size_t beg = romeWord.find_last_of ("D");
  size_t end = beg;

  if ( beg <= romeWord.size() ) { 
    if ( (romeWord[beg-1] == 'C') && ( romeWord[beg-2] == 'D') ) {
      beg -= 2;
      romeWord.replace ( beg, end - beg + 1, "CM");
    }
    while ( (beg > 0) && (romeWord[--beg] == 'D') )
      ++count;
     
    if ( count != 0 ) { 
      for ( i = 0; i < count / 2; ++i )
        temp.append ("M");
 
      if ( count % 2 == 0 )
        romeWord.replace ( beg + 1, count, temp );

      else {
        temp.append ("D");
        romeWord.replace ( beg + 1, count, temp );
      }
    } 
  }

}

void RomeMin::_MinRomeWords ( string & romeWord ) {

  _Check_I ( romeWord );
  _Check_V ( romeWord );
  _Check_X ( romeWord );
  _Check_L ( romeWord );
  _Check_C ( romeWord );
  _Check_D ( romeWord );

}


void RomeMin::ChangeRomeWords () {

  ifstream inFile ( "rome.txt", ios_base::in );
  
  if ( !inFile.good() )
    cerr<< "File rome.txt can't open for read\n";

  else {
    string currentWord;

    while ( !inFile.eof() ) {
      getline ( inFile, currentWord );
      _MinRomeWords ( currentWord );
      _romanWords.append ( currentWord + "\n");
    } 

    inFile.close();
  }
 
}


int main () {
  
  RomeMin roman;
  roman.ChangeRomeWords ();
  string fileName;
  cin>> fileName;
  roman.AddToFile ( fileName );
  roman.Print();

  return 0;
}

#ifndef _ROMEMIN_

#define _ROMEMIN_

#include <string>
using namespace std;

class RomeMin {

  public:
    RomeMin ();
    ~RomeMin ();
    void Print ();
    void AddToFile ( const  string & fileName );
    void ChangeRomeWords ();
  private:
    void _MinRomeWords ( string & romeWord );
    void _Check_I ( string & romeWord );
    void _Check_V ( string & romeWord );
    void _Check_X ( string & romeWord );
    void _Check_L ( string & romeWord );
    void _Check_C ( string & romeWord );
    void _Check_D ( string & romeWord );
    string _romanWords;
};

#endif // _ROMEMIN_

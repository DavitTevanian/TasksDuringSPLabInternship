#include "Vector.h"
#include "Vector.cpp"
#include <string> 

int main() {

    vector<int> vectInt(11);
    vector<string> vectStr;
    vector<string> vectFix(4,"ball");
    vectStr.push("c++");
    vectStr.push("c#");
    vectStr.push("java");
    vectStr.push("python");
    for( int i = 0; i < vectInt.capacity(); ++i)
        vectInt[i] = i * i;
	
    cout<<"front: "<<vectInt.front()<<"  back: "<<vectInt.back()<<"\n\n";
    for( int i = 0; i < vectStr.size(); ++i)
        cout<<vectStr[i]<<"  ";
    cout<<"\n\nPrint content of vectStr through iterator\n\n";
    for(vector<string>::iterator it = vectStr.begin(); it != vectStr.end(); ++it)
	cout<<*it<<"  ";
    cout<<"\n";
    for( int i = 0; i < vectInt.size(); ++i)
        cout<<vectInt[i]<< " ";
    cout<<"\n\n";
    for( int i = 0; i < vectFix.size(); ++i)
        cout<<vectFix[i]<< " ";
    cout<<"\n\n";
    vector<string> temp;  //this case \ vector<string> temp=vectStr; \ invoked copy constructor
    temp=vectStr;
	
    if (vectStr == temp )
        cout<<"vectors are equal !\n";
    else 
        cout<<"vectors are not equal !\n";
    temp.pop();
    if ( vectStr == temp )
        cout<<"vectors are equal !\n";
    else 
        cout<<"vectors are not equal !\n";
	
    return 0;
}
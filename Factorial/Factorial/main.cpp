#include "Factorial.h"

int main() {
    cout<<"Enter number that you want\n";
    unsigned num;
    cin>>num;
    cout<<"Factorial of  "<<num<<"  is\n";
    Factorial fact;
    fact.FactOfBigDigit( num );
    fact.Print();
    return 0;
}
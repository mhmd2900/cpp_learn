#include<iostream>
#include<string>
// #include "../general/mlib.h"

using std::cout ;
using std::cin ;
using std::string ;

void mult ( int a , int b )
{
    cout << a*b << "\n" ;
}


int main ()
{
// mlib::reset_screen();
int a , b , c ;
a = 5 ;
b = 6 ;
a++ ;
b-- ;
c = a-b ;
cout << c ;


mult ( a , b );
mult ( b , c );

return 0 ;
}
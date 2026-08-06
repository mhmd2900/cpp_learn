#include <iostream>
using namespace std;

int climb ( int stairs , int sum)
{

// int a = 1 ;
// int b = 2 ;
// int sum = 0 ;
if ( stairs == 0 )  { sum +=1 ; return 0 ; } 
cout << 1 ;


return 1 + ( climb (stairs - 1 , sum ) ) ;


}



int main() 
{

 cout << climb ( 4 , 0 );

    return 0;
}
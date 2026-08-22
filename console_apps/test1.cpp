#include <iostream>
#include <vector>
#include"../general/mlib.h"

using std::string ;
using std::vector ;
using std::cin ;
using std::cout ;
using std::endl ;


void guess ( )
{

int num = 50 ;
int prev = 0 ;
int prev1 = 0 ;
int prev2 = 100 ;
char ch ;

do 
{
cout << num << " is this bigger or smaller ?  , b or s or correcr c " << endl ;
cin >> ch ;
prev = num ;

if ( ch == 'b')
{
prev1 = num ;
num =  ( num + prev1 ) /2 ;
}

else if ( ch == 's')
{
prev2 = num ;
num =  ( num + prev2 ) /2 ;
}

// prev1 = num ;
// prev2 = num ;

} while ( ch == 'b' || 's');



cout << " your number is " << num ;

}


int main() 
{
guess();

return 0 ;
}
    
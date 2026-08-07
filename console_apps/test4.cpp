#include <iostream>
using namespace std;

int climb ( int total_stairs , int& trials )
{


//int total_stairs ; 
int one_step  = 1 ;
int two_steps = 2 ;
int jump = 0 ;
//int trials = 0 ;
int num = 0 ;



if ( total_stairs <= 0 )  { trials +=1 ; return 0 ; } 
//cout << 1 ;

// if ( jump < 4 )
jump = 1 + ( climb (total_stairs - 1 , trials ) ) ;

// if (jump == 4 )
// jump = jump + 1 + ( climb (total_stairs + 2 , trials ) ) ;

trials += 1 ;

return trials ;


}
//  + 1 + ( climb (total_stairs - 2 , trials ) ) 


int main() 
{
int a = 0 ;
cout << climb ( 4 , a );

    return 0;
}
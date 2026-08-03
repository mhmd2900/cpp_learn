#include<iostream>
#include<cmath>
#include <cstdlib> // random
#include <ctime>  // random
#include"mlib.h"
using namespace std ;




///////////////////////////////////          reset screen
// Windows only (not portable)
// Slow (launches a new process)
// Security risk in some environments
void reset_screen ()
{
system ("cls");
system ( "color 0F") ;
}


//////////////////////////////////////      random
int get_random ( int from , int to )
{
  return rand()%( to - from + 1)+from ;
}
// needs                         <cstdlib>   and   <ctime>
// inside main function       srand((unsigned )time (NULL));




/////////////////////////////////////      check square root  babylion      Newton method
double my_sqrt(double num)
{
    if (num < 0) return -1;    // or NaN
    if (num == 0) return 0;    // avoid division by zero
    
    double g = num / 2;
    double prev_g;
    const double err = 0.0001;

    do {
        prev_g = g;
        g = (g + num / g) / 2;
    } while (fabs(g - prev_g) > err);

    return g;   // return, don't print
}





/////// function default parameters ,, the highest prpability to change go to rightmost position
// in this example , discount is from meal not total , then tax is applied , then tips
float receipt ( float meal , float tips = 0.05 , float tax = 0.15 , float discount = 0 ) 
{
    float total ;

    total  = (1-discount) * meal ;
    total *= (1+tax) ;
    total *= (1+tips) ;
    return total ;
}



int main ()
{
mlib::reset_screen();

cout << my_sqrt (16) << " \n" ;

cout << receipt (100) << " \n";
cout << receipt (100 , 0 ) << " \n";
cout << receipt (100 , 0 , 0.2 ) << " \n" ;
cout << receipt (100 , 0 , 0.2 , 0.5 ) << " \n" ;

return 0;
}
#include<iostream>
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



/////////////////////////////////////         input random
int input_random ( int from , int to )
{
  return rand()%( to - from + 1)+from ;
}


/////////////////////////////////////  check square root  babylion      Newton method
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





int main ()
{
mlib::reset_screen();



return 0;
}
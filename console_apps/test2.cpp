
#include <iostream>
using namespace std;

void climb1(int n) {
    
    if ( n == 0 )  { cout << "--\n";  return ;}

    cout << " begin \n";

    climb1(n-1);

    cout << " mid \n";

    cout << " end \n";
}



void climb2(int n) {
    
    if ( n == 0 )  { cout << "--\n";  return ;}

    cout << " begin \n";

    climb2(n-1);

    cout << " mid \n";

    climb2(n-1);

    cout << " end \n";
}



int climb3(int n) {
    
    if ( n == 0 )  { cout << "--\n";  return 0 ;}

    cout << " begin \n";

    // int sum = 0  ;
    //int sum = 
    climb3(n-1) + climb3(n-1);

    cout << " mid \n";

    cout << " end \n";
    return 0 ;
}

int main() {
    climb3(2) ;
    return 0;
}
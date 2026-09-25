#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "../general/mlib.h"
using namespace std ;


void fun ( int arr[] )  // taking a pointer {22,33,44}
{
cout << arr[0] << endl ;    // print index 0  ,,  which is 22 
}


void cal ( int x , int* y , int** z )  // x 3 (local)   ,  y 3 (pointer) ,  z 3 (pointer)
{
int d , f ;
++ **z  ;       //  x 3 , y 4 , z 4    // y and z point to the original a , not x  [ increase of y or z , increases a ]  
                                        // **z ++ not accepted   **z++ evaluates as ** (z++).
d = **z ;       // d = 4
f = *y + 1 ;    // f = 5      
*y +=2  ;       // x 3 , y 6 , z 6      d = 4    f = 5    // pointers do not update local d or f // they point to only 1 address ( address of a )
x +=5  ;        // x 8 , y 6 , z 6       d = 4    f = 5 ;

cout << x + d + f << endl ;   //  8 + 4 + 5     = 17
}



int main()
{

int arr [] = { 11,22,33,44} ;
fun ( arr + 1 );     
// arrays automatically decay into pointers when passed to functions.  
// Passing arr + 1 passes the address of the element at index 1 (22).
cout << arr[0] << "\n\n" ;     // no change to arr itself ( change was only to a temporary pointer )   ,,  result is 11




int a = 3 ;
int* b  = &a ;
int** c = &b ;
cal ( a , b , c );  //   3 (local)   ,  3 (pointer) ,  3 (pointer)  
cout << a + *b + **c << endl ;  // 6 + 6 + 6    =   18



}


#include<iostream>
#include<string>
#include<vector>
#include"mlib.h"
using namespace std ;


void swap ( int& a , int& b )
{
int temp ;
temp = a ;
a = b ;
b = temp ;
}


void swaps ( int arr[] , int size )
{
for ( int i = 0 ; i < size ; i ++)
swap (    arr [ mlib::input_random ( 0 , size -1 ) ]    ,   arr [ mlib::input_random( 0 , size -1 ) ]    ) ;
}


int main ()
{
mlib::reset_screen();




// Optimized loop limit
// for (int i = 0; i < size - 1; i++) 
//     swap(arr[i], arr[mlib::input_random(i, size - 1)]);


return 0 ;
}


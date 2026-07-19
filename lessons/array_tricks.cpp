#include<iostream>
#include<string>
#include<vector>
#include"mlib.h"
using namespace std ;



//////////////////////////                make array one by one    ( random or user )
void fill_array ( int numb , int arr2[] , int& index )
{
arr2[index] = numb  ;
index ++ ;
}// index = 0     in int main 


void split_array ( int size ,        int arr1[] ,int arr2[] ,int& index )
{
for ( int i = 0 ; i < size ; i ++ )
if (mlib::is_prime(arr1[i])) // if needed
fill_array ( arr1[i] , arr2 , index );
}   


///////////////////////                    make array total         ( random or user )
void make_array ( int arr[] , int size)
{
for ( int i = 0 ; i < size ; i ++ )
arr[i] = mlib::input_number(" plz enter number \n" , 1 , 100 );
}




////////////////////////////////////////         palindrome ,, mirror number
bool check_palindrome ( int arr[] , int size)
{
for ( int i = 0 ; i < size ; i ++)
if (arr[i] != arr [size-1-i] ) // 1 index instead of 2 indices ( if one increase and other decrease the same value )
return false ;
return true ;
}







///////////////////////////////////              distinct number ( copy repeated number only in 1st appearance )
bool check_distinct ( int arr[] , int index , int num ) // index as a size ( half of a loop )
{
for ( int i = 0 ; i < index ; i ++) // nested loop 
if ( num == arr [i] )
return false ;
return true ;
}
// num /= 10    same as     num = ( num - num % 10 ) / 10




////////////////////////////////////               Fisher-Yates Shuffle!     swap array

void mshuffle( int arr[] , int size )
{
for (int i = 0; i < size - 1 ; i++ )        
    swap(arr[i], arr[mlib::input_random( i , size - 1 )]); 
}

// 1- arr ( i )  : fix one side to avoid unswapped elements 
// 2- random(0, n-1) : wrong , as i need to avoid unlucky re-reversed same couple ( bias towards original order )  // nestd loop one direction
// 3- random(i+1, n-1) : wrong , an element can never stay in its original spot
// 4- i < size : wrong , no need to swap last element with itself 











int main ()
{
mlib::reset_screen();

///////////////////////////////                     sort array using other array

int arr[5] = { 5 , 2 , 1 , 0 , 6 } ;
int x = 0 ;

for ( int i = 0 ; i < 5 ; i ++ )
{
for ( int x = i ; x < 5 ; x ++ )  // 
{
if ( arr[i] > arr[x] )  // nested loop one condition
swap ( arr[i] , arr[x] ) ;
}
}

for ( int k = 0 ; k < 5 ; k ++ )
cout << arr[k] << endl ;





////////////////////////////////////              sort array within itself
int arr4 [5] = { 5 , 2 , 1 , 8 , 6 } ;
int arr5 [5] = {0} ;

for ( int i = 0 ; i < 5 ; i ++ )
{
int rep = 0 ;

for ( int x = 0 ; x < 5 ; x ++ )
{
if ( arr4[i] > arr4[x] ) // bigger take bigger index
rep ++ ;

if ( arr4[i] == arr4[x] && i > x ) // i != x   is wrong , // nestd loop one side
rep ++ ; // duplicate number move to next index
}
arr5[rep] = arr4[i] ;
}

for ( int u = 0 ; u < 5 ; u++ )
cout << arr5[u] << endl ;










/////////////////////////////////                      array bool ←→ array integer
bool arr1 [5]= { true , false , true , true , false };
int arr2 [3] = {0};
bool arr3 [6] = {0} ;

for ( int i = 0 , x = 0 ; i < 5 ; i ++ )     // bool to integer
{
if ( arr1[i] == 0 )
continue;
else
{arr2[x] = i ;
 x++ ;
}
}

for ( int y = 0 ; y < 3 ; y ++ )
cout << arr2[y] << endl ;


for ( int g = 0 ; g < 3 ; g++ )     // integer to bool
arr3[arr2[g]] = 1 ;


for ( int k = 0 ; k < 6 ; k++ )
cout << endl << arr3[k] ;






return 0 ;
}

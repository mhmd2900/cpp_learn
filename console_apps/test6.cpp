#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "../general/mlib.h"
using namespace std ;



int main()
{
char arr[5] = {'a', 'b', 'c', 'd', '\0'};       // same as  char arr[] = "abcd";   which Automatically includes '\0'
char* pp  ;
pp = arr ;



// &pp                                                      🧠🧠🧠  address of pointer   ⚠️⚠️⚠️
// &pp + 1                                                  🧠🧠🧠  address after poniter ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )

// &arr                                                      🧠🧠🧠  address of block   ⚠️⚠️⚠️
// &arr + 1                                                  🧠🧠🧠  address after block ( 5 items , each 4 bytes , so 20 bytes + )





cout << (void*)pp << endl ;
cout << (void*)arr << endl ;
cout << (void*)&arr[0] << endl << endl ;


cout << (void*)(pp +1 )<< endl ;
cout << (void*)(arr +1)  << endl ;
cout << (void*)&arr[1] << endl << endl ;


cout << (void*)(pp +2 ) << endl ;
cout << (void*)(arr + 2) << endl ;
cout << (void*)&arr[2] << endl << endl ;


cout << &arr << endl ;
cout << &arr + 1 << endl << endl ;
cout << &pp << endl ;
cout << &pp + 1 << endl << endl ;







// int a = 10 ;

// int 
// a = 10 , 
// *p      = &a  , 
// **pp    = &p  ,
// ***ppp  = &pp ;




// cout << p << "\n" ;      // a   address         🧠🧠🧠
// cout << *(&a) << "\n" ;  // value of a    11
// cout << *p << "\n" ;     // value of a    11    
// cout << &p << "\n\n" ;     // p  address         


// *p = 20 ;                                  // 🧠🧠🧠
// cout << a << "\n" ;  // 20         

// a = 30 ;
// cout << *p << "\n\n" ;  // 30





























// cout << (void*)pp << endl ;
// cout << (void*)arr << endl ;
// cout << (void*)&arr[0] << endl << endl ;


// cout << (void*)(pp +1 )<< endl ;
// cout << (void*)(arr +1)  << endl ;
// cout << (void*)&arr[1] << endl << endl ;


// cout << (void*)(pp +2 ) << endl ;
// cout << (void*)(arr + 2) << endl ;
// cout << (void*)&arr[2] << endl << endl ;


// cout << *pp << endl ;
// cout << *arr << endl ;
// cout << *(&arr[0]) << endl ;
// cout << pp[0] << endl ;
// cout << arr[0] << endl << endl ;
// cout << *(pp+1) << endl ;
// cout << *(arr+1) << endl ;
// cout << *(&arr[1]) << endl ;
// cout << pp[1] << endl ;
// cout << arr[1] << endl << endl ;

}
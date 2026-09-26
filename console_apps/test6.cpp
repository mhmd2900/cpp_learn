#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include "../general/mlib.h"
using namespace std ;



int main()
{
//int arr[5] = { 10 , 20 , 30 , 40 , 50 };                  // each item has specific address


// ⚠️⚠️⚠️ 1D array has 3 ways of addresses   ( array - element - pointer )

//int (*p)[5]     =  &arr;                               
// p              =  &arr                                      🧠🧠🧠  address of array      
// p + 1          =  &arr + 1✅                               🧠🧠🧠  address after array                +20 bytes   ( 5 elements * 4 bytes ) 

//int* pp = arr ;  ✅                                                // arr decays to apointer of its 1st element                    
// pp           = arr       =     &arr[0]                      🧠🧠🧠  address of element     
// pp + 1✅    = arr + 1✅ =     &arr[1]                      🧠🧠🧠  address after element              + 4 bytes   ( 1 element  * 4 bytes ) 
// pp + 2       = arr + 2   =     &arr[2]                      🧠🧠🧠  address after after element        + 8 bytes   ( 2 elements * 4 bytes ) 

// &p       or      &pp                                      🧠🧠🧠  address of pointer    
// &p       or      &pp + 1                                  🧠🧠🧠  address after poniter ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ 1D array has 2 ways of dereferencing values

// (*p)[0]   =   *(*p)       =   *(*p + 0)   =   (*p)[0]   =   10
// (*p)[1]   =   *(*p + 1)   =   *((*p) + 1) =   (*p)[1]   =   20


// *pp✅         =   *arr         =   *(&arr[0])    =    pp[0]✅   =   arr[0]        =  10
// *(pp + 1)✅   =   *(arr + 1)   =   *(&arr[1])    =    pp[1]✅   =   arr[1]        =  20

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//char arr[5] = {'a', 'b', 'c', 'd', '\0'};             // each item has specific address ( same as  char arr[] = "abcd"; )

// ⚠️⚠️⚠️ 1D char array has 3 ways of addresses   ( array - element - pointer )

//char (*p)[5] =  &arr;
// p         =  &arr                                        🧠🧠🧠  address of array
// p + 1     =  &arr + 1                                    🧠🧠🧠  address after array                +5 bytes   ( 5 elements * 1 byte ) 

//char* pp = arr ;                                               // arr decays to apointer of its 1st element
// (void*)pp     = (void*)arr     = (void*)&arr[0]          🧠🧠🧠  address of element
// (void*)(pp+1) = (void*)(arr+1) = (void*)&arr[1]          🧠🧠🧠  address + 1     as char is 1 byte
// (void*)(pp+2) = (void*)(arr+2) = (void*)&arr[2]          🧠🧠🧠  address + 2

// &p       or      &pp                                     🧠🧠🧠  address of pointer
// &p + 1   or      &pp + 1                                 🧠🧠🧠  address after pointer ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ Unique to char pointers with cout / printf

// pp       = arr       =    &arr[0]                        🧠🧠🧠  print string "abcd" ,  starting from arr[0]  till  find  \0
// pp + 1   = arr + 1   =    &arr[1]                        🧠🧠🧠  print string "bcd"  ,  starting from arr[1]  till  find  \0
// pp + 2   = arr + 2   =    &arr[2]                        🧠🧠🧠  print string "cd"   ,  starting from arr[2]  till  find  \0



// ⚠️⚠️⚠️ 1D array has 2 ways of dereferencing values

// (*p)[0]   =   *(*p)       =   *(*p + 0)   =   (*p)[0]   =   'a'
// (*p)[1]   =   *(*p + 1)   =   *((*p) + 1) =   (*p)[1]   =   'b'

// *pp          =   *arr         =   *(&arr[0])    =    pp[0]   =   arr[0]        =  'a'
// *(pp + 1)    =   *(arr + 1)   =   *(&arr[1])    =    pp[1]   =   arr[1]        =  'b'    `




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int arr[2][3] = { {10, 20, 30}, {40, 50, 60} };     // row-major order block (2 rows x 3 cols)

// ⚠️⚠️⚠️ 2D array has 4 ways of addresses   ( whole array - row - element - pointer )

//int (*p)[2][3] = &arr;  
// p         =  &arr                                          🧠🧠🧠  address of whole 2D array
// p + 1     =  &arr + 1 ✅                                   🧠🧠🧠  address after whole 2D array ( 6 items , each 4 bytes , so 24 bytes + )

//int (*pp)[3] = arr;     ✅                                        // arr decays to apointer of its 1st element
// pp           =  arr         =    &arr[0]                    🧠🧠🧠  address of row 0
// pp + 1✅    =  arr + 1✅   =    &arr[1]                    🧠🧠🧠  address of row 1 ( 3 items , each 4 bytes , so 12 bytes + )



//int *ppp = &arr[0][0];   //✅
// ppp       =  &arr[0][0]=    *arr                         🧠🧠🧠  address of element [0][0]
// ppp + 1✅ =  &arr[0][1]=    *arr + 1                     🧠🧠🧠  address + 4     as int is 4 bytes
// ppp + 3   =  &arr[1][0]=    *arr + 3                     🧠🧠🧠  address + 12    (moves to row 1, col 0)
// 2D array row-pointer decay ( *pp gives pointer to row's 1st element )
// *pp       =  *arr       =    &arr[0][0]                  🧠🧠🧠  address of element [0][0]
// *(pp + 1) =  *(arr + 1) =    &arr[1][0]                  🧠🧠🧠  address of element [1][0]



// &p       or      &pp         or      &ppp                🧠🧠🧠  address of pointer
// &p + 1   or      &pp + 1     or      &ppp + 1            🧠🧠🧠  address after pointer ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ 2D array has 3 ways of dereferencing values ( row 1, col 2 -> value 60 )

// (*p)[1][2]           =   *(*(*p + 1) + 2)                   =   60

// (*(pp + 1))[2]    =   *(*(pp + 1) + 2)    =   pp[1][2]✅    =   60
// *(arr[1] + 2)     =   *(*(arr + 1) + 2)   =   arr[1][2]      =   60

// *(ppp + 1*3 + 2)  =   *(ppp + 5)           =   ppp[5] ✅     =   60







}


#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"mlib.h"
using namespace std ;


/////////////////////////////////////////////////////////////    check prime
bool is_prime(int num) 
{
    if (num <= 1) return false;      
    if (num <= 3) return true;      
    if (num % 2 == 0 || num % 3 == 0) return false; 

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;  }

    return true;
}


 ///////////////////////////////////////////////////////////  prime in range ,,, Sieve of Eratosthenes!
vector<bool> sieve_of_eratosthenes(int limit) {
    vector<bool> is_prime(limit + 1, true);

    if (limit >= 0) is_prime[0] = false;
    if (limit >= 1) is_prime[1] = false;

    for (int i = 2; i * i <= limit; ++i) 
          { if (is_prime[i]) {
            for (int z = i * i; z <= limit; z += i)  is_prime[z] = false;   }
               
          }
    return is_prime;
}

// Print every number marked as prime
void print_primes(const vector<bool>& is_prime) {
    int limit = static_cast<int>(is_prime.size()) - 1;

    for (int x = 2; x <= limit; ++x) 
       { if (is_prime[x])  cout << x << "\t";  }
       cout << "\n";
}



///////////////////////////////////////////////////////////  prime in range

// check if a number is prime using the existing list of primes ( n is part of an array )
bool is_prime(int n, const std::vector<int>& primes) {
    if (n < 2) return false; 
    
    for (int p : primes) 
      { if (p * p > n)  break;  
        if (n % p == 0) return false; }
    
    return true; // 2 will escape as vector is empty ,, other primes will not break or return false
    // another function is needed to push back the true numbers index to that vector
}




/////////////////////////////////////////////////////      check square root  ( babylion - Newton method )
double my_sqrt(double num)
{
    if (num < 0) return -1;    // or NaN
    if (num == 0) return 0;    // avoid division by zero
    
    double g = num / 2;          // simple picking near number
    double prev_g;
    const double err = 0.0001;

    do {
        prev_g = g;
        g = (g + num / g) / 2;
       } while (fabs(g - prev_g) > err);  // fabs needs <cmath>

    return g;   
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
for ( int i = 0 ; i < index ; i ++) 
if ( num == arr [i] )
return false ;
return true ;
}   // num /= 10    same as     num = ( num - num % 10 ) / 10




//////////////////////////                make array one by one    ( random or user )
void fill_array ( int numb , int arr2[] , int& index )
{
arr2[index] = numb  ;
index ++ ;
}// index = 0     in int main 


void split_array ( int size ,        int arr1[] ,int arr2[] ,int& index )
{
for ( int i = 0 ; i < size ; i ++ )
if (is_prime(arr1[i])) // if needed
fill_array ( arr1[i] , arr2 , index );
}   


///////////////////////                    make array total         ( random or user )
void make_array ( int arr[] , int size)
{
for ( int i = 0 ; i < size ; i ++ )
arr[i] = mlib::get_number(" plz enter number \n" , 1 , 100 );
}





////////////////////////////////////               Fisher-Yates Shuffle!     swap array

void mshuffle( int arr[] , int size )
{
for (int i = 0; i < size - 1 ; i++ )        
    swap(arr[i], arr[mlib::get_random( i , size - 1 )]); 
}

// 1- arr ( i )  : fix one side to avoid unswapped elements 
// 2- random(0, n-1) : wrong , as i need to avoid unlucky re-reversed same couple ( bias towards original order )  // nestd loop one direction
// 3- random(i+1, n-1) : wrong , an element can never stay in its original spot
// 4- i < size : wrong , no need to swap last element with itself 




///////////////////////////////                     sort array using other array

void sort_array(int arr[], int size) 
{    for (int i = 0; i < size; i++) 
        // Start j from i + 1 to avoid comparing an element with itself
       { for (int j = i + 1; j < size; j++) 
             { if (arr[i] > arr[j])     swap(arr[i], arr[j]); }
       } 
}


void print_array(const int arr[], int size) {
    for (int k = 0; k < size; k++) 
        { cout << arr[k] << endl; }
}



////////////////////////////////////              sort array within itself
void sort_to_new_array(const int input[], int output[], int size) {
    for (int i = 0; i < size; i++) {
        int rep = 0;

        for (int x = 0; x < size; x++) {
            if (input[i] > input[x]) { // bigger takes bigger index
                rep++;
            }

            if (input[i] == input[x] && i > x) { // work only in one side
                rep++;
            }
        }
        output[rep] = input[i];
    }
}




/////////////////////////////////                      array bool ←→ array integer
int bool_to_indices(const bool bool_arr[], int bool_size, int index_arr[]) {
    int count = 0;
    for (int i = 0; i < bool_size; i++) {
        if (bool_arr[i] == true) {
            index_arr[count] = i; 
            count++;
        }
    }
    return count; 
}

void indices_to_bool(const int index_arr[], int index_size, bool bool_arr[], int bool_size) {
    for (int i = 0; i < bool_size; i++) {
        bool_arr[i] = false;
    }

    for (int g = 0; g < index_size; g++) {
        if (index_arr[g] >= 0 && index_arr[g] < bool_size) {
            bool_arr[index_arr[g]] = true;
        }
    }
}



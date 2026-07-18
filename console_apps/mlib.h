#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>  // fabs for sqrr
#include <cstdlib> // random
#include <ctime>  // random
#include <limits>   // input number
#include<iomanip>     // for setw
#include<cmath>     // sqrt  for prime
using namespace std ;

// using std::cin;
// using std::cout;
// using std::numeric_limits;
// using std::streamsize;

namespace mlib 
{

void reset_screen ()
{
system ("cls");
system ( "color 0F") ;
}

//////////////     input random
int input_random ( int from , int to )
{
return rand()%( to - from + 1)+from ;
}


//////////////    input number
int input_number ( string message , int from , int to )
{
cout << message ;
int num ;
while ( true )
{
if ( cin >> num && num >= from && num <= to)
return num ;
    
cout << " wrong input , repeat ";
cin.clear();
cin.ignore( numeric_limits<streamsize>::max() , '\n');// // ctrl z + cin.ignore >> write 2 inputs
}
}


///////////////////////////    input string
string input_word ( string message )
{
cout << message ;
string pass ; 
while ( true )
{     

if (getline(cin, pass) && !pass.empty())  // getline succeded + not empty
return pass;

//← getline succeded + empty    OR    FAILED (eof, failbit) + empty 
cin.clear();
cout << " input can not be empty !  ,  and EOF is not allowed \n";
}
}


///////////////////    input string ( charchters )
string input_wordch ( string message )
{  
    cout << message ;
    string password ;
    char ch ;
    while (true)
    {
        while ( cin.get(ch) )
        {
        if ( ch == '\r')
        continue ;
        if ( ch == '\n')
        break ;
        password += ch ;
        }

        if (! password.empty())
        return password ;

        else 
        {
        cin.clear();
        cout << " empty password , not acceted , repeat \n" ;
        }
    }
}

///////////////  want to repeat
bool want_to_repeat ()
{
cout << " Do you want to repeat ?   [y/n] \n";
char ch ;
while ( true )
{
if ( cin>>ch && ( ch =='y' || ch == 'Y'))
return true ;
else if ( ch =='n' || ch == 'N')
return false ;

cin.clear();
cout << " plz only enter y or n   , thank you   \n" ;
// cout << " input can not be empty !  ,  and EOF is not allowed \n"; // used only if invalid user input
// but , during 2nd recall of this function
// there is no way to diff. between user invalid input or remaining \n ( both not meet the condition )
}
}














//////////////// check prime
bool check_prime ( int num )
{
if ( num < 2 )
return false ;   //  0 , 1     to avoid skipping into 3rd return

for ( int x = 2 ; x <= num /2 ; x ++ ) // <=  to involve 4 and prevent its skipping to 3rd return
if ( num % x == 0 )
return false ;  

return true ;  // 2 , 3         skip to it 
}




//////////////// check prime in range        Sieve of Eratosthenes
void check_prime_inrange  ( vector<int>&vnum , int min , int max )   
{
vector<int>vtemp ( max , 0) ;   

     // corrupt values of certain indices ( give 1 )
 for ( int i = 2    ; i < sqrt(max) ; i++  ) // avoid redundant max/2
 if (vtemp[i] == 0)   // avoid redundant composite numbers  e.g   8 is multiple of 2 and 4 
    {
    for ( int x = i*i  ; x < max   ; x+=i ) 
    vtemp[x] = 1 ;
    }

    // convert indices of uncorrupted values ( given 0 ) to values and push in a vector
for ( int z = min ; z < max ; z++)
if ( z >= 2 && vtemp[z] == 0 )      
vnum.push_back(z);
}




/////////////////////////////////////  check square root  babylion
void sqrt_bab(double num)
{
 double g = num/2 ;  // initial guess
 double prev_g ;
 double err = 0.0001 ;

 do 
 {
 prev_g = g ;
 g = ( g + num/g) /2 ;
 }while ( fabs(g - prev_g)> err) ;

cout << g ;
 }








////////////// check distinct number ( copy repeated number only in 1st appearance )
bool check_distinct( int number , int arr [] , int index)
{
for ( int i = index -1 ; i >= 0 ; i --)
if ( number == arr[i])
return false ;

return true ;
}



//////////////////// check palindrome
bool check_palindrome ( int arr[] , int size)
{
for ( int i = 0 ; i < size ; i ++)
if (arr[i] != arr [size-1-i] )
return false ;
return true ;
}
















    //////////////////////////   make array one by one    ( random or user )
    void fill_array ( int numb , int arr2[] , int& index )
    {
        arr2[index] = numb  ;
        index ++ ;
    }// index = 0     in int main 

    void split_array (int arr1[] ,int arr2[] ,int size ,int& index )
    {
    for ( int i = 0 ; i < size ; i ++ )
    if (mlib::check_prime(arr1[i])) // if needed
    fill_array ( arr1[i] , arr2 , index );
    }


    ///////////////////////       make array total         ( random or user )
    void make_array ( int arr[] , int size)
    {
    for ( int i = 0 ; i < size ; i ++ )
        arr[i] = mlib::input_number(" plz enter number \n" , 1 , 100);
    }
    

    /////////////////////      make array from itself ( by swapping - irreversible )
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
     swap (  arr [ mlib::input_random ( 0 , size -1 ) ]   ,  arr [ mlib::input_random( 0 , size -1 ) ]  ) ;
    }


////////////////////////    make string from itself  ( with known key - reversible )
string crypt ( string password , int key )
{
for ( int i = 0 ; i < password.length() ; i ++ )
password[i] = static_cast<char> (static_cast<unsigned char>(password[i]) + key) ;
return password ;
}
// Yes, the conversion from int (or unsigned char) to char happens implicitly — 
// but you should still write the explicit static_cast<char> for 3 critical reasons:
// 🧭 Clarity & Intent — telling “I know this is a narrowing conversion, and I want it.”
// ⚠️ Without cast, some compilers will warn you about implicit narrowing.
// 🔍 Makes code more robust against future changes or stricter compiler settings.



/////////////////////////    make string from other string  ( with known key )
string decrypt ( string password , int key )
{
string pass ;
for ( int i = 0 ; i < password.length() ; i ++ )
// for ( char& i : password )
pass += static_cast<char>(static_cast<unsigned char>(password[i]) - key) ;
return pass ;
}



///////////////////////             print array
void print_array ( int arr[] , int size )
{
for ( int i= 0 ; i < size ; i ++ )
cout << arr[i] << " \t" ;
cout << endl ;
}


}













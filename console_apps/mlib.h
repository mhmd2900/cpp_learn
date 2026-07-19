#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>     // numeric_limits<streamsize>::max()
#include <cstdlib>    // rand , srand , system , exit
#include <ctime>      // time (input_random) , null
#include<iomanip>     // setw
using namespace std ;


// using std::string;
// using std::cin;
// using std::cout;
// using std::numeric_limits;
// using std::streamsize;




///////////////  reset screen
// Cross-platform: Works on Windows, Mac, and Linux.
// Instant: No background processes are launched.
// Secure: No risk of command injection.
void reset_screen()
{
    std::cout << "\033[2J\033[H";   // Clear + move cursor
    std::cout << "\033[0m";         // Ensure default colors
}





//////////////    input number
int input_number ( const string& message )
{
while ( true )
{
cout << message ;
int num ;

if ( cin >> num ) {  cin.ignore( numeric_limits<streamsize>::max() , '\n');   return num ; } // target
else if ( cin.eof() )  { cout << " EOF ... goodbye \n ";  exit(0); } // EOF                    ,, exit needs <cstdlib>
else if ( cin.fail())         { cin.clear();   cin.ignore( numeric_limits<streamsize>::max() , '\n');  cout << " failed input \n "; } // fail 
} 
}



//////////////    input number  ,,, function overloading
int input_number ( const string& message , int from , int to )
{
while ( true )
{
cout << message ;
int num ;

if ( cin >> num )        {  cin.ignore( numeric_limits<streamsize>::max() , '\n');   
                        if ( num >= from && num <= to )         return num ;     // target 
                        cout << " out of range \n" ; }                     // different choice
else if ( cin.eof() )         { cout << " EOF ... goodbye \n ";  exit(0); }               // EOF
else if ( cin.fail())         { cin.clear();   cin.ignore( numeric_limits<streamsize>::max() , '\n');  cout << " failed input \n "; } // fail 
} 
}

///////////////  want to repeat
bool want_to_repeat ()
{
while ( true )
{
cout << " Do you want to repeat ?   [y/n] \n";
char ch ;

if ( cin >> ch )  {     cin.ignore( numeric_limits<streamsize>::max() , '\n');  
                    if (ch == 'y' || ch == 'Y') return true;   // target
                    if (ch == 'n' || ch == 'N') return false;  // target
                    cout << "Invalid choice, please enter y or n\n";  }  // different choice
else if ( cin.eof())          {  cout << " EOF , goodbye \n" ;  exit(0) ; }  // EOF
else if ( cin.fail())         {  cin.clear();   cin.ignore( numeric_limits<streamsize>::max() , '\n'); cout << " failed input \n"; } // fail ( not char input )
}
} 







///////////////////////////    input string  
string input_word ( const string& message ) 
{
while ( true )
{     
cout << message ;
string pass ;   // tight scope

if (getline(cin, pass))    { if (!pass.empty())   return pass;                 // target
                              else  cout << " input can not be empty ! \n"; }  // different choice
else if (cin.eof())          {cout << " EOF , goodbye \n";   exit(0) ;}            // EOF  
}
}



///////////////////    input string ( charchters )
// You want to filter specific characters as they're typed (e.g., only allow digits)
// You want to hide password input (mask with *)
// You want to add character limits mid-typing
// You need special Windows \r\n handling for files from other systems
string input_word_ch ( const string& message )
{  
while (true)
{
  cout << message ;
  string password ; // fresh empty string each attempt
  char ch ; // narrow scope 

  while ( cin.get(ch) )  {
      if ( ch == '\r')   continue ;
      if ( ch == '\n')   break ;
      password += ch ;     }
      
  if (cin)  {  if (!password.empty())   return password ;   // target         ,, if (cin) means I/O succeeded (found \n)
                    cout <<  " empty password , not acceted , repeat \n" ;  }  // other option
  else if ( cin.eof())  { cout << " EOF , goodbye \n" ;  exit(0) ; } // EOF 
}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



bool is_prime(int num) {
    if (num <= 1) return false;      // 0 and 1 are not prime
    if (num <= 3) return true;       // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0) return false; // Eliminate evens and multiples of 3

    // We start at 5 and skip even numbers (i += 2)
    // We stop when i * i > num
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}




//////////////// check prime in range        Sieve of Eratosthenes    ,,,   function overloading
void check_prime  ( vector<int>&vnum , int min , int max )   
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








////////////////////////    make string from itself  ( with known key - reversible )   ,, Caesar cipher (toy example)
string crypt ( string password , int key )
{
for ( int i = 0 ; i < password.length() ; i ++ )
password[i] = static_cast<char> (static_cast<unsigned char>(password[i]) + key) ;
return password ;
}



/////////////////////////    make string from other string  ( with known key )
string decrypt ( string password , int key )
{
string pass ;
for ( int i = 0 ; i < password.length() ; i ++ )
// for ( char& i : password )
pass += static_cast<char>(static_cast<unsigned char>(password[i]) - key) ;
return pass ;
}



//////////////////////          layout alignment   ///////  need adjust
string align ( char side , int space , const string& word , char fill = ' ' )
{
int blanks = space - static_cast<int>(word.size()) ;
if ( blanks < 0 )   blanks = 0 ;
int l_pad = blanks/ 2 ;
int r_pad = blanks - l_pad ;

if ( side == 'l')
return word + string(blanks , fill)  ;

else if ( side == 'r')
return string(blanks , fill ) + word ;

else
return string( l_pad , fill ) + word + string( r_pad , fill ) ;
}














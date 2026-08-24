#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>     // std::numeric_limits<std::streamsize>::max()
#include <cstdlib>    // system , std::exit
#include <random>      // random



//using namespace std ;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;
// using std::numeric_limits;
// using std::streamsize;


namespace mlib
{


///////////////  reset screen
// Cross-platform: Works on Windows, Mac, and Linux.
// Instant: No background processes are launched.
// Secure: No risk of command injection.
void reset_screen()
{
    std::cout << "\033[2J\033[H";   // Clear + move cursor
    std::cout << "\033[0m";         // Ensure default colors
}




/////////////////////////////////////         input random 

int get_random(int from, int to) 
{
    // this std will be used once , do not pollute global namespace
    // static run ONCE during the whole program  
    static std::random_device rd;   // pick random number
    static std::mt19937 gen(rd());  // generates numbers from it
    std::uniform_int_distribution<int> distrib(from, to); // updates to your custom range every time you call 
    return distrib(gen);
}





//////////////    input number
int get_number ( const std::string& message )
{
while ( true )
{
std::cout << message ;
int num ;

if ( std::cin >> num ) {  std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');   return num ; } // target
else if ( std::cin.eof() )  { std::cout << " EOF ... goodbye \n ";  std::exit(0); } // EOF                    ,, std::exit needs <cstdlib>
else if ( std::cin.fail())         { std::cin.clear();   std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');  std::cout << " failed input \n "; } // fail 
} 
}



//////////////    input number  ,,, function overloading
int get_number ( const std::string& message , int from , int to )
{
while ( true )
{
std::cout << message ;
int num ;

if ( std::cin >> num )        {  std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');   
                        if ( num >= from && num <= to )         return num ;     // target 
                        std::cout << " out of range \n" ; }                     // different choice
else if ( std::cin.eof() )         { std::cout << " EOF ... goodbye \n ";  std::exit(0); }               // EOF
else if ( std::cin.fail())         { std::cin.clear();   std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');  std::cout << " failed input \n "; } // fail 
} 
}

///////////////  want to repeat
bool want_to_repeat (const std::string& message) // boolean names should be questionable
{
while ( true )
{
std::cout << message ;
char ch ;

if ( std::cin >> ch )  {     std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');  
                    if (ch == 'y' || ch == 'Y') return true;   // target
                    if (ch == 'n' || ch == 'N') return false;  // target
                    std::cout << "Invalid choice, please enter y or n\n";  }  // different choice
else if ( std::cin.eof())          {  std::cout << " EOF , goodbye \n" ;  std::exit(0) ; }  // EOF
else if ( std::cin.fail())         {  std::cin.clear();   std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n'); std::cout << " failed input \n"; } // fail ( not char input )
}
} 







///////////////////////////    input string  
std::string input_word ( const std::string& message ) 
{
while ( true )
{     
std::cout << message ;
std::string pass ;   // tight scope

if (std::getline(std::cin, pass))    { if (!pass.empty())   return pass;                 // target
                              else  std::cout << " input can not be empty ! \n"; }  // different choice
else if (std::cin.eof())          {std::cout << " EOF , goodbye \n";   std::exit(0) ;}            // EOF  
}
}



///////////////////    input string ( charchters )
// You want to filter specific characters as they're typed (e.g., only allow digits)
// You want to hide password input (mask with *)
// You want to add character limits mid-typing
// You need special Windows \r\n handling for files from other systems
std::string input_word_ch ( const std::string& message )
{  
while (true)
{
  std::cout << message ;
  std::string password ; // fresh empty std::string each attempt
  char ch ; // narrow scope 

  while ( std::cin.get(ch) )  {
      if ( ch == '\r')   continue ;
      if ( ch == '\n')   break ;
      password += ch ;     }
      
  if (std::cin)  {  if (!password.empty())   return password ;   // target         ,, if (std::cin) means I/O succeeded (found \n)
                    std::cout <<  " empty password , not acceted , repeat \n" ;  }  // other option
  else if ( std::cin.eof())  { std::cout << " EOF , goodbye \n" ;  std::exit(0) ; } // EOF 
}
}




////////////////////////    make std::string from itself  ( with known key - reversible )   ,, Caesar cipher (toy example)
std::string crypt ( std::string password , int key )
{
for ( size_t i = 0 ; i < password.length() ; i ++ )
password[i] = static_cast<char> (static_cast<unsigned char>(password[i]) + key) ;
return password ;
}



/////////////////////////    make string from other string  ( with known key )
std::string decrypt ( std::string password , int key )
{
std::string pass ;
for ( size_t i = 0 ; i < password.length() ; i ++ )
// for ( char& i : password )
pass += static_cast<char>(static_cast<unsigned char>(password[i]) - key) ;
return pass ;
}



////////////////////          layout alignment   
std::string align ( char side , int space ,  std::string_view word , char fill = ' ' )
{
int blanks = space - static_cast<int>(word.size()) ;
if ( blanks <= 0 )   return std::string(word); 

std::string result ;
result.reserve(space);

char s = std::tolower(static_cast<unsigned char>(side));

if ( s == 'l')
{ result.append(word) ;
  result.append ( blanks , fill ); }


else if ( s == 'r')
{ result.append ( blanks , fill ); 
  result.append(word) ;}

else
{ 
int l_pad = blanks/ 2 ;
int r_pad = blanks - l_pad ;

result.append(l_pad , fill);
result.append(word);
result.append(r_pad , fill);
}

return result ;
}




}









#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>   // input_number
#include <cstdlib>  // random , input_word 
#include <ctime>    // random
#include <cmath>    // for sqrt used in prime numbers ,, fabs for sqrr
#include<iomanip>     // for setw
using namespace std ;

// using std::cin;
// using std::cout;
// using std::numeric_limits;
// using std::streamsize;



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
                                                                      int input_number ( const string& message )
                                                                      {
                                                                          while ( true )
                                                                          {
                                                                          cout << message ;
                                                                          int num ;

                                                                          if ( cin >> num ) {  cin.ignore( numeric_limits<streamsize>::max() , '\n');   return num ; } // target
                                                                          if ( cin.eof() )  { cout << " EOF ... goodbye \n ";  exit(0); } // EOF                    ,, exit needs <cstdlib>
                                                                          cin.clear();  cin.ignore( numeric_limits<streamsize>::max() , '\n'); // remnant ( fail )  ,, needs <limits>
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
                                                                        else if ( cin.fail())         {  cin.clear();   cin.ignore( numeric_limits<streamsize>::max() , '\n'); cout << " failed input \n"; } // fail
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
                                                                       string input_wordch ( const string& message )
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
                                                                         arr[i] = mlib::input_number(" plz enter number \n" , 1 , 100 );
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
                                                                        swap (    arr [ mlib::input_random ( 0 , size -1 ) ]    ,   arr [ mlib::input_random( 0 , size -1 ) ]    ) ;
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


//////////////////////          layout alignment
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







                                                            

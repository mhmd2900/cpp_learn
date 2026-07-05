// #include <iostream>
// #include <string>
// #include <array>
// #include <vector>
// #include <limits>   // input_number
// #include <cstdlib>  // random , input_word 
// #include <ctime>    // random
// #include <cmath>    // for sqrt used in prime numbers ,, fabs for sqrr
// #include<iomanip>     // for setw
// using namespace std ;

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

                                                                                    if ( cin >> num ) {  cin.ignore( numeric_limits<streamsize>::max() , '\n');   return num ; }
                                                                                    if ( cin.eof() )  { cout << " EOF ... goodbye \n ";  exit(0); }
                                                                                    cout << " wrong input , repeat ";
                                                                                    cin.clear();  cin.ignore( numeric_limits<streamsize>::max() , '\n'); // needs <limits>
                                                                                    } 
                                                                                }



                                                                              //////////////    input number  ,,, function overloading
                                                                                int input_number ( const string& message , int from , int to )
                                                                                {
                                                                                    while ( true )
                                                                                    {
                                                                                    cout << message ;
                                                                                    int num ;

                                                                                    if ( cin >> num && num >= from && num <= to) {  cin.ignore( numeric_limits<streamsize>::max() , '\n');   return num ; }
                                                                                    if ( cin.eof() )  { cout << " EOF ... goodbye \n ";  exit(0); }
                                                                                    cout << " wrong input , repeat ";
                                                                                    cin.clear();  cin.ignore( numeric_limits<streamsize>::max() , '\n'); // needs <limits>
                                                                                    } 
                                                                                }



                                                                              ///////////////////////////    input string
                                                                              string input_word ( const string& message )
                                                                              {
                                                                                  while ( true )
                                                                                  {     
                                                                                  cout << message ;
                                                                                  string pass ;   // tight scope
    
                                                                                  if (getline(cin, pass) && !pass.empty())      return pass;          // target
                                                                                  if (cin.eof())          {cout << " EOF , goodbye \n";   exit(0) ;}  // EOF  ,  exit needs <cstdlib>
                                                                                  cout << " input can not be empty ! \n";                             // empty
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

                                                                                      if (!password.empty())   return password ;  // target
                                                                                      if ( cin.eof())  { cout << " EOF , goodbye \n" ;  exit(0) ; } // EOF  ,  exit needs <cstdlib>
                                                                                      cout << " empty password , not acceted , repeat \n" ; // empty
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

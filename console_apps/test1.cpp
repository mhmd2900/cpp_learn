#include<iostream>
#include<string>
#include<vector>
#include"../general/mlib.h"

using std::cout ;
using std::cin ;
using std::string ;
using std::vector ;
using std::endl ;



enum enuser { accountant = 1 , auditor = 2 , other = 3 } ;
enum enmenu { show = 1 , find = 2 , update = 3 , add = 4 , del = 5 , exit_app = 6 } ;

enuser current_user ;

void check_permission ()
{
int passcode = mlib::get_number(" enter your passcode \n ");
if      ( passcode == 123456)  { cout << " welcome   ,   accountant\n" ;    current_user = accountant ; } 
else if ( passcode == 123)     { cout << " welcome   ,   auditor \n"   ;    current_user = auditor    ; } 
else                           { cout << " you are not authorized  \n" ;    current_user = other      ; } 
}



void show_menu ()
{
cout << "=================================================================\n";
cout << "                       main menu screen                          \n";
cout << "=================================================================\n";
cout << "     [1] Show clients list. \n";
cout << "     [2] Find client. \n";
cout << "     [3] Update client. \n";
cout << "     [4] Add client. \n";
cout << "     [5] Remove client. \n";
cout << "     [6] Exit. \n";


}




int main()
{
check_permission () ;



show_menu ();


system("pause");
}



#include<iostream>
#include<string>
#include<cctype>
#include"mlib.h"
using namespace std;



enum enname { mhmd = 4719 , aly , meme = 3000 , soso , unknown };
enum enlocation { clinic , er , undefined };
enum endiagnosis { app , crohns , other };


struct stdoctor
     {  int age ;
        enname name ; };


struct stspeciality
     { enlocation location ;
       stdoctor doctor[3] ;  };


struct stpatient
     { endiagnosis diagnosis ;
       stspeciality medicine , surgery ; };


// ═══════════════════════════════
// PHASE 1: INPUT
// ═══════════════════════════════


string input_word ( const string& message )  // & due to string , const to protect it      // worker function
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


enname str_to_enname ( const string& name ) // & due to struct , const to protect it     //worker function
{
    string temp = name ;       for ( char& ch : temp ) ch = tolower(ch) ;     // tolower <cctype>
    
    if      ( temp == "mhmd" )   return enname::mhmd ;
    else if ( temp == "aly"  )   return enname::aly ;
    else if ( temp == "meme" )   return enname::meme;
    else if ( temp == "soso" )   return enname::soso ;
    else                         return enname::unknown ;
}



void read_hisdoctor_name ( stpatient& patient )   // & to modify parameters   // co-ordinator function
{
    for ( short i = 0 ; i < 3 ; i ++ )             patient.surgery.doctor[i].name = str_to_enname ( input_word ( " enter surgery doctor name \n")) ;
    for ( short i = 0 ; i < 3 ; i ++ )             patient.medicine.doctor[i].name = str_to_enname ( input_word ( " enter medicine doctor name \n")) ;
}



// ═══════════════════════════════
// PHASE 2: OUTPUT
// ═══════════════════════════════



string enname_to_str ( enname name  )  // enum is light
{
switch ( name )
    {    case enname::mhmd :    return  "mhmd";
         case enname::aly :     return  "aly" ;
         case enname::meme :    return  "meme";
         case enname::soso :    return  "soso";
         default :              return "not available";    }
}


void print_hisdoctor_name ( const stpatient& patient ) // & due to large struct , const to protect it
{
cout << " surgery  doctor names \n";         for ( short i = 0 ; i < 3 ; i ++ )               cout << " dr : " <<  enname_to_str ( patient.surgery.doctor[i].name  )<< " \t ";
cout << " \n medicine doctor names \n";      for ( short i = 0 ; i < 3 ; i ++ )               cout << " dr : " <<  enname_to_str ( patient.medicine.doctor[i].name )<< " \t ";
}



// *********************************************************************************************************************************************
// *********************************************************************************************************************************************

int main ()
{
mlib::reset_screen();

stpatient abdo , manal , anonymous[3]; 

read_hisdoctor_name  ( anonymous[1] ) ;  // driver function
print_hisdoctor_name ( anonymous[1] ) ;

return 0;    
}
return 0;    
}

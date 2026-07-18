#include<iostream>
#include<string>
#include<cctype>
#include"mlib.h"
using namespace std;



enum enname { mhmd = 4719 , aly , meme = 3000 , soso , unknown };
enum enlocation { clinic , er , undefined };
enum endiagnosis { app , crohns , other };


struct stdoctor
     {  int age = 0 ;
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


string input_word ( const string& message )  // & due to string , const to protect it      // function W ( worker )
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


enname str_to_enname ( const string& name ) // & due to string , const to protect it     // function W ( worker )
{
    string temp = name ;       for ( char& ch : temp )      ch = tolower(ch) ;     // tolower <cctype>
    
    if      ( temp == "mhmd" )   return enname::mhmd ;
    else if ( temp == "aly"  )   return enname::aly ;
    else if ( temp == "meme" )   return enname::meme;
    else if ( temp == "soso" )   return enname::soso ;
    else                         return enname::unknown ;
}



void read_surgerydoctor_name ( stpatient& patient )   // & to modify parameters  // function B ( co-ordinator )
{
    for ( auto& doctor : patient.surgery.doctor )  doctor.name = str_to_enname ( input_word ( " enter surgery doctor name \n")) ; // struct ( str_to_enname المحطة الاقرب للشارع  ) 
}

void read_medicinedoctor_name ( stpatient& patient )   // & to modify parameters    // function B ( co-ordinator )
{
	for ( auto& doctor : patient.medicine.doctor )    doctor.name = str_to_enname ( input_word ( " enter medicine doctor name \n")) ;
}

void read_hisdoctor_name ( stpatient& patient )   // & to modify parameters   // function A ( driver )
{
read_surgerydoctor_name ( patient );
read_medicinedoctor_name ( patient );
}



void read_defaultdoctor ( stpatient patient[] , int n )  // no & as it is array   // function A ( driver )
{
  for ( int i = 0 ; i < n ; i ++ )  // range lopp does not work with array parameter which works as a pointer ( size not known )
  {  
	cout << " for patient " << i + 1 << " plz " ;
	patient[i].surgery.doctor[0].name = str_to_enname ( input_word ( " enter default   MRP   doctor name  \n" )) ;
  }
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


void print_surgerydoctor_name ( const stpatient& patient ) // & due to large struct , const to protect it
{
// cout << " surgery  doctor names \n";         for ( int i = 0 ; i < 3 ; i ++ )                  cout << " dr : " <<  enname_to_str ( patient.surgery.doctor[i].name  )<< " \t "; // enname_to_str المحطة الاقرب للشارع ( struct )
cout << " surgery  doctor names \n";         for ( const auto& doctor : patient.surgery.doctor )     cout << " dr : " <<  enname_to_str ( doctor.name  )<< " \t "; // enname_to_str المحطة الاقرب للشارع ( struct )
}

void print_medicinedoctor_name ( const stpatient& patient ) // & due to large struct , const to protect it
{
// cout << " \n medicine doctor names \n";      for ( int i = 0 ; i < 3 ; i ++ )               cout << " dr : " <<  enname_to_str ( patient.medicine.doctor[i].name )<< " \t ";
cout << " \n medicine doctor names \n";      for ( const auto& doctor : patient.medicine.doctor )               cout << " dr : " <<  enname_to_str (doctor.name )<< " \t ";
}


void print_hisdoctor_name ( const stpatient& patient ) // & due to large struct , const to protect it
{
print_surgerydoctor_name ( patient ) ;
print_medicinedoctor_name ( patient ) ;
}



void print_defaultdoctor ( const stpatient patient[] , int n )  // no & as it is array
{
	cout << "  \n ====================================== \n  default ( MRP ) doctor of each patient is  :  \n  " ;
  for ( int i = 0 ; i < n ; i ++ )  
  cout << " for patient " << i + 1 << "    Dr : " << enname_to_str (patient[i].surgery.doctor[0].name) << endl ;
}


// *********************************************************************************************************************************************
// *********************************************************************************************************************************************

int main ()
{
mlib::reset_screen();

const int MAX_PATIENTS = 3 ; 
stpatient abdo , manal , anonymous[3] , patient[MAX_PATIENTS]; 

read_hisdoctor_name  ( anonymous[1] ) ;  
read_defaultdoctor(patient , MAX_PATIENTS);


print_hisdoctor_name ( anonymous[1] ) ;
print_defaultdoctor(patient , MAX_PATIENTS);

return 0;    
}

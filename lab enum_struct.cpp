#include<iostream>
#include<string>
#include<cctype>
#include"mlib.h"
using namespace std;



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

enum encode { mhmd = 4719 , aly , unknown };
enum enlocation { clinic , er , undefined };
enum endiagnosis { app , crohns , other };


struct stdoctor
{
encode code ;
};



struct stspeciality
{
enlocation location ;
stdoctor doctor[3] ;
};



struct stpatient
{
endiagnosis diagnosis ;
stspeciality medicine , surgery  ;
};


// Enum 
// 1) categorization : 
//     -- static casting ( with integers )                     cast a declared enum not int 
//     -- if statement ( with strings )                        e.g  str_to_encode  ,, after tolower
// 2) storage :
//     -- Enum                                                  by value
//     -- Enum is a part of struct                            ( ref with reading   ,,,  const ref with printing )       
// 3) output : 
//     -- Enum return its number
//     -- switch return anything                               e.g  encode_to_str                              




// Rule of thumb:
// ➤ Built-in types (int, char, double, bool) and Enums: Pass by value. as 4 bytes ( light enum ) faster than pass a pointer/address ( 8 bytes )
// ➤ Large objects (std::string, std::vector, structs , modern arrays ): 
            // ➤ If you’re modifying it     — pass by &
            // ➤ If you’re not modifying it — pass by const &
// ➤ c style arrays automatically "decays" into a pointer to its first element. So, int arr[3] actually becomes int* arr.



                                    encode str_to_encode ( const string& name ) // & due to large struct , const to protect it
                                    {
                                    string temp = name ;       for ( char& ch : temp ) ch = tolower(ch) ;     // tolower <cctype>

                                    if      ( temp == "mhmd" )  return encode::mhmd ;
                                    else if ( temp == "aly" )   return encode::aly ;
                                    else                        return encode::unknown ;
                                    }




                                    string encode_to_str ( encode name  )
                                    {
                                    switch ( name )
                                       {    case encode::mhmd :    return "mhmd";
                                            case encode::aly :     return "aly";
                                            default :              return "not available";    }
                                    }


void read ( stpatient& patient )   // & to modify parameters
{
for ( short i = 0 ; i < 3 ; i ++ )             patient.surgery.doctor[i].code  = str_to_encode ( input_word ( " enter surgery  doctor name \n")) ;
for ( short i = 0 ; i < 3 ; i ++ )             patient.medicine.doctor[i].code = str_to_encode ( input_word ( " enter medicine doctor name \n")) ;
}



void print ( const stpatient& patient ) // & due to large struct , const to protect it
{
cout << " surgery  doctor codes \n";         for ( short i = 0 ; i < 3 ; i ++ )               cout << " dr : " <<  encode_to_str ( patient.surgery.doctor[i].code  )<< " \t ";
cout << " \n medicine doctor codes \n";      for ( short i = 0 ; i < 3 ; i ++ )               cout << " dr : " <<  encode_to_str ( patient.medicine.doctor[i].code )<< " \t ";
}





int main ()
{
mlib::reset_screen();

stpatient abdo , manal ,   patient [3] ,    anonymous [] = {}  ;  // accepted 2D array :  flexible rows and fixed colums ( stspeciality , endiagnosis ) 

read  ( anonymous[1] ) ;
print ( anonymous[1] ) ;


return 0;    
}
return 0;    
}

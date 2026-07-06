#include<iostream>
#include<string>
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



                                    encode str_to_encode ( const string& name )
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

int main ()
{
mlib::reset_screen();

stpatient abdo , manal ;

for ( short i = 0 ; i <3 ; i++)           abdo.medicine.doctor[i].code= str_to_encode ( input_word ( " plz enter doctor name \n")) ;
for ( short i = 0 ; i <3 ; i++)           cout << encode_to_str ( abdo.medicine.doctor[i].code ) << "\t" << abdo.medicine.doctor[i].code << endl ;

return 0;    
}

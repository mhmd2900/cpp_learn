#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include"../general/mlib.h"

using std::cout ;
using std::cin ;
using std::string ;
using std::vector ;
using std::endl ;
using std::streamsize ;
using std::numeric_limits ;
using std::setw ;
using std::left ;
using std::right ;
using std::fstream ;
using std::ios ;
using std::getline ;
using std::ws ;
// using std::stoi ;
// using std::stod ;

// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

const string main_path    = "E:/m10.txt";
const string updated_path = "E:/m11.txt";
const string added_path   = "E:/m12.txt";
const string deleted_path = "E:/m13.txt";

enum enaccess { findx = 1<<0 , showx = 1<<1 , updatex = 1<<2 , addx = 1<<3 , delx = 1<<4 , exit_appx = 1<<5 } ;
enum enuser  
  { none       = 0 ,
    auditor    = findx | showx | exit_appx ,
    accountant = findx | showx | updatex | addx | delx | exit_appx }  ;  

enuser current_user = none ;

struct stclient 
{
int serial  ;
string name ;
string pin ;
double balance ;
bool activity = true ;
};



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                        active
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

string num_activity ( bool is_active )
{
if ( is_active == 1 )
return "active" ;
else 
return "not active" ;
}


bool num_activity ( string is_active )      // function overloading
{
if ( is_active == "active" )
return 1 ;
else 
return 0 ;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



stclient login_or_update ( stclient& client , bool add = false )
{

          cout<< " enter serial \n";
          cin >> client.serial ;

          cout<< " enter name \n";
          getline ( cin >> ws , client.name ) ;   
          
          if (add)
          { cout<< " enter pin \n";
          cin >> client.pin ; }

          cout<< " enter balance \n";
          cin >> client.balance ;
          
          cout<< " enter activity    , 1 active   , 0  not active \n";
          cin >> client.activity ;
          cout << "\n\n";

return client ;
}


vector<stclient> struct_to_vst (stclient& client )
{
vector<stclient> records ;
records.push_back(client) ;

return records ;
}





void write_file ( string path , vector<stclient>& client , bool check = true )  // default parameter
{
fstream mfile ;
mfile.open( path , ios::out | (check   ? ios::app   :  ios::trunc));
if ( mfile.is_open())
{
for ( auto& c : client )  mfile << c.serial  << "#//#" << c.name << "#//#"  << c.pin 
                                << "#//#"  << c.balance << "#//#" << num_activity(c.activity) << endl ;
mfile.close();
}
}



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



vector<string> split_string ( string sentence , const string separator )
{
vector<string>vWords ;
size_t pos = 0 ;
string word ;
  while ( ( pos = sentence.find(separator) ) != sentence.npos )
  {
  word = sentence.substr(0 , pos);
  vWords.push_back(word) ;
  sentence.erase( 0 , pos + separator.size() );
  }
if (!sentence.empty())
vWords.push_back(sentence) ;
return vWords ;
}


stclient fields_to_record ( vector<string> vRecord )
{
stclient stRecord ;
//if (!vRecord.empty())
{
stRecord.serial    = stoi(vRecord[0]) ;
stRecord.name      = vRecord[1] ;
stRecord.pin       = vRecord[2] ;
stRecord.balance   = stod(vRecord[3]) ;
stRecord.activity  = num_activity(vRecord[4]) ;
}
return stRecord ;
}


vector<stclient> read_file ( string path = main_path )
{
vector<string> vWords ;
vector<stclient> vFile ;
stclient client ;
string line ;
fstream mfile ;
mfile.open( path , ios::in );
if (mfile.is_open())
{
  while ( getline (mfile , line ))
  {
    if (line.empty()) continue;
    //if (!line.empty() && line.back()=='\r') line.pop_back();
  vWords = split_string(line , "#//#") ;
  client = fields_to_record(vWords);
  vFile.push_back(client);
  }
mfile.close();
}
return vFile ;
}


void show ( stclient client )
{
    {
  cout << "______________________________________\n";
  cout << "           client details         \n";
  cout << "______________________________________\n";
  cout << " serial    :  " << client.serial << "\n" ;
  cout << " name      :  " << client.name << "\n" ;
  cout << " pin       :  " << client.pin << "\n" ;
  cout << " balance   :  " << client.balance << "\n" ;
  cout << " activity  :  " << num_activity(client.activity) << "\n" ;
  cout << "______________________________________\n";
  }
}



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



void update ( string pin , vector<stclient>& vstFile , stclient& client )
{

for (auto& c : vstFile )
if ( c.pin == pin ) 
{ 
        do {
             {    vector<stclient> record ;
                  c = login_or_update(c) ;
                  record = struct_to_vst(c);
                  write_file ( updated_path , record )  ;
                  show (c) ;
             }
           } while ( mlib::want_to_repeat( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );
}
    write_file ( main_path , vstFile , false )  ; 
    cout << "           ......update done successfully......         \n";
}


void add ( string pin , vector<stclient>& vstFile , stclient& client )
{
  vector<stclient> record ;  
  client.pin = pin ;

        do {
             {              
                                         
                  client = login_or_update(client ) ;
                   record = struct_to_vst(client);
                  show (client) ;
             }
           } while ( mlib::want_to_repeat( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );
    vstFile.push_back(client) ;
    write_file ( added_path , record )  ;
    write_file ( main_path , vstFile , false )  ; 

}



void del ( string pin , vector<stclient>& vstFile , stclient& client )
{

// vector<stclient>::iterator it = vstFile.begin() ;

for ( auto it = vstFile.begin() ; it != vstFile.end() ;  )
{


}


}






bool find ( string pin , vector<stclient>& vstFile )
{
for (auto& c : vstFile )
if ( c.pin == pin )   return true ;
return false ;
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                               CHOICES
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


// ════════════════════════════════════════════════════════════════════════════════ 1 ════════════════════════════════════════════════════════════════


void show_client_list ( vector<stclient>& vstFile )
{
cout << "\n\n*********************************************************************\n";

int siz = vstFile.size()  ;
cout << right << setw(40) << " Client list ( " << siz << " )  client" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "____________________________________________________________________________\n";
cout << '|' << left << setw(15) << " serial" << '|' << left << setw(15) << " name" << '|' << left << setw(15) << " pin" << 
        '|' << left << setw(15) << " balance" << '|' << left << setw(10) << " activity" << '|'  << endl ;
cout << "____________________________________________________________________________\n\n";


for ( auto&c : vstFile )
cout << '|' << left << setw(15) << c.serial << '|' << left << setw(15) << c.name<< '|' << left << setw(15) << c.pin << 
        '|' << left << setw(15) << c.balance << '|' << left << setw(10) << c.activity << '|'  << endl ;
cout << "____________________________________________________________________________\n";

cout << "\n Press any key to return to main menu . . .\n ";

cout << "\n\n\n";
system("pause > 0 ");
}


// ════════════════════════════════════════════════════════════════════════════════════ 2 ════════════════════════════════════════════════════════════


void show_client ( vector<stclient>& vstFile )
{
string pin ;
stclient client ;
cout << "\n\n";
do {
cout << " Please , enter account PIN to search for .\n";
cin >> pin ;

  if (find( pin , vstFile ))
   show ( client ) ;

  else
   cout << " account does not exist \n";

} while ( mlib::want_to_repeat( "Do you want to show another client ?    y  or   n  \n"));

cout << "\n\n\n";

}


// ══════════════════════════════════════════════════════════════════════════════════════ 3 ══════════════════════════════════════════════════════════



void update_client ( vector<stclient>& vstFile )
{
string pin ;
stclient client ;

  do {
        cout << "\n\n plz enter pin to update \n";
        getline ( cin >> ws , pin);

        if ( find( pin , vstFile )) 
        update ( pin , vstFile , client ) ;

        else
        cout << " account does not exist \n";


     } while ( mlib::want_to_repeat( "Do you want to update another client ?    y  or   n  \n"  ) );



cout << "\n\n\n";
}


// ═════════════════════════════════════════════════════════════════════════════════════════ 4 ═══════════════════════════════════════════════════════

void add_client  ( vector<stclient>& vstFile )
{
string pin ;
stclient client ;

  do {
        cout << "\n\n plz enter pin to add \n";
        getline ( cin >> ws , pin);

        if ( ! find( pin , vstFile )) 
        add ( pin , vstFile , client ) ;

        else
        cout << " account already exists \n";


     } while ( mlib::want_to_repeat( "Do you want to add another client ?    y  or   n  \n"  ) );


cout << "\n\n\n";
 }


// ═════════════════════════════════════════════════════════════════════════════════════════ 5 ═══════════════════════════════════════════════════════

void delete_client  ( vector<stclient>& vstFile )
{
string pin ;
stclient client ;

  do {
        cout << "\n\n plz enter pin to delete \n";
        getline ( cin >> ws , pin);

        if ( find( pin , vstFile )) 
        del ( pin , vstFile , client ) ;

        else
        cout << " account does not exists \n";


     } while ( mlib::want_to_repeat( "Do you want to add another client ?    y  or   n  \n"  ) );


cout << "\n\n\n";
}






// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                       BIG BOSS
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


void check_permission ()
{
int passcode = mlib::get_number(" enter your passcode \n ");
if      ( passcode == 123)   { cout << " welcome   ,   accountant\n \n" ;    current_user = accountant ; } 
else if ( passcode == 1)     { cout << " welcome   ,   auditor   \n \n" ;    current_user = auditor    ; } 
else                         { cout << " not a member , want to sign Up ? \n \n" ;    exit(0)          ; } 
}









int show_menu ()
{
cout << "=================================================================\n";
cout << "                       main menu screen                          \n";
cout << "=================================================================\n";
cout << "     [1] Show clients list. \n";
cout << "     [2] Show client. \n";
cout << "     [3] Update client. \n";
cout << "     [4] Add client. \n";
cout << "     [5] Remove client. \n";
cout << "     [6] Exit. \n";
cout << "=================================================================\n";


int choice = mlib::get_number( " Choose which action to perform from  1  to  6  \n" , 1 , 6 ) ;

return choice ;
}



// *********************************************************************************************************************************************
// *********************************************************************************************************************************************
// *********************************************************************************************************************************************

int main()
{
//check_permission () ;
vector<stclient>vstFile ;
vstFile = read_file();

int choice = 0 ;


while ( choice != 6 )
{
choice = show_menu ();

  switch ( choice )
  {
  case 1 :
  show_client_list(vstFile);
  break ;

  case 2 :
  show_client(vstFile);
  break ;

  case 3 :
  update_client(vstFile);
  break ;

  case 4 :
  add_client(vstFile);
  break ;

  case 5 :
  delete_client(vstFile);
  break ;
 
  case 6 :
  break ;
  }
} 

cout << " We are happy for this visit     Thank you  ";

}



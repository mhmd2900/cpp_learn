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

enum enaccess { showy = 1<<0 , find = 1<<1 , update = 1<<2 , add = 1<<3 , del = 1<<4 , exit_app = 1<<5 } ;
enum enuser  
  { none       = 0 ,
    auditor    = showy | find | exit_app ,
    accountant = showy | find | update | add | del | exit_app }  ;  

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
          getline ( cin >> ws , client.name ) ;     // getline >> ws 
          
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

stclient record_to_fields ( string& record , string sep = "#//#" ) 
{
vector<stclient>vst_fields ;
stclient field ;

size_t pos = record.find(sep);
string copy = record.substr( 0 , pos );

field.serial = (copy.empty()) ? 0 : stoi(copy) ;
record.erase( 0 , copy.size() + sep.size());

pos = record.find(sep);
copy = record.substr( 0 , pos );
field.name = copy ;
record.erase( 0 , copy.size() + sep.size());

pos = record.find(sep);
copy = record.substr( 0 , pos );
field.pin = copy ;
record.erase( 0 , copy.size() + sep.size());

pos = record.find(sep);
copy = record.substr( 0 , pos );
field.balance = stod(copy) ;
record.erase( 0 , copy.size() + sep.size());

if(!record.empty())
field.activity = num_activity(record) ;

vst_fields.push_back(field);
return field ;
}


vector<stclient> read_file ( string path = main_path )
{
vector<stclient> vst_records ;
stclient client ;
string line ;
fstream mfile ;
mfile.open( path , ios::in );
if (mfile.is_open())
{
  while ( getline (mfile , line ))
  {
  client = record_to_fields(line);
  vst_records.push_back(client);
  }
mfile.close();
}
return vst_records ;
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


bool find_client ( string pin , vector<stclient>& vst_clients , stclient& client , bool update = false  )
{
bool available = false ;
for (auto& c : vst_clients )
if ( c.pin == pin ) 
{ 
available = true ;  
client = c ;

        if (update)   
        {
        do {
             {    vector<stclient> record ;
                  c = login_or_update(c) ;
                  record = struct_to_vst(c);
                  write_file ( updated_path , record )  ;
                  show (c) ;
             }
           } while ( mlib::want_to_repeat(" press y to modify these data   ,,     press n if correct   \n" ) );
                   write_file ( main_path , vst_clients , false )  ;
        }   
           break ;
} 
                  
return available ;
}



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                               CHOICES
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


// ════════════════════════════════════════════════════════════════════════════════ 1 ════════════════════════════════════════════════════════════════


void show_client_list ( vector<stclient>& printed_records )
{
cout << "\n\n*********************************************************************\n";

int siz = printed_records.size()  ;
cout << right << setw(40) << " Client list ( " << siz << " )  client" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "____________________________________________________________________________\n";
cout << '|' << left << setw(15) << " serial" << '|' << left << setw(15) << " name" << '|' << left << setw(15) << " pin" << 
        '|' << left << setw(15) << " balance" << '|' << left << setw(10) << " activity" << '|'  << endl ;
cout << "____________________________________________________________________________\n\n";


for ( auto&c : printed_records )
cout << '|' << left << setw(15) << c.serial << '|' << left << setw(15) << c.name<< '|' << left << setw(15) << c.pin << 
        '|' << left << setw(15) << c.balance << '|' << left << setw(10) << c.activity << '|'  << endl ;
cout << "____________________________________________________________________________\n";

cout << "\n Press any key to return to main menu . . .\n ";

cout << "\n\n\n";
system("pause > 0 ");
}


// ════════════════════════════════════════════════════════════════════════════════════ 2 ════════════════════════════════════════════════════════════


void show_client ( vector<stclient>& vst_clients )
{
string pin ;
stclient client ;
cout << "\n\n";
do {
cout << " Please , enter account PIN to search for .\n";
cin >> pin ;

  if (find_client( pin , vst_clients , client ))
   show ( client ) ;

  else
   cout << " account does not exist \n";

} while ( mlib::want_to_repeat( "Do you want to show another client ?    y  or   n  \n"));

cout << "\n\n\n";

}


// ══════════════════════════════════════════════════════════════════════════════════════ 3 ══════════════════════════════════════════════════════════



void update_client ( vector<stclient>& vst_clients )
{
string pin ;
stclient client ;
vector<stclient> record ;


  do {
        cout << "\n\n plz enter pin to update \n";
        getline ( cin >> ws , pin);

        if (find_client( pin , vst_clients , client , true ))
        cout << "           ......update done successfully......         \n";

        else
        cout << " account does not exist \n";


     } while ( mlib::want_to_repeat( "Do you want to update another client ?    y  or   n  \n"));



cout << "\n\n\n";
}


// ═════════════════════════════════════════════════════════════════════════════════════════ 4 ═══════════════════════════════════════════════════════


void delete_client ()
{




cout << "\n\n\n";
}

// ═════════════════════════════════════════════════════════════════════════════════════════ 5 ═══════════════════════════════════════════════════════



void add_client ()
{




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
vector<stclient>all_clients ;
all_clients = read_file();

int choice = 0 ;


while ( choice != 6 )
{
choice = show_menu ();

  switch ( choice )
  {
  case 1 :
  show_client_list(all_clients);
  break ;

  case 2 :
  show_client(all_clients);
  break ;

  case 3 :
  update_client(all_clients);
  break ;
 

  case 6 :
  break ;
  }
} 

cout << " We are happy for this visit     Thank you  ";

}



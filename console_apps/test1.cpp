
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


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

const string main_path    = "E:/m10.txt";  // or E:/m10.txt
const string updated_path = "E:/m11.txt";
const string added_path   = "E:/m12.txt";
const string deleted_path = "E:/m13.txt";
const string active_path  = "E:/m14.txt";

enum entrans  { depositx = 1 , withdrawx = 2 , balancesx = 3 , returnx = 4 } ;
enum enaccess { showx = 1 , findx = 2 , updatex = 3 , addx = 4 , delx = 5 , transx = 6 , exit_appx = 7  } ;
enum enacc    { findxx = 1<<0 , showxx = 1<<1 , updatexx = 1<<2 , addxx = 1<<3 , delxx = 1<<4 , transxx = 1<<5 , exit_appxx = 1<<6 } ;
enum enuser  
  { none       = 0 ,
    auditor    = findxx | showxx | transxx  | exit_appxx ,
    accountant = findxx | showxx | updatexx | addxx | delxx | transxx | exit_appxx } ;  

enuser current_user = none ;

struct stclient 
{
int serial  ;
string name ;
string pin ;
double balance ;
bool activity = false ;
};


string num_activity ( bool is_active );       // just declaration for later organization 
bool num_activity ( string is_active );       // function overloading   ✅✅✅



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     write
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
                                                                    // write 
                                                                    // string → st → vst

                                                                    // read
                                                                    // string → vs → st → vst


stclient login_or_update ( stclient& client , bool add = false )
{
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





void write_file ( string path , vector<stclient>& client , bool check = true )  // default parameter ✅✅✅
{
fstream mfile ;
mfile.open( path , ios::out | (check   ? ios::app   :  ios::trunc));
if ( mfile.is_open())
{
for ( int i = 0 ; i < client.size() ; i++)
  {
  mfile << (client[i].serial = i+1 )  << "#//#" << client[i].name << "#//#"  << client[i].pin 
  << "#//#"  << client[i].balance << "#//#" << num_activity(client[i].activity) << endl ;
  }
mfile.close();
}
}



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     read
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


vector<string> split_string ( string& sentence , const string separator )
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


stclient fields_to_record ( vector<string> vRecord , int& count)
{
stclient stRecord ;
//if (!vRecord.empty())
{
stRecord.serial    = count ;
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
int count = 1 ;
stclient client ;
string line ;
fstream mfile ;
mfile.open( path , ios::in );
if (mfile.is_open())
{
  while ( getline (mfile , line ))
  {
    if (line.empty()) continue;
  vWords = split_string(line , "#//#") ;
  client = fields_to_record(vWords , count );
  vFile.push_back(client);
  count ++ ;
  }
mfile.close();
}
return vFile ;
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
void show ( stclient client ) ;                                   // just declaration for later organization ✅✅✅
void update ( string pin , vector<stclient>& vstFile , stclient& client ); 
void add ( string pin , vector<stclient>& vstFile , stclient& client );
void del ( string pin , vector<stclient>& vstFile , stclient& client );
bool find ( string pin , vector<stclient>& vstFile ) ;


                                        //✅✅✅ Speed Performance : searching vst in RAM is better than searching the file itself in storage
bool find ( string pin , vector<stclient>& vstFile ) 
{
for (auto& c : vstFile )
if ( c.pin == pin )   return true ;
return false ;
}


string num_activity ( bool is_active )
{
if ( is_active == 1 )
return "active" ;
else 
return "not active" ;
}


bool num_activity ( string is_active )      
{
if ( is_active == "active" )
return 1 ;
else 
return 0 ;
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                               CHOICES
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


// ════════════════════════════════════════════════════════════════════════════════ show list ════════════════════════════════════════════════════════════════


void show_client_list ( vector<stclient>& vstFile )
{
system("cls");     
cout << "\n\n*********************************************************************\n";

int siz = vstFile.size()  ;
cout << right << setw(40) << " Client list ( " << siz << " )  client" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "____________________________________________________________________________\n";
cout << '|' << left << setw(15) << " serial" << '|' << left << setw(15) << " name" << '|' << left << setw(15) << " pin" << 
        '|' << left << setw(15) << " balance" << '|' << left << setw(10) << " activity" << '|'  << endl ;
cout << "____________________________________________________________________________\n\n";


for ( int i = 0 ; i < vstFile.size() ; i++)
//for ( auto&c : vstFile )
cout << '|' << left << setw(15) << i+1 << '|' << left << setw(15) << vstFile[i].name << '|' << left << setw(15) << vstFile[i].pin << 
        '|' << left << setw(15) << vstFile[i].balance << '|' << left << setw(10) << vstFile[i].activity << '|'  << endl ;
cout << "____________________________________________________________________________\n";

cout << "\n Press any key to return to main menu . . .\n ";
cout << "\n\n\n";
system("pause > 0 ");                       //✅✅✅ as there is no repeat option
}


// ════════════════════════════════════════════════════════════════════════════════════ show client ════════════════════════════════════════════════════════════
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

void show_client ( vector<stclient>& vstFile )
{
system("cls");     
string pin ;
cout << "\n\n";
do {
    cout << " Please , enter account PIN to search for .\n";
    cin >> pin ;

      if ( find( pin , vstFile )) 
              {
                  for (auto& c : vstFile )
                  {
                  if ( c.pin == pin )  
                    { show ( c ) ;  break ; }
                  }
              }
    else
      cout << " account does not exist \n";

} while ( mlib::want_to_repeat( "Do you want to show another client ?    y  or   n  \n"));

}


// ══════════════════════════════════════════════════════════════════════════════════════ update ══════════════════════════════════════════════════════════

void update ( string pin , vector<stclient>& vstFile )
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



void update_client ( vector<stclient>& vstFile )
{
system("cls");     
string pin ;
  do {
        cout << "\n\n plz enter pin to update \n";
        getline ( cin >> ws , pin);

        if ( find( pin , vstFile )) 
        update ( pin , vstFile ) ;

        else
        cout << " account does not exist \n";


     } while ( mlib::want_to_repeat( "Do you want to update another client ?    y  or   n  \n"  ) );

}


// ═════════════════════════════════════════════════════════════════════════════════════════ add ═══════════════════════════════════════════════════════
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


void add_client  ( vector<stclient>& vstFile )
{
system("cls");     
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

 }


// ═════════════════════════════════════════════════════════════════════════════════════════ delete ═══════════════════════════════════════════════════════

void del ( string pin , vector<stclient>& vstFile )
{

vector<stclient>::iterator it = vstFile.begin() ;
vector<stclient> record ;

        do {
             it = vstFile.begin() ; // // <--- Reset finger back to item #1 every time!( when enterd data are not correct)
             for ( ; it != vstFile.end() ; it++)
               {
                if ( it->pin == pin ) 
                {
                  record = struct_to_vst(*it);
                  write_file ( deleted_path , record )  ;
                  show (*it) ;   
                  break ; 
                }
                } 
           } while ( mlib::want_to_repeat( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );

    vstFile.erase( it );  
    write_file ( main_path , vstFile , false )  ; 

}


void delete_client  ( vector<stclient>& vstFile )
{
system("cls");     
string pin ;

  do {
        cout << "\n\n plz enter pin to delete \n";
        getline ( cin >> ws , pin);

        if ( find( pin , vstFile )) 
        del ( pin , vstFile ) ;

        else
        cout << " account does not exists \n";


     } while ( mlib::want_to_repeat( "Do you want to delete another client ?    y  or   n  \n"  ) );

// cout << "\n Press any key to return to main menu . . .\n ";
// system("pause > 0 ");                // ✅✅✅   no need to pause  as patient choose not to repeat
}

// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     transaction menu
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



void show_balances ( vector<stclient>& vstFile )
{
system("cls");     
double sum = 0 ;
cout << "\n\n*********************************************************************\n";

int siz = vstFile.size()  ;
cout << right << setw(40) << " Client list ( " << siz << " )  client" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "_______________________________________________________\n";
cout << '|' << left << setw(15) << " name" << '|' << left << setw(15) << " pin" << 
        '|' << left << setw(15) << " balance" << '|'  << endl ;
cout << "_______________________________________________________\n\n";


for ( int i = 0 ; i < vstFile.size() ; i++)
{ cout <<  '|' << left << setw(15) << vstFile[i].name << '|' << left << setw(15) << vstFile[i].pin << 
        '|' << left << setw(15) << vstFile[i].balance << '|' << endl ;   sum+= vstFile[i].balance ;}
cout << "________________________________________________________\n\n";


cout << " TOTAL BANK BALANCES IS         :    " << sum  ;

cout << "\n\n Press any key to return to main menu . . .\n ";
system("pause > 0 ");                 
}






void  do_deposit_withdraw ( string pin , vector<stclient>& vstFile , entrans trans )//✅✅✅  both same function 
{  
int tran  ;
vector<stclient> record ;
//if (trans == entrans::withdrawx )   tran *= -1 ;
for ( auto& c : vstFile )
{
if ( c.pin == pin )   
{
show(c);
    if ( mlib::want_to_repeat(" this is the account . Do you need to perform a transaction ?  y  or   n  \n " , 'y' , 'n'))
    {
    cout << " plz enter transaction amount \n ";
    cin >> tran ;
    if (trans == entrans::withdrawx )   
    {
    if (tran > c.balance )  {cout << " insufficient balance \n";  return ;}
    else
    tran *= -1 ;
    }
    cout << "old balance was " << c.balance << "    , now became  " << c.balance + tran  << "\n" ;
    c.balance += tran ;
    c.activity = 1 ;
                      record = struct_to_vst(c);
                      write_file ( active_path , record )  ;
                      write_file ( main_path , vstFile , false )  ; 
    }

    break ;
}
}
system("cls");
}




void deposit_withdraw ( vector<stclient>& vstFile , entrans trans )
{
system("cls");     // ✅✅✅  at the beginning of all independent functions
string pin ;

  do {
        cout << "\n\n please , enter account PIN for performing transactions \n";
        getline ( cin >> ws , pin);

        if ( find ( pin , vstFile )) 
        do_deposit_withdraw ( pin , vstFile , trans ) ;

        else
        cout << " account does not exists \n";


     } while ( mlib::want_to_repeat( "Do you want to perform another transaction ?    y  or   n  \n"  ) );
   
}



entrans show_transaction_menu ( vector<stclient>& vstFile )
{
cout << "=================================================================\n";
cout << "                    transaction menu screen                      \n";
cout << "=================================================================\n";
cout << "     [1] Deposit. \n";
cout << "     [2] Withdraw. \n";
cout << "     [3] Total balances. \n";
cout << "     [4] Return to main menu. \n";
cout << "=================================================================\n";


int choice = mlib::get_number( " Choose which action to perform from  1  to  4  \n" , 1 , 4 ) ;
return (entrans)choice ;
}




void transaction_menu  ( vector<stclient>& vstFile )
{
entrans choice ;

do {
system("cls");     
choice = show_transaction_menu(vstFile) ;
    switch(choice)
      {
        case entrans::depositx :
        deposit_withdraw ( vstFile , depositx );
        break ;

        case entrans::withdrawx :                
        deposit_withdraw ( vstFile , withdrawx );
        break ;

        case entrans::balancesx :
        show_balances ( vstFile );
        break ;

        case entrans::returnx :
        break ;
      }
}while ( choice != entrans::returnx ) ; 

system("cls");

}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                       MENU
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════


void check_permission ()
{
int passcode = mlib::get_number(" enter your passcode \n ");
if      ( passcode == 123)   { cout << " welcome   ,   accountant\n \n" ;    current_user = accountant ; } 
else if ( passcode == 1)     { cout << " welcome   ,   auditor   \n \n" ;    current_user = auditor    ; } 
else                         { cout << " not a member , want to sign Up ? \n \n" ;    exit(0)          ; } 
}




enaccess show_menu ()
{
cout << "=================================================================\n";
cout << "                       main menu screen                          \n";
cout << "=================================================================\n";
cout << "     [1] Show clients list. \n";
cout << "     [2] Show client. \n";
cout << "     [3] Update client. \n";
cout << "     [4] Add client. \n";
cout << "     [5] Remove client. \n";
cout << "     [6] Transction menu. \n";
cout << "     [7] Exit. \n";
cout << "=================================================================\n";


int choice = mlib::get_number( " Choose which action to perform from  1  to  7  \n" , 1 , 7 ) ;

return (enaccess)choice ;
}


// *********************************************************************************************************************************************
// *********************************************************************************************************************************************
// *********************************************************************************************************************************************


int main()
{
check_permission () ;
vector<stclient>vstFile ;
vstFile = read_file();
enaccess choice ;

do           // main() is clearly the boss. ✅✅✅ ماسكة خيوط اللعبة
{
system("cls");     
choice = show_menu ();
  switch ( choice ) 
  {

        case enaccess::showx :
        {
        if ( current_user == accountant || current_user == auditor )
        show_client_list(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;




        case enaccess::findx :
        {
        if ( current_user == accountant || current_user == auditor )
        show_client(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;



        case enaccess::updatex :
        {
        if ( current_user == accountant || current_user == auditor )
        update_client(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;




        case enaccess::addx :
        {
        if ( current_user == accountant )
        add_client(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;



        case enaccess::delx :
        {
        if ( current_user == accountant )
        delete_client(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;


        case enaccess::transx :
        {
        if ( current_user == accountant )
        transaction_menu(vstFile);
        else 
        cout << " not allowed \n";
        }
        break ;
      

        case enaccess::exit_appx :
        break ;
  }
} while ( choice != enaccess::exit_appx ) ;     // return to main menu ✅✅✅ spontaneously without calling specific function and chance for stack overflow

cout << " We are happy for this visit     Thank you  ";

}



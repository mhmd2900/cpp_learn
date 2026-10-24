
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
const string users_path   = "E:/users.txt";

enum enusers        { users_show = 1 , users_find = 2 , users_update = 3 , users_add = 4 , users_del = 5 , users_return = 6  } ;
enum entransaction  { tr_deposit = 1 , tr_withdraw = 2 , tr_balance = 3 , tr_return = 4 } ;
enum enmain         { main_show = 1 , main_find = 2 , main_update = 3 , main_add = 4 , main_del = 5 , main_trans = 6 , main_users = 7  , main_exit = 8  } ;
enum enprivilege    { pr_show = 1<<0 , pr_find = 1<<1 , pr_update = 1<<2 , pr_add = 1<<3 , pr_del = 1<<4 , pr_trans = 1<<5 , pr_users = 1<<6 , pr_exit = 1<<7 } ;


struct stusers
{
string username ;
int password = 0 ;
int privilege = 1 ;
};

struct stclient 
{
int serial = 0 ;
string name ;
string pin ;
double balance ;
bool activity = false ;
};



// ════════════════════════════════════════════════════════════════════  users  ═══════════════════════════=═══════════════════════════════════════

void show_signin ( stusers& user )
{
cout << "==============================\n";
cout << " username : " << user.username << "\n";
cout << " password : " << user.password << "\n";
cout << "==============================\n";
}

void access_denied ()
{
system("cls");
cout << "************************\n";
cout << "     Access denied      \n";
cout << "plz , contact your admin\n";
cout << "************************\n";
system("pause");
}



bool available_username ( string username , vector<stusers>&vstusers , bool signup = false ) // for search to update , for signup
{
for ( auto& u : vstusers )
if ( username == u.username )
{
  if ( signup == true ) cout << " choose different username \n";
  return true ;
}
return false ;
}

bool available_user     ( stusers signin_user , vector<stusers>&vstusers ) 
{
for ( auto& u : vstusers )
{
if ( u.username == signin_user.username && u.password == signin_user.password )
return true ;
}
cout << " invalid username/password    try again  \n\n";
return false ;
}

stusers retrieve_user  ( stusers signin_user , vector<stusers>&vstusers ) 
{
for ( auto& u : vstusers )
if ( signin_user.username == u.username && signin_user.password == u.password )
{
signin_user = u ;
break ;
}
return signin_user ;
} 


stusers sign_up ( vector<stusers>&vstusers  )
{
system("cls");  
stusers new_user ;
cout << "*************************************\n" ; 
cout << "*************  SIGN UP  *************\n" ; 
cout << "*************************************\n\n" ; 
 do {
      do {                                                                // ✅✅✅ nested do while 
            new_user.username = mlib::input_word(" enter username \n ") ;
            new_user.password = mlib::get_number (" enter password \n ") ;
          } while ( available_username ( new_user.username , vstusers , true ) ) ;
    show_signin(new_user) ;
    } while (mlib::repeat_vs_proceed(" y  if  correct         r to repeat " , 'r' , 'y' ));

cout << " \n welcome " << new_user.username << " \n Now , you are a member in HOSTILE BANK \n";
vstusers.push_back(new_user);
return new_user ;
}

stusers sign_in  ( vector<stusers>&vstusers  )
{
//system("cls");  
stusers signin_user ;
cout << "*************************************\n" ; 
cout << "*************  SIGN IN  *************\n" ; 
cout << "*************************************\n\n" ; 
int count = 0 ;
  do {                                                     
        signin_user.username = mlib::input_word(" plz , enter your user name \n");
        signin_user.password = mlib::get_number(" plz , enter your password  \n");
        count ++ ;
        if ( count >= 3 ) { cout << " multiple failed trials ,  thank you , good bye  ";  exit(0);}
      } while ( !available_user ( signin_user , vstusers ) ) ;
system("cls"); 
show_signin(signin_user) ;
cout << " \n welcome back  " << signin_user.username  << "\n press any key to return to menu \n  ";
system("pause>0") ;
return retrieve_user ( signin_user , vstusers )  ;
}

stusers sign     ( vector<stusers>&vstusers  )
{
//system("cls");
stusers user ;
cout << "\n\n============================++++++++++++++============================\n";
cout << "================             HOSTILE BANK             ================\n";
cout << "============================++++++++++++++============================\n\n";
char ch = mlib::repeat_vs_proceed(" press  y   if you have an account ,  press   n   to sign up \n") ;
  user = ch   ?  sign_in(vstusers)   :  sign_up(vstusers); 
return user ;
}


// ═══════════════════════════════════════════════════════════   write user ( string → st → vst → print ) ══════════════════════════════════════════════════

vector<stusers> struct_to_vst ( stusers& user )
{
vector<stusers> records ;
records.push_back(user) ;
return records ;
}

void write_file ( string path , vector<stusers>& users , bool append = true )  // default parameter ✅✅✅
{
fstream mfile ;
mfile.open( path , ios::out | (append   ? ios::app   :  ios::trunc)); //    bitwise OR operator |
if ( mfile.is_open())
{
for ( int i = 0 ; i < users.size() ; i++)
  {
  mfile << users[i].username << "#//#"  << users[i].password
  << "#//#"  << users[i].privilege << endl ;
  }
mfile.close();
}
}


// ══════════════════════════════════════════════════════════  read user ( string → vs → st → vst )  ══════════════════════════════════════════════════

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

stusers user_fields_to_record ( vector<string> vUsers , int& count )
{
stusers user ;
if (!vUsers.empty())
{
user.username      = vUsers[0] ;
user.password      = stoi(vUsers[1]) ;
user.privilege     = stoi(vUsers[2]) ;
// if ( user.username == "admin ")  user.privilege = -1 ;
}
return user ;
}

vector<stusers> user_read_file ( string path = users_path )
{
vector<string> vWords ;
vector<stusers> vFile ;
int count = 1 ;
stusers user ;
string line ;
fstream mfile ;
mfile.open( path , ios::in );
if (mfile.is_open())
{
  while ( getline (mfile , line ))
  {
    if (line.empty()) continue;
  vWords = split_string(line , "#//#") ;
  user = user_fields_to_record(vWords , count );
  vFile.push_back(user);
  count ++ ;
  }
mfile.close();
}
return vFile ;
}


// ═════════════════════════════════════════════════════════════════════   users menu   ═════════════════════════════════════════════════════════════

void show_user ( stusers& user )
{
    {
  cout << "______________________________________\n";
  cout << "               user details           \n";
  cout << "______________________________________\n";
  cout << " username       :  " << user.username << "\n" ;
  cout << " password       :  " << user.password<< "\n" ;
  cout << " permisiona     :  " << user.privilege<< "\n" ;
  cout << "______________________________________\n";
  }
}

void pre_show_user ( vector<stusers>& vstusers )
{
system("cls");     
stusers user ;
cout << "\n\n";
do {
    cout << " Please , enter username to search for .\n";
    getline ( cin , user.username );

      if (available_username ( user.username , vstusers ))
              {
                user = retrieve_user( user , vstusers );
                show_user ( user );
              }
    else
      cout << " user does not exist \n";

} while ( mlib::repeat_vs_proceed( "Do you want to show another user ?    y  or   n  \n"));
}



void customize_permissions ( stusers& user )
{
mlib::repeat_vs_proceed(" allow find client   (y/n) \n ")  ? user.privilege  |= pr_find   :  user.privilege=user.privilege  ;
mlib::repeat_vs_proceed(" allow update client (y/n) \n ")  ? user.privilege  |= pr_update   :  user.privilege=user.privilege  ;
mlib::repeat_vs_proceed(" allow add client    (y/n) \n ")  ? user.privilege  |= pr_add   :  user.privilege=user.privilege  ;
mlib::repeat_vs_proceed(" allow delete client (y/n) \n ")  ? user.privilege  |= pr_del   :  user.privilege=user.privilege  ;
mlib::repeat_vs_proceed(" allow transactions  (y/n) \n ")  ? user.privilege  |= pr_trans   :  user.privilege=user.privilege  ;
mlib::repeat_vs_proceed(" allow manage users  (y/n) \n ")  ? user.privilege  |= pr_users   :  user.privilege=user.privilege  ;
}

stusers update_add_user ( stusers& user )
{

          cout<< " enter password \n";
          cin >> user.password ;

          bool choice = mlib::repeat_vs_proceed ( "do you want to give him full access  (y/n)" ) ;
          if (choice)
            user.privilege = -1 ;
          else 
            customize_permissions ( user );

          cout << "\n\n";

return user ;
}

void update_user ( string username , vector<stusers>&vstusers )
{
vector<stusers> record ;
for (auto& c : vstusers )
if ( username == c.username ) 
{ 
        do {
             {    
                  c = update_add_user(c) ;
                  record = struct_to_vst(c);
                  show_user (c) ;
             }
           } while ( mlib::repeat_vs_proceed( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );
}   
    write_file ( users_path , vstusers , false )  ; 
    cout << "           ......update done successfully......         \n";
}

void pre_update_user ( vector<stusers>&vstusers )
{
system("cls");     
stusers user ;
  do {
        cout << "\n\n enter username to update \n";
        getline ( cin >> ws , user.username );

        if ( available_username( user.username , vstusers )) 
        update_user ( user.username , vstusers ) ;

        else
        cout << " user does not exist \n";

     } while ( mlib::repeat_vs_proceed( "Do you want to update another client ?    y  or   n  \n"  ) );

}



void show_users_list ( vector<stusers>& vstusers )
{
system("cls");     

int siz = vstusers.size()  ;
cout << right << setw(40) << " Users list ( " << siz << " )  user" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "____________________________________________________________________________\n";
cout << '|' << left << setw(15) << " username" << '|' << left << setw(15) << " password" << '|' << left << setw(15) << " permissions" << 
        '|'  << endl ;
cout << "____________________________________________________________________________\n\n";

for ( auto& u : vstusers)
cout << '|' << left << setw(15) << u.username << '|' << left << setw(15) << u.password << 
        '|' << left << setw(15) << u.privilege << '|'  << endl ;
cout << "____________________________________________________________________________\n";

cout << "\n Press any key to return to main menu . . .\n ";
system("pause > 0 ");                       //✅✅✅ as there is no repeat option
}



enusers show_users_menu ( vector<stusers>&vstusers , stusers& current_user )
{
cout << "=================================================================\n";
cout << "                         manage stusers                    "<< current_user.username << "\n";
cout << "=================================================================\n";
cout << "     1.  Users list. \n";
cout << "     2.  Show user. \n";
cout << "     3.  Update user. \n";
cout << "     4.  Add user. \n";
cout << "     5.  Remove user. \n";
cout << "     6.  Main menu. \n";
cout << "=================================================================\n";

int choice = mlib::get_number( " Choose which action to perform from  1  to  6  \n" , 1 , 6 ) ;
return (enusers)choice ;
}

void pre_users_menu  ( vector<stusers>&vstusers , stusers& current_user )
{
enusers choice ;

do {
system("cls");     
choice = show_users_menu(vstusers , current_user) ;
    switch(choice)
      {
        case users_show :
        show_users_list ( vstusers );
        break ;

        case users_find :                
        pre_show_user ( vstusers );
        break ;

        case users_update :
        pre_update_user ( vstusers );
        break ;

        case users_add :
        //show_balances ( vstFile );
        break ;

        case users_del :
        //show_balances ( vstFile );
        break ;

        case users_return :
        break ;
      }
}while ( choice != users_return ) ; 

system("cls");
}




// ════════════════════════════════════════════════════════════════════  clients    ══════════════════════════════════════════════════════════════════
string num_activity ( bool is_active );       // just declaration for later organization 
bool num_activity ( string is_active );       // function overloading   ✅✅✅


// ═══════════════════════════════════════════════════════════════    write client ( string → st → vst → print )   ══════════════════════════════════════════════════════════

stclient update_add_client ( stclient& client , bool add = false )
{
          cout<< " enter name \n";
          getline ( cin >> ws , client.name ) ;   
          
          if (add)
          { cout<< " enter pin \n";
          cin >> client.pin ; }

          cout<< " enter balance \n";
          cin >> client.balance ;
          
          client.activity = mlib::get_number(" enter activity    , 1 active   , 0  not active \n" , 0 , 1) ;
          cout << "\n\n";

return client ;
}

vector<stclient> struct_to_vst (stclient& client )
{
vector<stclient> records ;
records.push_back(client) ;
return records ;
}

void write_file ( string path , vector<stclient>& clients , bool append = true )  // default parameter ✅✅✅
{
fstream mfile ;
mfile.open( path , ios::out | (append   ? ios::app   :  ios::trunc)); //    bitwise OR operator |
if ( mfile.is_open())
{
for ( int i = 0 ; i < clients.size() ; i++)
  {
  mfile << (clients[i].serial = i+1 )  << "#//#" << clients[i].name << "#//#"  << clients[i].pin 
  << "#//#"  << clients[i].balance << "#//#" << num_activity(clients[i].activity) << endl ;
  }
mfile.close();
}
}

// ═══════════════════════════════════════════════════════════════  read  client ( string → vs → st → vst )   ═════════════════════════════════════════════════════════════

stclient fields_to_record ( vector<string> vRecord , int& count )
{
stclient stRecord ;
if (!vRecord.empty())
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

void show   ( stclient client ) ;                                   // just declaration for later organization ✅✅✅
void update ( string pin , vector<stclient>& vstFile , stclient& client ); 
void add    ( string pin , vector<stclient>& vstFile , stclient& client );
void del    ( string pin , vector<stclient>& vstFile , stclient& client );
bool find   ( string pin , vector<stclient>& vstFile ) ;


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

// ════════════════════════════════════════════════════════════════════════════════ show list ════════════════════════════════════════════════════════════════

void show_client_list ( vector<stclient>& vstFile )
{
system("cls");     

int siz = vstFile.size()  ;
cout << right << setw(40) << " Client list ( " << siz << " )  client" ; 
if ( siz > 1 ) cout << 's' ;
cout << endl ;

cout << "____________________________________________________________________________\n";
cout << '|' << left << setw(15) << " serial" << '|' << left << setw(15) << " name" << '|' << left << setw(15) << " pin" << 
        '|' << left << setw(15) << " balance" << '|' << left << setw(10) << " activity" << '|'  << endl ;
cout << "____________________________________________________________________________\n\n";


for ( int i = 0 ; i < vstFile.size() ; i++)
cout << '|' << left << setw(15) << i+1 << '|' << left << setw(15) << vstFile[i].name << '|' << left << setw(15) << vstFile[i].pin << 
        '|' << left << setw(15) << vstFile[i].balance << '|' << left << setw(10) << vstFile[i].activity << '|'  << endl ;
cout << "____________________________________________________________________________\n";

cout << "\n Press any key to return to main menu . . .\n ";
system("pause > 0 ");                       //✅✅✅ as there is no repeat option
}

// ════════════════════════════════════════════════════════════════════════════════════ show client ════════════════════════════════════════════════════════════
void show ( stclient client )
{
    {
  cout << "______________________________________\n";
  cout << "           client details         \n";
  cout << "______________________________________\n";
  //cout << " serial    :  " << client.serial << "\n" ;         // not yet added
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

} while ( mlib::repeat_vs_proceed( "Do you want to show another client ?    y  or   n  \n"));

}

// ══════════════════════════════════════════════════════════════════════════════════════ update ══════════════════════════════════════════════════════════

void update ( string pin , vector<stclient>& vstFile )
{
vector<stclient> record ;
for (auto& c : vstFile )
if ( c.pin == pin ) 
{ 
        do {
             {    
                  c = update_add_client(c) ;
                  record = struct_to_vst(c);
                  show (c) ;
             }
           } while ( mlib::repeat_vs_proceed( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );
  write_file ( updated_path , record )  ;
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


     } while ( mlib::repeat_vs_proceed( "Do you want to update another client ?    y  or   n  \n"  ) );

}

// ═════════════════════════════════════════════════════════════════════════════════════════ add ═══════════════════════════════════════════════════════
void add ( string pin , vector<stclient>& vstFile , stclient& client )
{
  vector<stclient> record ;  
  client.pin = pin ;

        do {
             {              
                                         
                  client = update_add_client(client ) ;
                  record = struct_to_vst(client);
                  show (client) ;
             }
           } while ( mlib::repeat_vs_proceed( " are these enetred data correct ?    y  or   n  \n"  , 'n'  ,  'y'  ) );
    write_file ( added_path , record )  ;
    vstFile.push_back(client) ;
    write_file ( main_path , vstFile , false )  ; 
    cout << "           ......account added successfully......         \n";

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


     } while ( mlib::repeat_vs_proceed( "Do you want to add another client ?    y  or   n  \n"  ) );

 }

// ═════════════════════════════════════════════════════════════════════════════════════════ delete ═══════════════════════════════════════════════════════

void del ( string pin , vector<stclient>& vstFile )
{
vector<stclient>::iterator it = vstFile.begin() ;
vector<stclient> record ;

             for ( ; it != vstFile.end() ; it++)
                if ( it->pin == pin ) 
                {
                  record = struct_to_vst(*it);
                  show (*it) ;   
                  break ; 
                }

      if ( mlib::repeat_vs_proceed( " sure to delete this acoount  ?  y to confirm     c to cancel "  , 'y' , 'c'))
      {
        write_file ( deleted_path , record )  ;
        vstFile.erase( it );  
        write_file ( main_path , vstFile , false )  ; 
        cout << "           ......account deleted successfully......         \n";
      }
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


     } while ( mlib::repeat_vs_proceed( "Do you want to delete another client ?    y  or   n  \n"  ) );

// system("pause > 0 ");                // ✅✅✅   no need to pause  as patient choose not to repeat
}

// ══════════════════════════════════════════════════════════════════   transaction menu   ═════════════════════════════════════════════════════════════

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

void  do_deposit_withdraw ( string pin , vector<stclient>& vstFile , entransaction trans )//✅✅✅  both same function 
{  
int tran  ;
vector<stclient> record ;
//if (trans == entransaction::tr_withdraw )   tran *= -1 ;
for ( auto& c : vstFile )
{
if ( c.pin == pin )   
{
show(c);
    if ( mlib::repeat_vs_proceed(" this is the account . Do you need to perform a transaction ?  y  or   n  \n " , 'y' , 'n'))
    {
    cout << " plz enter transaction amount \n ";
    cin >> tran ;
    if (trans == entransaction::tr_withdraw )   
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

void deposit_withdraw ( vector<stclient>& vstFile , entransaction trans )
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


     } while ( mlib::repeat_vs_proceed( "Do you want to perform another transaction ?    y  or   n  \n"  ) );
   
}

entransaction show_transaction_menu ( vector<stclient>& vstFile , stusers& current_user )
{
cout << "=================================================================\n";
cout << "                    transaction menu screen              " << current_user.username << "\n";
cout << "=================================================================\n";
cout << "     [1] Deposit. \n";
cout << "     [2] Withdraw. \n";
cout << "     [3] Total balances. \n";
cout << "     [4] Return to main menu. \n";
cout << "=================================================================\n";


int choice = mlib::get_number( " Choose which action to perform from  1  to  4  \n" , 1 , 4 ) ;
return (entransaction)choice ;
}

void transaction_menu  ( vector<stclient>& vstFile , stusers& current_user )
{
entransaction choice ;

do {
system("cls");     
choice = show_transaction_menu(vstFile , current_user) ;
    switch(choice)
      {
        case entransaction::tr_deposit :
        deposit_withdraw ( vstFile , tr_deposit );
        break ;

        case entransaction::tr_withdraw :                
        deposit_withdraw ( vstFile , tr_withdraw );
        break ;

        case entransaction::tr_balance :
        show_balances ( vstFile );
        break ;

        case entransaction::tr_return :
        break ;
      }
}while ( choice != entransaction::tr_return ) ; 

system("cls");

}

// ════════════════════════════════════════════════════════════════════     MENU      ═══════════════════════════════════════════════════════════════

enmain show_menu ( stusers& current_user )
{

cout << "=================================================================\n";
cout << "                       main menu screen                  "<< current_user.username << "\n";
cout << "=================================================================\n";
cout << "     [1] Show clients list. \n";
cout << "     [2] Show client. \n";
cout << "     [3] Update client. \n";
cout << "     [4] Add client. \n";
cout << "     [5] Remove client. \n";
cout << "     [6] Transction menu. \n";
cout << "     [7] Manage stusers. \n";
cout << "     [8] Logout. \n";
cout << "=================================================================\n";


int choice = mlib::get_number( " Choose which action to perform from  1  to  8  \n" , 1 , 8 ) ;

return (enmain)choice ;
}

// *********************************************************************************************************************************************
// *********************************************************************************************************************************************
// *********************************************************************************************************************************************


int main()
{


vector<stusers>vstusers = {{ "admin" , 1234 , -1 }} ;      //✅✅✅
vstusers = user_read_file(users_path);
stusers current_user = sign ( vstusers );

vector<stclient>vstFile ;
vstFile = read_file();

enmain choice ;

do           // main() is clearly the boss. ✅✅✅ ماسكة خيوط اللعبة
{
  system("cls");     
  choice = show_menu (current_user);
  switch ( choice ) 
  {
        case enmain::main_show :
        if ( current_user.privilege & pr_show )              show_client_list(vstFile);
        else                                                 access_denied ();
        break ;

        case enmain::main_find :
        if ( current_user.privilege & pr_find )              show_client(vstFile);
        else                                                 access_denied ();
        break ;


        case enmain::main_update :
        if ( current_user.privilege & pr_update )             update_client(vstFile);
        else                                                  access_denied ();
        break ;

        case enmain::main_add :
        if ( current_user.privilege & pr_add )                add_client(vstFile);
        else                                                  access_denied ();
        break ;

        case enmain::main_del :
        if ( current_user.privilege & pr_del )                delete_client(vstFile);
        else                                                  access_denied ();
        break ;

        case enmain::main_trans :
        if ( current_user.privilege & pr_trans )              transaction_menu(vstFile , current_user);
        else                                                  access_denied ();
        break ;

        case enmain::main_users :
        if ( current_user.privilege & pr_users )              pre_users_menu(vstusers , current_user);
        else                                                  access_denied ();
        break ;

        case enmain::main_exit :
        break ;
  }
} while ( choice != enmain::main_exit ) ;     // return to main menu ✅✅✅ spontaneously without calling specific function and chance for stack overflow


cout << " \n\n We are happy for your visit     Thank you  \n\n";
cout << "===================================================";
}


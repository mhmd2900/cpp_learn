#include<iostream>
#include<fstream>
#include"../general/mlib.h"

using namespace std ;

const string path = "E:/clients.txt" ;

struct stclient 
{
string name ;
string pin ;
double balance ;
};


// vector<string> split_string ( string line , string delim = "#//#")
// {
// int pos = 0 ;
// string word ;
// vector<string>vector_of_words ;

// if ( (pos = line.find(delim)) != line.npos )
// {
// word = line.substr( 0 , pos ) ;
// vector_of_words.push_back(word);
// line.erase( 0 , pos + delim.size() ) ;
// }

// if ( ! line.empty() )
// vector_of_words.push_back(line);
// return vector_of_words ;
// }
bool check_file_string ( stclient& login_data , string line , string delim = "#//#")
{
int pos = 0 ;
int prev ;
stclient client ;
int count = 0 ;
string::iterator string_iter = line.begin();

while ( ! line.empty() && string_iter != line.end())
{

prev = pos ;
    if ( (pos = line.find(delim) ) != line.npos )
    {
        if ( count == 1 )
        {
        client.name = line.substr( prev + delim.size()  , pos ) ;
        }


        if ( count == 2 )
        {
        client.pin = line.substr( prev + delim.size()  , pos ) ;
        break ;
        }
    }
count ++ ;
string_iter ++ ;
}

if (client.name == login_data.name &&
    client.pin == login_data.pin)                    return true ;
return false ;

}


// stclient words_to_stclient ( vector<string>& vector_of_words )
// {
// stclient client ;
// if ( ! vector_of_words.empty())
// {
// client.name = vector_of_words[1];
// client.pin = vector_of_words[2];
// client.balance = stod(vector_of_words[3]);
// }
// return client ;
// }


bool read_file ( stclient& login_data )
{
fstream mfile ;
string line ;

mfile.open ( path , ios::in );
if ( mfile.is_open())
{
    while ( getline ( mfile , line  ))  
    {
    if (check_file_string( login_data , line ))
    return true ;
    }
mfile.close();
}
return false ;
}


// void write_file ( vector<stclient>& clients , string delim = "#//#")
// {
// fstream mfile ;
// mfile.open ( path , ios::app );
// if ( mfile.is_open( ))
// {
//     for ( int i = 0 ; i < clients.size() ; i ++ )
//     {
//       if ( ! clients.empty())
//       mfile << clients[i].name << delim << clients[i].pin << delim << clients[i].balance << endl ;
//     }

// mfile.close();    
// }
// }



// void is_client_available_spypointer ( stclient login_data )
// {
// fstream mfile ;
// string line ;
// vector<string>vector_of_words ;
// stclient client ;
// vector<stclient>vstclients ;

// mfile.open( path , ios::in );
// if ( mfile.is_open())
// {
//     while ( getline ( mfile , line  ))  
//     {
//     vector_of_words = split_string(line);
//     client = words_to_stclient(vector_of_words);
//     vstclients.push_back(client);
//     }
// mfile.close();
// }



// }



// void change_password ( )
// {

// }

// stclient login_screen ()
// {
// cout << "========================\n";
// cout << "      login screen \n";
// cout << "========================\n";
// stclient login_data ;
// cout << " enter name \n";
// cin >> login_data.name ;
// cout << " enter pin \n";
// cin >> login_data.pin ;

// return login_data ;
// }





int main ()
{
stclient client = {"saged" , "A11"};

cout << read_file(client);



return 0 ;
}
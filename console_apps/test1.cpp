#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<fstream>
#include"../general/mlib.h"
using namespace std ;


const string file_name = "E:/m5.txt";


struct stclient_data 
{
string name ;
short pin ;
int balance ;
};



stclient_data _login_to_struct ( )
{
stclient_data client_data ;
cout << " enter name \n";
getline( cin >> ws , client_data.name );
cout << " enter pin \n";
cin >> client_data.pin ;
cout << "enter balance \n";
cin >> client_data.balance ;
return client_data ;
}



// string login_to_struct_to_record ( string sep )
// {

// stclient_data client_data = login_to_struct ( );
// string record ;

// stclient_data* point = &client_data;

// record += point->name + sep ;
// record += to_string(point->pin) + sep ;
// record += to_string(point->balance) ;

// return record ;
// }
vector<string> _struct_to_record (  )
{
string sep = "#//#";
stclient_data client_data = _login_to_struct ( );
//string record ;
vector<string> vlines ;

stclient_data* point = &client_data;

vlines.push_back(point->name) ;
vlines.push_back(sep) ;
vlines.push_back(to_string(point->pin) ) ;
vlines.push_back(sep) ;
vlines.push_back(to_string(point->balance)) ;

return vlines ;
}





// stclient_data word_to_vec ( string delim = "#//#")
// {
// string word = login_to_struct_to_record (delim);
// size_t pos = 0 ;
// vector<string>words ;
// stclient_data data ;
// while ( ( pos = word.find(delim) ) != word.npos)
// {
// if (!word.empty())
// words.push_back(word.substr(0,pos));

// word.erase( 0 , pos + delim.length());
// }
// if (!word.empty())
// words.push_back(word);

// data.name = words.at(0); 
// data.pin = stoi(words.at(1)); 
// data.balance = stoi(words.at(2)); 

// return data ;
// }


vector<string> file_to_vector(string file_name)
{
vector<string>words ;
string word ;
fstream mfile ;
mfile.open(file_name , ios::in) ;
if ( mfile.is_open())
{
while (getline ( mfile , word )) words.push_back(word);
mfile.close();
}
return words ;
}



void record_to_file_ ( string file_name , vector<string>vlines )
{
fstream mfile ;
mfile.open( file_name , ios::out | ios::app);

if ( mfile.is_open())
{
for ( string& line : vlines)  if (line!= "")  mfile << line ;
mfile << endl ;
mfile.close();
}
}




int main ()
{


do
{
record_to_file_ ( file_name , _struct_to_record() );
cout << endl ;
} while (mlib::want_to_repeat(" y or n "));




}
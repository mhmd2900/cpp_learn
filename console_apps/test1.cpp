#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<fstream>
#include<iomanip>
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
//vlines.push_back("____") ;

return vlines ;
}


void record_to_file_ ( string file_name , vector<string>vlines )
{
fstream mfile ;
mfile.open( file_name , ios::out | ios::app );

if ( mfile.is_open())
{
for ( string& line : vlines)  if (line!= "")  mfile << line ;
mfile << endl ;
mfile.close();
}
}




vector<string> file_to_vector( string file_name)
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





void line_to_words_ ( string line )
{
vector<string> words ;
string sep = "#//#";
size_t pos = 0 ;


cout << "____________________" << endl ;
cout << "|"  << left << setw(5) << "name"   << "|"  << left << setw(5) << "pin"  << "|"  << left << setw(7) << "balance"  << "|" << endl;
cout << "____________________" << endl ;


while ((pos = line.find(sep)) != line.npos )
{
string copy = line.substr(0,pos) ;

if ( !line.empty())
cout << "|" << left << setw(5) << copy   ;

line.erase( 0 , copy.length()+4 );
}

if (!line.empty())
cout << "|" << left << setw(7) << line   ;

cout << "|" << endl ;
cout << "____________________" << endl ;

}





// void show_file_records_( vector<string>lines )
// {
// auto iter = lines.begin();
// while ( iter != lines.end() )
// {
// line_to_words_(*iter);
// iter ++ ;
// }
// }



int main ()
{


do
{
record_to_file_ ( file_name , _struct_to_record() );
cout << endl ;
} while (mlib::want_to_repeat(" y or n "));



show_file_records_(file_to_vector(file_name));


}
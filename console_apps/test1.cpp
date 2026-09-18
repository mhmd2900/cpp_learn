#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<fstream>
#include<iomanip>
#include"../general/mlib.h"
using namespace std ;




struct strclientdata 
{
string name ;
short pin ;
int balance ;
};

const string file_name = "E:/m5.txt";
strclientdata stclientdata ;
vector<strclientdata> vstclientdata ;

//////////////////////////////////////////////////////////////////////////
void  _clientdata_to_records ( )
{

do 
{
cout << " enter name \n";
getline( cin >> ws , stclientdata.name );
cout << " enter pin \n";
cin >> stclientdata.pin ;
cout << "enter balance \n";
cin >> stclientdata.balance ;

vstclientdata.push_back(stclientdata);

} while (mlib::want_to_repeat("add another client ?  \n    y   or   n   \n" ));

}



void records_to_file_ ( string file_name )
{
fstream mfile ;
mfile.open( file_name , ios::out | ios::app );

if ( mfile.is_open())
{
for ( auto& [ name , pin , balance ] : vstclientdata )  
mfile << name << "#//#" << pin << "#//#" << balance << endl ;

mfile.close();
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


vector<string> file_to_records( string file_name)
{
vector<string>records ;
string word ;
fstream mfile ;
mfile.open(file_name , ios::in) ;
if ( mfile.is_open())
{
while (getline ( mfile , word )) records.push_back(word);
mfile.close();
}
return records ;
}





            void record_to_fields_ ( string line )
            {
            vector<string> fields ;
            string sep = "#//#";
            size_t pos = 0 ;


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





void print_records_( vector<string>records )
{
auto iter = records.begin();
cout << "____________________" << endl ;
cout << "|"  << left << setw(5) << "name"   << "|"  << left << setw(5) << "pin"  << "|"  << left << setw(7) << "balance"  << "|" << endl;
cout << "____________________" << endl ;

while ( iter != records.end() )
{
record_to_fields_(*iter);
iter ++ ;
}
}


//////////////////////////////////////////////////////////////////////////


int main ()
{
_clientdata_to_records();

records_to_file_ ( file_name );
cout << endl ;

vector<string>records = (file_to_records(file_name)) ;
print_records_(records);
}
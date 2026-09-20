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
int pin ;
int balance ;
};

const string file_name = "E:/m5.txt";                                                                               //✅✅✅
strclientdata stclientdata ;
vector<strclientdata> vst_write_records ;
vector<strclientdata> vst_read_records ;

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

vst_write_records.push_back(stclientdata);

} while (mlib::want_to_repeat("add another client ?  \n    y   or   n   \n" ));

}



void records_to_file_ ( string file_name , vector<strclientdata> vst = vst_write_records , bool check = false )     //✅✅✅
{
fstream mfile ;
mfile.open( file_name , ios::out | ( check ? ios::trunc   : ios::app));

if ( mfile.is_open())
{
for ( strclientdata & data : vst )                                                                                  //✅✅✅
mfile << data.name << "#//#" << data.pin << "#//#" << data.balance << endl ;

mfile.close();
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


strclientdata split_fields(string record)                                                                          //✅✅✅ 
{
strclientdata strecord ;
string sep = "#//#";

size_t pos = record.find(sep) ;
strecord.name = record.substr( 0 , pos );
record.erase(0 , pos+4);

pos = record.find(sep) ;
strecord.pin = stoi(record.substr( 0 , pos ));
record.erase(0 , pos+4);

strecord.balance = stoi(record);

return strecord  ;
}



void file_to_records( string file_name)
{

string record ;
fstream mfile ;

strclientdata strecord ;
vector<string> vrecord ;

mfile.open(file_name , ios::in) ;
if ( mfile.is_open())
{
while (getline ( mfile , record ))    
{
strecord  = split_fields(record);                                                                                   //✅✅✅ 
vst_read_records.push_back(strecord);                                                                               //✅✅✅ 
}

mfile.close();
}
}



void print_fields ( strclientdata clientdata)
{


    cout << "|"  << left << setw(5) << clientdata.name     << 
            "|"  << left << setw(5) << clientdata.pin      <<
            "|"  << left << setw(7) << clientdata.balance  << "|" << endl;
    cout << "____________________" << endl ;
    

}






void print_records_( )
{
    cout << "____________________" << endl ;
    cout << "|"  << left << setw(5) << "name"   << "|"  << left << setw(5) << "pin"  << "|"  << left << setw(7) << "balance"  << "|" << endl;
    cout << "____________________" << endl ;
    

auto iter = vst_read_records.begin();
while ( iter != vst_read_records.end() )
{
print_fields(*iter);
iter ++ ;
}
}



bool del()
{
char ch ;
cout << " do you want to delete this client ? \n";
cin >> ch ;
return (tolower(ch) == 'y') ? true : false ;

}



void check_pin ( int num )
{
strclientdata client ;
bool found = 0 ;           
vector<strclientdata>::iterator iter = vst_read_records.begin() ;                                                   //✅✅✅

cout << "before " << vst_read_records.size() << endl ;

    while ( iter != vst_read_records.end())
    {
        if (iter->pin == num )
        {
        client = *iter ;
        cout << " yes available  , name is " << client.name << " balance is " << client.balance << endl ;
        found = 1 ;

        if (del())     { iter = vst_read_records.erase(iter);   continue ;}
        }
       iter ++ ;
    }

cout << "after" << vst_read_records.size() << endl ;

if (!found)
{
char t = 'n';
strclientdata neww;
cout << " not available , want to add \n";
cin >> t ;
string name ;
int pin ;
int balance ;

if (t == tolower('y'))
{
neww.pin = num ;
cout << "name?" << endl ;
getline(cin>>ws ,neww.name ) ;
cout << "balance" << endl ;
cin >> neww.balance ;
vst_read_records.push_back(neww);
}
}
}

//////////////////////////////////////////////////////////////////////////


int main ()
{
_clientdata_to_records();
records_to_file_ ( file_name );
cout << endl ;

file_to_records(file_name) ;
print_records_();

records_to_file_ ("E:/m6.txt");
check_pin(99);

records_to_file_ ( file_name , vst_read_records , true );

}
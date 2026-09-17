#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include <iomanip> 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios ;
using std::setw ;
using std::left ;



const string file_name = "E:/m5.txt";


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


int main()                 
{
line_to_words_("xx#//#55#//#66");
}
    




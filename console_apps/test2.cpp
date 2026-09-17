#include <iostream>
#include <vector>
#include <string>
#include <fstream> 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios ;



const string file_name = "E:/m5.txt";


vector<string> read ( string file_name )
{
string line ;
vector<string>vlines ;

fstream mfile ;
mfile.open(file_name , ios::in);

if (mfile.is_open())
{
while ( getline ( mfile , line ) )   vlines.push_back(line);

mfile.close();
}
return vlines ;
}





void file_to_vector_(string file_name)
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
for ( const string& wo : words )
cout << wo ;
}





void write ( string file_name , vector<string>vlines)
{
fstream mfile ;
mfile.open( file_name , ios::out | ios::app);

if ( mfile.is_open())
{
for ( string& line : vlines)  if (line!= "")  mfile << line << endl ;

mfile.close();
}

}


int main()                 
{

// vector<string>vlines = read("E:/m1.txt");


// for ( const string& word : vlines )
// cout << word ;

// vector<string>rep = {"aly " , " wala "};
// write ("E:/m2.txt" , rep);

file_to_vector_(file_name);

}
    




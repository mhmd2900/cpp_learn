#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace std ;




void replace ( string& temp , bool both = false )
{
if ( temp == "saad")  temp = "kuala";
if ( both == true )    if ( temp == "Saad")  temp = "kuala";
}


void vnames ( string word , const string& delim = "," )
{
size_t pos = 0 ;

while ( ( pos = word.find(delim)) != word.npos )
{
string temp = word.substr( 0 , pos );
if (!word.empty())
{
replace(temp , 1);
cout << temp << " ";
}

word.erase(0 , pos + delim.length() );
}


replace(word , 1 );

if ( !word.empty())
cout << word ;
}







int main ()
{
string word = "mhmd saad hamed saad";


vnames(word);

}
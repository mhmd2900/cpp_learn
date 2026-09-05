#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::vector;

enum encount  { small , capital , m , mM };



string read ()
{
string word ;
cout << "plz enter word \n";
getline (cin , word );
return word ;
}


void trim_left (string& word , string delim)
{
int pos = 0 ;

while ( !word.empty() && word.at(0) == ' ')
word.erase(0,1);
}




void trim_right(string& word , string delim)
{

int pos = word.length()-1 ;
while ( !word.empty() && word.at(pos) == ' ')
{
pos = word.length()-1 ;
word.erase(pos,1);
}
}


int main ()
{
string word ;
word = read();
trim_left(word , " ");
trim_right(word , " ");
cout << word ;

// return 0 ;
}
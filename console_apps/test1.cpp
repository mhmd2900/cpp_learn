#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace std ;



vector<string> reverse ( string word , const string& delim = " " )
{
size_t pos = word.length() ;
vector<string>vwords ;

while ( (pos = word.rfind(delim) )  != word.npos  )
{
//string temp =  word.substr(pos, word.length()) ;
if (!word.empty() )
vwords.push_back(word.substr(pos + delim.length() )) ;

word.erase(pos ,word.length() );
}

if(!word.empty())
vwords.push_back(word);
return vwords ;
}




string show ( const string& word)
{
vector<string>vwords = reverse (word);
//vector<string>::iterator iter = vwords.end() - 1;
auto iter = vwords.end() - 1;

// for ( iter ; iter >= vwords.begin() ; iter-- )
// cout << *iter << " " ;

// for ( size_t i = vwords.size() ; i > 0 ; i-- )
// cout << vwords.at(i-1) << " " ;

string S2;
while (iter > vwords.begin())
{
S2 += *iter + " ";
--iter;
}
S2 = S2.substr(0, S2.length() - 1); //remove last space.
cout << S2 ;
return S2 ;
}






int main ()
{
string word = "many abdel maged";
show (word);
}
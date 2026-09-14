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




// string show ( const string& word)
// {
// vector<string>vwords = reverse (word);
// //vector<string>::iterator iter = vwords.end() - 1;
// auto iter = vwords.end() ;
// string S2;


// for ( size_t i = vwords.size() ; i > 0 ; i-- )
// cout << vwords.at(i-1) << " " ;
// return S2 ;


// while (iter > vwords.begin())
// {
// --iter;
// S2 += *iter + " ";
// }
// S2 = S2.substr(0, S2.length() - 1); //remove last space.
// cout << S2 ;
// return S2 ;
// }




void replace ( const string& word)
{
vector<string>vwords ;
vwords = reverse(word);
string temp ;

vector<string>::iterator iter = vwords.end();

// while ( iter > vwords.begin() )
// {
// iter -- ;
// if (*iter == "saad")  *iter = "another";
// temp += *iter + " ";
// }


while ( iter != vwords.begin() )
{
    iter -- ;
    if (*iter == "saad")  *iter = "another";
    temp += *iter + " ";
}
cout << temp ;
}




int main ()
{
string word = "mhmd saad hamed";
replace (word);
}
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



void replace ( string &word  )
{

auto iter = word.begin() ;
while (iter != word.end())
{
if ( ispunct(*iter))
*iter = 'Q' ;

cout << *iter ;
iter ++ ;
}
}




int main()                 
{
int a = 10 ;

string word = "hany0, mohamed ali. mokhtar mary";

replace (word);

}
    
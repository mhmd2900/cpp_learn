#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include "../general/mlib.h"
using namespace std ;


void fun1 ( )
{
int a = 5 ;
int*p = &a ;
cout << p << endl ;
cout << p +1  << endl ;
cout << p +2  << endl << endl;
}
int main()
{


string s = "mhmd";  // s[4] = \0
s[4] = 'i';
cout << s ;    // should be  mhmd + garbage ( the memory goes up to the previous int main variable )


char ch[5];
ch[0]= 'a';
ch[1]= 'b';

cout << ch ;

}



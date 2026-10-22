#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include "../general/mlib.h"
#include "../general/mdates.h"
using namespace std ;




enum enaccess { read = 1 << 0 , write = 1 << 1 , share = 1 << 2 };
short admin = read | write | share ;
short user = 15 ;
short non = 2 ;
short all = -1 ;





int main()
{
int pr ;
cout << "enter\n";
cin >> pr ;




if ( pr & read )
cout << " yes \n " ;
else
cout << " no \n " ;







}
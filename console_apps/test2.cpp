#include<iostream>
#include<string>
#include<vector>
using namespace std ;


bool leap (int num)
{
return ( (num%400 == 0) || (num%4 == 0 && num%100 != 0)) ;
}


void count ( int& days , int& hours , int& minutes , int& seconds )
{
hours = days * 24 ;
minutes = hours * 60 ;
seconds = minutes * 60 ;
}


int main()
{
int year = 2000 ;
int days = 0 ;

// if (leap(year))
// days = 366 ;
// else
// days = 365 ;

days = (leap(year)) ? 366 : 365 ;

int hours = 0 ;
int minutes = 0 ;
int seconds = 0 ;

count ( days , hours , minutes , seconds ) ;
cout << days << endl << hours << endl << minutes << endl << seconds ;


}



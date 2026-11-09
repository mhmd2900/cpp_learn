#include<iostream>
#include<vector>

using namespace std ;


void fun ( int*& x  ,  vector<int>& vnums )
{
x = &vnums[1] ;
cout << *x << endl ;
}



int main ()
{

int a =  4 , b = 5 , c = 6 ;
int* p = nullptr ; 
vector<int>vnums = { a,b,c};

fun ( p , vnums );
cout << *p << endl ; 



return 0 ;
}
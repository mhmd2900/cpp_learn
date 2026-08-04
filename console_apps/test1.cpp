#include<iostream>
#include<string>
#include "../general/mlib.h"

using std::cout ;
using std::cin ;
using std::string ;



void fun3()
{
cout << " hello \n";
}


void fun2()
{
fun3();
}


void fun1()
{
fun2();
}

int main ()
{

fun1();
return 0 ;
}
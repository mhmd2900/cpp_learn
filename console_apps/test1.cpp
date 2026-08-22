#include <iostream>
#include <cstdio>
#include"../general/mlib.h"
using namespace std;



int main() 
{


int a = 5 ;
printf("  num is %d\n", a ) ;
printf("  num is %3d\n", a ) ;
printf("  num is %*d\n", 3 , a ) ;
printf("  num is %03d\n", a ) ;
printf("  num is %0*d\n\n", 3 , a ) ;

float b = 5.123456 ;
printf(" num is %f   \n", b ) ;
printf(" num is %10f   \n", b ) ;
printf(" num is %.2f   \n", b ) ;
printf(" num is %.*f   \n\n", 3 , b ) ;

char name[] = "mhmd";
printf(" my name is %s \n" , name ) ;
printf(" my name is %6s \n" , name ) ;
printf(" my name is %*s \n\n" , 6 , name ) ;

char ch = 'c';
printf("first letter is %c \n" , 'm');
printf("first letter is %3c \n" , 'm');
printf("first letter is %*c \n" , 3 , 'm');
return 0;
}
    
#include<iostream>
#include<string>
#include<vector>
using namespace std ;


string convert_text ( int num )
{
string ones[20] = { "" , "one " , "two " , "three " , "four " , "five " , "six " , "seven " , "eight " , "nine " , "ten " ,
"eleven " , "twelve " , "thirteen " , "fourteen " , "fifteen " , "sixteen " , "seventeen " , 
"eighteen " , "nineteen " } ;
string twenties[10] = { "" , "" , "twenty " , "thirty " , "forty " , "fifty " , "sixty " , "seventy " ,
    "eighty " , "ninety " };


if ( num == 0 )
return "";

else if ( num >= 1 && num <= 19 )
return ones[num] ;

else if ( num >= 20 && num <= 99 )
return twenties[num/10]  + convert_text(num %10);

else if ( num >= 100 && num <= 199 )
return "hundred " + convert_text(num %100);

else if ( num >= 200 && num <= 999 )
return ones[num/100] +  "hundreds " + convert_text(num %100);

//////////////////////////////////////////////

else if ( num >= 1000 && num <= 1999 )
return "thousand " + convert_text(num %1000);

else if ( num >= 2000 && num <= 999999 )
return convert_text(num/1000) + "thousands " + convert_text(num %1000);

else if ( num >= 1000000 && num <= 1999999 )
return "million " + convert_text(num %1000000);

else if ( num >= 2000000 && num <= 999999999 )
return convert_text(num/1000000) + "millions " + convert_text(num %1000000);

else 
return "";
}


int main()
{

string str = convert_text(987654321);
cout << str ;
}



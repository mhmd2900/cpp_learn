#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std ;


bool is_leap (int year)
{
return ( (year%400 == 0) || (year%4 == 0 && year%100 != 0)) ;
}



int dayscount_in_month ( int month , int year )
{
int days[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31};
return ( month == 2 ?  (is_leap(year ) ? 29 :  28)  
                    : days[month]               ) ;
}



int day_index ( int day , int month , int year )
{
//string week_days[] = {"sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday"};
int y , d , m , a ;
a = (14 - month ) / 12 ;
y = year - a ;
m = month + 12*a - 2 ;
d = (day + y + y/4 - y/100 + y/400 + 31*m/12 ) % 7 ;
return d ;
//return week_days[d];
}


void print ( int month )
{
string week_days[] = {"" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "June" , "July" , "Aug", "Sep", "Oct", "Nov", "Dec"};
cout << "\n\n======================  "<< week_days[month] << "  ======================" << endl ;
printf(" %6s %6s %6s %6s %6s %6s %6s " , "sun" , "mon" , "tues" , "wedn" , "thurs" , "fri" , "sat" );
cout << endl ;
}


void cal_month ( int month , int year , int day = 1 )
{
vector<int>days(dayscount_in_month(month,year));
for ( int i = 0 ; i < days.size() ; i++)
days.at(i) = i + 1 ;

int d_index = day_index ( 1 , month , year );


print ( month );

for ( int i = 0 ; i < d_index ; i ++ )
printf(" %6s" , " ") ;
 

for ( int x = 0 ; x < days.size() ; x ++ )
{
printf(" %5d " , days[x]) ;
if (( d_index + days[x]) %7 == 0 )   cout << endl ;
}

cout << "\n==================================================\n" << endl ;
}


void cal_year ( int year )
{
cout << "\n\n======================  Calendar"<< year << "  ======================" << endl ; 
for ( int i = 1 ; i < 13 ; i ++ )
cal_month( i , 2030 );
}

void daydate_daycount( int day , int month , int year)
{
int count = 0  ;
for ( int i = 1 ; i < month ; i++ )
count += dayscount_in_month(i , year) ;
count += day ;
cout << count << endl ;
}

void daycount_daydate ( int count , int year )
{
int month = 1 ;
for ( ; month < 12 ; month++ )
{
int dd = dayscount_in_month( month , year) ;
if ( count <= dd )    break ;
count -= dd ;
}

cout << " day is " << count << "/" << month << "/" << year << "\n" ;
}




int main()
{
//cal_year( 2030 );
//daydate_daycount( 20  ,   9  , 2022 );
daycount_daydate(263 , 2022);
}









// void count ( int& days , int& hours , int& minutes , int& seconds )
// {
// hours = days * 24 ;
// minutes = hours * 60 ;
// seconds = minutes * 60 ;
// }



// int year = 2000 ;
// int days = 0 ;

// days = (is_leap(year)) ? 366 : 365 ;

// days = dayscount_in_month ( 2 , 2000 ) ;

// int hours = 0 ;
// int minutes = 0 ;
// int seconds = 0 ;

// count ( days , hours , minutes , seconds ) ;
//cout << days << endl << hours << endl << minutes << endl << seconds ;



//cout << day_index(1,9,2022) << endl ;
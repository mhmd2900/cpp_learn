#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std ;


struct stdate1 {
short day = 28 ;
short month = 2 ;
short year = 2001 ;
};

struct stdate2 {
short day = 1 ;
short month = 1 ;
short year = 2022 ;
};


// bool which_is ()
// {
// stdate1 date1 ;
// stdate2 date2 ;
// // return ( date1.year < date2.year) ?  true   :  
// //                                     ( date1.year == date2.year  
// //                                       ? ( date1.month < date2.month ? true :
// //                                         (date1.month == date2.month  ?
// //                                             date1.day < date2.day  : false))      
// //                                   : false ) ;
// return date1.year == date2.year ? (  date1.month == date2.month ? ( date1.day == date2.day ):false ):false;
// }

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

bool last_day ( stdate1& date1  )
{ 
int day =  dayscount_in_month( date1.month , date1.year ) ;
return date1.day == day ;
}

bool last_month ( stdate1& date1 )
{
return date1.month == 12 ;
}

void add_one ( stdate1& date1 )
{
int d = date1.day , m = date1.month  , y = date1.year ;
// d = last_day(date1) ? ( d = 1 , ( last_month (date1) ? ( m = 1 , y ++ )  : m ++    ))     :  d ++ ;
last_day(date1) ? ( d = 1 , last_month (date1) ?  ( m = 1 , y ++  )  : m++  )   : d++   ;

// cout << d << "/" << m << "/" << y ;
printf(" \n  %i / %i / %i " , d , m , y );
}


void daycount_daydate ( int count , int day , int month , int year )
{
int month_count = month ;
count += day ;
int year_count = is_leap(year+1) ? 366  : 365 ;

    if ( month <= 2)
    while ( count > year_count ) 
    {
    year_count = is_leap(year) ? 366  : 365 ;
    count -= year_count ;
    year ++ ; 
    }

    else
    while ( count > year_count ) 
    {
    year_count = is_leap(year+1) ? 366  : 365 ;
    count -= year_count ;
    year ++ ; 
    }

while ( true )
    {
    int dd = dayscount_in_month ( month_count , year) ;
    if  ( count <= dd )    break ;

    count -= dd ;
    month_count++ ;

        if ( month_count > 12 )
        {
        month_count = 1 ;
        year ++ ;
        }
    }
printf(" exact day is %i/%i/%i " , count , month_count , year  ) ;
}



int main()
{
stdate1 date1 ;
daycount_daydate(1 , 28 , 2 , 2000);
add_one ( date1 );
}


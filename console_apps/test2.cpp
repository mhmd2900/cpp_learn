#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std ;


struct stdate {
short day  ;
short month ;
short year  ;
};

// stdate2 gettime ( )
// {
// stdate2 date2 ;
// time_t t = time(0) ;
// tm* now = localtime(&t) ;
// date2.day = now->tm_mday ;
// date2.month = now->tm_mon + 1 ;
// date2.year = now->tm_year + 1900 ;
// return date2 ; 
// }

// bool is_date1_smaller ( stdate1 date1 , stdate1 date2 )
// {
//  return ( date1.year < date2.year) ?  true   :                                      
//                                     ( date1.year == date2.year  
//                                     ? ( date1.month < date2.month ? true :
//                                       (date1.month == date2.month  ?
//                                          date1.day < date2.day  : false))      
//                                     : false ) ;  
// }

// bool is_dates_equal ( stdate1 date1 , stdate1 date2 )
// {
// //return date1.year == date2.year ? (  date1.month == date2.month ? ( date1.day == date2.day ):false ):false; 
// }

// void swap_dates ( stdate1& date1 , stdate1& date2 )
// {
// stdate1 temp ;
// temp = date1;
// date1 = date2;
// date2 = temp;
// }

bool is_leap (short year)
{
return ( (year%400 == 0) || (year%4 == 0 && year%100 != 0)) ;
}

short dayscount_in_month ( short month , short year )
{
short days[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31};
return ( month == 2 ?  (is_leap(year ) ? 29 :  28)  
                    : days[month]               ) ;
}

bool last_day ( stdate& date1  )
{ 
short day =  dayscount_in_month( date1.month , date1.year ) ;
return date1.day == day ;
}

bool last_month ( stdate& date1 )
{
return date1.month == 12 ;
}

void add_1day_to_date ( stdate& date1 )
{
short& d = date1.day   ;                               //✅✅✅  alias to short not struct 
short& m = date1.month ;
short& y = date1.year  ;

                                                       //✅✅✅  ternary add with ,    not ; or &&
last_day(date1) ? ( d = 1 , last_month (date1) ?  ( m = 1 , y ++  )  : m++  )   : d++   ;

printf(" \n  %i / %i / %i \n" , d , m , y );            // ✅✅✅ interconnected variables and values
}

void remove_1day_to_date ( stdate& date1 )
{
short& d = date1.day   ;                            
short& m = date1.month ;
short& y = date1.year  ;

d == 1  ? (m == 1  ?  d = 31 , m = 12 , y-- :  m--  ,  d = dayscount_in_month ( m , y )  ) : d--;
printf(" \n  %i / %i / %i \n" , d , m , y );          
}

void add_days_to_date ( short count , stdate& date1 , bool week = 0 )
{
short& d  = date1.day ;
short& m  = date1.month ;
short& y  = date1.year ;

if ( week == 1) count *= 7 ;
d += count ;
short adder =   m<= 2 ? 0  :  1 ;
short days_in_year = is_leap( y + adder ) ? 366  : 365 ;

    while ( d > days_in_year ) 
    {
    d -= days_in_year ;
    y ++ ; 
    }

while ( true )
    {
    short days_in_month = dayscount_in_month ( m , y) ;
    if  ( d <= days_in_month )    break ;
    d -= days_in_month ;
    m++ ;
        if ( m > 12 )
        {
        m = 1 ;
        y ++ ;
        }
    }
printf(" exact day is %i/%i/%i \n " , d , m , y  ) ;
}

void remove_days_to_date ( short count , stdate& date1 , bool week = 0 )
{
short& d  = date1.day ;
short& m  = date1.month ;
short& y  = date1.year ;

if ( week == 1)   count *= 7 ;

short adder =   m<= 2 ?  -1  :  0 ;
short days_in_year = is_leap( y + adder ) ? 366  : 365 ;

    while ( d > days_in_year ) 
    {
    count -= days_in_year ;
    y -- ; 
    }

while ( count != 0 )
    {
    short mm = m , yy = y ;
    (m == 1)  ? mm = 12 , yy--     : mm -= 1 ;
    short days_in_month = dayscount_in_month ( m , y ) ;
    short days_in_prevmonth = dayscount_in_month ( mm , yy ) ;

        if  ( count < days_in_month && count < d )  
        {
         d -= count ;
         count = 0 ;
         break ;
        }

        else if  ( count < days_in_prevmonth && count > d )  
        {
        count -= d ;
        days_in_prevmonth -= count ;
        count = 0 ;
        d = days_in_prevmonth ;
         m-- ;
            if ( m < 1 )
            {
            m = 12 ;
            y -- ;
            }
        break ;
        }  


        else 
        {
         count -= days_in_prevmonth;
         m-- ;
            if ( m < 1 )
            {
            m = 12 ;
            y -- ;
            }
        }
    }
printf(" exact day is %i/%i/%i \n " , d , m , y  ) ;
}




void add_months_to_date ( short count , stdate& date1 )
{
while ( count != 0 )
{
date1.month ++ ;
    if ( date1.month == 12 ) 
    {
    date1.month = 0 ;
    date1.year ++ ;
    }
count -- ;
}

if(date1.day > dayscount_in_month(date1.month , date1.year))
date1.day = dayscount_in_month(date1.month , date1.year) ;

printf(" after adding months is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

void add_years_to_date ( short count , stdate& date1 )
{
while ( count != 0 )
{
date1.year ++ ;
count -- ;
}
printf(" after adding years is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

void add_decades_to_date ( short count , stdate& date1 )
{
while ( count != 0 )
{
date1.year += 10 ;
count -- ;
}
printf(" after adding decades is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

void add_cents_to_date ( short count , stdate& date1 )
{
while ( count != 0 )
{
date1.year += 100 ;
count -- ;
}
printf(" after adding cents is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

void add_mills_to_date ( short count , stdate& date1 )
{
while ( count != 0 )
{
date1.year += 1000 ;
count -- ;
}
printf(" after adding mills is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

// void date_diff ( stdate1 date1 , stdate1 date2 )
// {
// //date2 = gettime();
// short swapflag = 1 ;
// if ( ! is_date1_smaller( date1 , date2))
//     {
//       swap_dates ( date1 , date2 ) ;
//       swapflag = -1 ;
//     }
// short c = 0 ;
// short year_count = 0 ;
// while ( date2.year > date1.year + 1 ) 
//     {
//         if ( date1.month <= 2)
//         {
//         year_count = is_leap(date1.year) ? 366  : 365 ;
//         c += year_count ;
//         date1.year ++ ; 
//         }
//         else
//         {
//         year_count = is_leap(date1.year+1) ? 366  : 365 ;
//         c += year_count ;
//         date1.year ++ ; 
//         }
//     }
// while ( date2.year != date1.year ||  date2.month != date1.month ) 
//     {
//         short m_count = dayscount_in_month( date1.month , date1.year);
//         c += m_count ;
//         //date1.month ++ ;
//         if (date1.month == 12 ) {  date1.month = 1 ; date1.year++ ; }  
//         else  date1.month ++ ; 
//     }
// cout << swapflag * ( c + date2.day - date1.day ) << endl ;
// }

int main()
{
stdate date[2] , months , years , decades , mills ;

date[0].day = 1 ;
date[0].month = 1 ;
date[0].year = 2000 ;

date[1].day = 30 ;
date[1].month = 12 ;
date[1].year = 1990 ;

// remove_1day_to_date( date[0]);
// add_days_to_date( 2 , date[0] , 1 );
// add_months_to_date( 13 , date[0] );
// add_years_to_date( 10 , date[0] );
// add_decades_to_date( 5 , date[0] );
// add_cents_to_date( 5 , date[0] );
// add_mills_to_date( 2 , date[0] );

remove_days_to_date ( 2 , date[0] );




}


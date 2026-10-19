#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std ;


namespace mdates
{

struct stdate {
short day   ;
short month ;
short year  ;
};

struct stemp {
stdate period_s , period_e ;
};

stdate gettime ( )
{
stdate date ;
time_t t = time(0) ;

tm* now = localtime(&t) ;
date.day = now->tm_mday ;
date.month = now->tm_mon + 1 ;
date.year = now->tm_year + 1900 ;
return date ; 
}

bool is_date1_smaller ( stdate date1 , stdate date2 )
{
 return ( date1.year < date2.year) ?  true   :                                      
                                    ( date1.year == date2.year  
                                    ? ( date1.month < date2.month ? true :
                                      (date1.month == date2.month  ?
                                         date1.day < date2.day  : false))      
                                    : false ) ;  
}

bool is_dates_equal ( stdate date1 , stdate date2 )
{
return date1.year == date2.year ? (  date1.month == date2.month ? ( date1.day == date2.day ):false ):false; 
}

void swap_dates ( stdate& date1 , stdate& date2 )
{
stdate temp ;
temp = date1;
date1 = date2;
date2 = temp;
}

short day_index  ( stdate& date1 )
{
short& day = date1.day   ;                               //✅✅✅  alias to short not struct 
short& month = date1.month ;
short& year = date1.year  ;
short y , d , m , a ;
a = (14 - month ) / 12 ;
y = year - a ;
m = month + 12*a - 2 ;
d = (day + y + y/4 - y/100 + y/400 + 31*m/12 ) % 7 ;
return d ;
}

string day_name ( stdate& date1 )
{
short& day = date1.day   ;                               //✅✅✅  alias to short not struct 
short& month = date1.month ;
short& year = date1.year  ;
string week_days[] = {"sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday"};
short y , d , m , a ;
a = (14 - month ) / 12 ;
y = year - a ;
m = month + 12*a - 2 ;
d = (day + y + y/4 - y/100 + y/400 + 31*m/12 ) % 7 ;
return week_days[d];
}

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

void print ( short month )
{
string week_days[] = {"" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "June" , "July" , "Aug", "Sep", "Oct", "Nov", "Dec"};
cout << "\n\n======================  "<< week_days[month] << "  ======================" << endl ;
printf(" %6s %6s %6s %6s %6s %6s %6s " , "sun" , "mon" , "tues" , "wedn" , "thurs" , "fri" , "sat" );
cout << endl ;
}

void calend ( stdate& date1 )
{
date1.day = 1 ;

short& day = date1.day   ;                               //✅✅✅  alias to short not struct 
short& month = date1.month ;
short& year = date1.year  ;

vector<short>days(dayscount_in_month(month,year));     // put month days into vector
for ( short i = 0 ; i < days.size() ; i++)
days.at(i) = i + 1 ;

short d_index = day_index ( date1 );                 // to know number of spaces before 1st day

print ( month );

for ( short i = 0 ; i < d_index ; i ++ )             // make spaces
printf(" %6s" , " ") ;
 

for ( short x = 0 ; x < days.size() ; x ++ )
{
printf(" %5d " , days[x]) ;
if (( d_index + days[x]) %7 == 0 )   cout << endl ;  // new line after each saturday
}

cout << "\n==================================================" << endl ;
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
string day_n = day_name(date1) ;
printf(" \n  %i / %i / %i  " , d , m , y );   // ✅✅✅ interconnected variables and values
cout << " which is " << day_n << endl ;
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

void remove_months_to_date ( short count , stdate& date1 )
{
                                                                // ✅✅✅
date1.year  -= count/12 ;
date1.month -= count%12 ;

if ( date1.month <= 0 )  {  date1.month += 12 ; date1.year -- ;  }


if(date1.day > dayscount_in_month(date1.month , date1.year))
date1.day = dayscount_in_month(date1.month , date1.year) ;

printf(" after removing months is %i/%i/%i \n " , date1.day , date1.month , date1.year  ) ;
}

short date_diff ( stdate& date1 , stdate& date2 , bool inclde_end_date = false ) // ✅✅✅
{
//date2 = gettime();
short swapflag = 1 ;
if ( ! is_date1_smaller( date1 , date2))
    {
      swap_dates ( date1 , date2 ) ;
      swapflag = -1 ;
    }
short c = 0 ;
short year_count = 0 ;
while ( date2.year > date1.year + 1 ) 
    {
        if ( date1.month <= 2)
        {
        year_count = is_leap(date1.year) ? 366  : 365 ;
        c += year_count ;
        date1.year ++ ; 
        }
        else
        {
        year_count = is_leap(date1.year+1) ? 366  : 365 ;
        c += year_count ;
        date1.year ++ ; 
        }
    }
while ( date2.year != date1.year ||  date2.month != date1.month ) 
    {
        short m_count = dayscount_in_month( date1.month , date1.year);
        c += m_count ;
        //date1.month ++ ;
        if (date1.month == 12 ) {  date1.month = 1 ; date1.year++ ; }  
        else  date1.month ++ ; 
    }
short diff =  swapflag * ( c + date2.day - date1.day ) ;
//cout << " total dates difference is " << diff << endl ;
return diff + inclde_end_date; // ✅✅✅  add bool to short
}

void remove_wd_from_vacation ( stdate& date1 , stdate& date2 )
{
int diff = 0 , i = 0  ;
while (!is_dates_equal(date1,date2))
{
diff ++ ;
i = day_index(date1 ) ;
    if ( i == 5 || i == 6 ) diff -- ;
add_1day_to_date(date1);
}
printf(" net vacation is %i days" , diff );
}

void remove_vacation_todate ( short diff , stdate& date1 )
{
short i ;
while ( diff!= 0)
{
i = day_index(date1 ) ;
    if ( i == 5 || i == 6 ) diff ++ ;
diff -- ;
add_1day_to_date(date1);

}
add_1day_to_date(date1);
printf(" return date is   %i / %i / %i  \n " , date1.day , date1.month , date1.year);
}

stdate which_is_smaller ( stdate date1 , stdate date2)
{
return is_date1_smaller (date1,date2)    ? date1   : date2   ;
}

bool overlap ( stemp ahmed , stemp ali )
{
return !is_date1_smaller (ahmed.period_e , ali.period_s)|| is_date1_smaller (ali.period_e , ahmed.period_s);
}

short overlap_count ( stemp ahmed , stemp ali )
{
stdate large_s = is_date1_smaller(ahmed.period_s , ali.period_s) ? ali.period_s  :  ahmed.period_s ;
stdate small_e = is_date1_smaller(ahmed.period_e , ali.period_e) ? ahmed.period_e  :  ali.period_e ;
return date_diff( large_s , small_e , true ) ;
}

bool date_within ( stemp ahmed , stdate date1 )
{
return is_date1_smaller (date1 , ahmed.period_e) && is_date1_smaller (ahmed.period_s , date1);
}

void get_date ( stdate& date )
{
date.year = mlib::get_number("plz enter the year \n");
date.month = mlib::get_number("plz enter month " , 1 , 12 );
short end = dayscount_in_month(date.month , date.year) ;
date.day = mlib::get_number("plz enter day " , 1 , end );
}

string convert_num_to_text ( int num )
{
string ones[20] = { "" , "one " , "two " , "three " , "four " , "five " , "six " , "seven " , "eight " , "nine " , "ten " ,
"eleven " , "twelve " , "thirteen " , "fourteen " , "fifteen " , "sixteen " , "seventeen " , 
"eighteen " , "nineteen " } ;
string ties[10] = { "" , "" , "twenty " , "thirty " , "forty " , "fifty " , "sixty " , "seventy " ,
    "eighty " , "ninety " };

if ( num == 0 )
return "";

else if ( num >= 1 && num <= 19 )
return ones[num] ;

else if ( num >= 20 && num <= 99 )
return ties[num/10]  + convert_num_to_text(num %10);

else if ( num >= 100 && num <= 199 )
return "hundred " + convert_num_to_text(num %100);

else if ( num >= 200 && num <= 999 )
return ones[num/100] +  "hundreds " + convert_num_to_text(num %100);

//////////////////////////////////////////////

else if ( num >= 1000 && num <= 1999 )
return "thousand " + convert_num_to_text(num %1000);

else if ( num >= 2000 && num <= 999999 )
return convert_num_to_text(num/1000) + "thousands " + convert_num_to_text(num %1000);

else if ( num >= 1000000 && num <= 1999999 )
return "million " + convert_num_to_text(num %1000000);

else if ( num >= 2000000 && num <= 999999999 )
return convert_num_to_text(num/1000000) + "millions " + convert_num_to_text(num %1000000);

else 
return "";
}


}

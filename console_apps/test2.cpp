#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;




void fun ( string& word , string delim , char*& name_start , int& name_length , char*& pin_start , int& pin_length )
{
int count = 0 , pos = 0 ;
string::iterator itstring ;
itstring = word.begin() ;

    while ( (itstring != word.end())  )
    {

        if ( ( pos = word.find(delim)) != word.npos  )   // index of delim start
        {
            cout << word.substr(0,pos) << endl ;

            if ( count == 1 )
            {
              name_start = &word[0];
              name_length = pos ;              
            }

            else if ( count == 2 )
            {
              pin_start = &word[0];
              pin_length = pos ;
            }

            itstring += pos + delim.size()  ;        // iterator moves after delim
            word = &*itstring ;                      // word becomes the remnant after iterator
            itstring = word.begin() ;                // iterator move to the beginning of the new word ( remnant )
            count ++ ;                               // counts how many times i find the delim + extra count
            
            cout << word << endl ;
            cout << "count " << count << endl ;
            if ( count == 4 )  break ;               // break after all delimiters
            //continue ;
        }

    // auto index = itstring - word.begin();  // substract two iterators 
    // auto index = user - vstusers.data();   // substract two pointers

    // cout << index << "\n";          // index
    // cout << *itstring << "\n";      // value
    // cout << &*itstring << "\n";     // string remnant


    }


}



int main ()
{
system ("cls") ;

string word = "1#//#saged#//#A11#//#1132#//#active"; 
string delim = "#//#";


char * name_start = nullptr ;
int name_length  = 0 ;

char * pin_start = nullptr ;
int pin_length  = 0 ;

string name , pin ;


fun ( word , delim , name_start , name_length , pin_start , pin_length );

cout << endl << endl ;
cout << *name_start << endl ;
cout << name_length << endl ;
cout << *pin_start << endl ;
cout << pin_length << endl ;

}


#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include "../general/mlib.h"
#include "../general/mdates.h"
using namespace std ;


// enum enaccess { read = 1 << 0 , write = 1 << 1 , share = 1 << 2 };
// short admin = read | write | share ;
// short user = 15 ;
// short non = 2 ;
// short all = -1 ;


struct stfirst {
    string name ;
    //int grade ;
};

struct stsecond {
    //string name ;
    int grade ;
};

enum enusers    { users_show = 1 , users_find = 2 , users_update = 3 , users_add = 4 , users_del = 5 , users_return = 6  } ;


void fun ( stfirst first )
{
    cout << " welcome " ;
}

int main()
{
// stfirst first ; 
// stsecond second ;
// fun ( second );


vector<enusers> ven_users ;

ven_users.push_back(users_add) ;

cout << ven_users.at(0) ;




}
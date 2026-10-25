#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include "../general/mlib.h"
#include "../general/mdates.h"
using namespace std ;


enum entransaction  { tr_deposit = 1 , tr_withdraw = 2 , tr_balance = 3 , tr_return = 4 } ;


struct stclient_history
{
vector<double> v_amount ;
vector<entransaction> v_trans ; //✅✅✅ structure of vst of vector of enums
};

struct stclient 
{
int serial = 0 ;
string name ;
string pin ;
double balance ;
bool activity = false ;
vector<stclient_history> v_history ;
};

int main()
{



// stclient client ;
// client.v_history.push
// client.v_history[0].v_amount.at(0) = 1000 ;

// cout << client.v_history[0].v_amount[0] ;
}
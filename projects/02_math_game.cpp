#include<iostream>
#include<string>
#include<random>
#include "../general/mlib.h"


using std::cout ;
using std::cin ;
using std::string ;


enum enlevel  { easy = 1 , hard = 2 , mix = 3 } ;
enum enoper   { add = 1 , substract = 2 , divide = 3 , all = 4 };
enum enwinner { player , computer , draw };

struct stround_stats 
{
int num1 = 0 ;
int num2 = 0 ;
int sum  = 0 ;
int answer  = 0 ;
};



struct stgame_stats 
{
int count = 0 ;
int right = 0 ;
int wrong = 0 ;
enlevel level ;
enoper oper ;
enwinner winner ;
stround_stats round_stats[10] ;            //✅✅✅✅✅✅ 
};

// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     D  CONVERSTORS
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



string enlevel_to_string( enlevel level )
{
switch ( level)
{
case easy :
return " easy ";
case hard :
return " hard ";
case mix :
return " mix  ";
default :
return " invalid level ";
}
}



string enoper_to_string( enoper oper )
{
switch ( oper )
{
case add :
return " add ";
case substract :
return " substract ";
case divide :
return " divide  ";
case all :
return " all  ";
default :
return " invalid operator ";
}
}


string enwinner_to_string( enwinner winner )
{
switch ( winner)
{
case player :
return " PLAYER ";
case computer :
return " COMPUTER ";
case draw :
return " NO WINNER ";
default :
return " invalid inpput ";
}
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     C  ROUND LOGIC
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
void generate ( stround_stats& r , const enlevel level )   // & modify
{


if ( level  == easy)
{
r.num1 = mlib::get_random(0 , 9 );
r.num2 = mlib::get_random(1 , 9 );
}

else if ( level == hard )
{
r.num1 = mlib::get_random(10 , 20 );
r.num2 = mlib::get_random(10 , 20 );
}

else 
{
r.num1 = mlib::get_random(0 , 20 );
r.num2 = mlib::get_random(1 , 20 );
}
}



enoper generate_operator ( enoper& oper  ) 
{
if ( oper == all )        oper = (static_cast<enoper>(mlib::get_random ( 1, 3 ))) ;
    return oper ;
}



void show_and_calculate ( stround_stats& r , enoper oper )  // & modify  , no & to allow change oper every iteration
{

cout << r.num1  << "\n" ;

    switch ( generate_operator(oper) ) // call in FUNCTION C not B ,, to be changed every call
    {
    case add :
    r.sum = r.num1 + r.num2 ;  cout << " + \n" ;
    break ;
    case substract :
    r.sum = r.num1 - r.num2 ;  cout << " - \n" ;
    break ;
    case divide :
        if ( r.num2 != 0 )  // just as a guarantee if later change input
        r.sum = r.num1 / r.num2 ;  
        else 
        r.sum = 0 ;   
        cout << " / \n" ;
    break ;
    default :
    r.sum = 0 ;
    }
     
cout << r.num2 << "\n_________________________ \n" ;
}






void receive_and_update( stround_stats& r , int& right , int& wrong )   //  & nodify
{

r.answer = mlib::get_number(" your answer    :   ") ;

if (r.answer == r.sum)                 { cout << " right  \n";     right++ ; }
else                                   { cout << " wrong  \n";     wrong++ ; }
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                     B  GAME RESULTS
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
void round ( stgame_stats& game_stats , int i )    // & modify
{
stround_stats& r = game_stats.round_stats[i] ;           //✅✅✅✅✅✅ pass by alias to avoid long sentece
                                                         //✅✅✅✅✅✅ every coming function takes only what it needs , not all game_stats
generate ( r , game_stats.level);
show_and_calculate ( r , game_stats.oper );
receive_and_update ( r , game_stats.right , game_stats.wrong );
}



void final_winner ( stgame_stats& game_stats )  // & modify 
{
game_stats.winner = ( game_stats.right == game_stats.wrong) ? draw : ( ( game_stats.right > game_stats.wrong) ? player : computer);

    cout << " ================== \n";
    cout << " final winner  is              : " <<  enwinner_to_string(game_stats.winner)  << "\n";
    cout << " ================== \n";
    cout << " number of questions           : " << game_stats.count   << "\n";
    cout << " number of right answers is    : " << game_stats.right   << " \n";
    cout << " number of wrong answers is    : " << game_stats.wrong   << " \n";
    cout << " choosen level is              : " << enlevel_to_string(game_stats.level)    << "\n";
    cout << " choosen operator is           : " << enoper_to_string(game_stats.oper)      << "\n";

}



void print_all_detail( const stgame_stats& game_stats , int count ) //    & size , so use const
{

cout << " \n^^^^^^^^^^^^^^^^^ all details ^^^^^^^^^^^^^^^^ \n  ";
for ( int i = 0 ; i < count ; i ++)
{
const stround_stats& r = game_stats.round_stats[i] ;     //✅✅✅✅✅✅const in parameter necessitate const here

cout << " \n round " << i+1 << " : you choose " << r.answer << "   , real sum is : " << r.sum << " your answer is " ;
cout << ((r.answer == r.sum) ? " right \n" : " wrong  \n"); 
}
cout << " \n  ************** \n " ;
}


// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                    A  GAME FLOW
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

void game ( )
{
stgame_stats game_stats ;

//✅✅✅✅✅✅ 
game_stats.count = mlib::get_number(" how many questions ( maximum 10 )   ? \n " , 1 , 10 ) ;
game_stats.level = static_cast<enlevel>(mlib::get_number( " choose level  [1]easy     [2]hard      [3]mix   \n" , 1 , 3 ));
game_stats.oper  = static_cast<enoper>(mlib::get_number( " choose operator  [1]+   [2]-    [3]/   [4]all   \n" , 1 , 4 ));

int& count = game_stats.count ;


for ( int i = 0 ; i < count ; i ++ )
{
cout << " _________________________________________  \n";
cout << "           QUESTION  [" << i+1 <<  "/"  << count <<  "]  \n";
round ( game_stats , i );
}

final_winner( game_stats );

print_all_detail ( game_stats , count );

}


// *********************************************************************************************************************************************
// *********************************************************************************************************************************************
// *********************************************************************************************************************************************


int main ()
{
mlib::reset_screen();

do 
{
game ( );
} while ( mlib::want_to_repeat(" do you want to repeat ?  [y/n] \n"));


return 0;
}




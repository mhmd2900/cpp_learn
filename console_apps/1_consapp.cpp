#include<iostream>
#include<string>
#include "../general/mlib.h"

// using namespace std ;
using std::cout ;
using std::cin ;
using std::string ;




enum enchoices { paper=1 , stone=2 , scissor=3 };
enum enwinner { player , computer , draw };



struct stround_stat {
enchoices ply_choice ;
enchoices comp_choice ;
enwinner winner ;
};


struct stgame_stat {
int player = 0 ;
int computer = 0 ;
int draw = 0 ;
enwinner finalwinner ;
};
  

// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                          FUNCTIONS C
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

enchoices int_to_enchoices ( int num )
{
enchoices choice = static_cast<enchoices>(num) ;
return choice ;
}


string enchoices_to_string ( enchoices choice )
{
switch (choice)
{
case paper :
return "paper" ;
case stone :
return "stone" ;
case scissor :
return "scissor" ;
default :
return " unvalid option";
}
}


// string enchoices_to_string ( enchoices choice )
// {
// string choosen_option[3] = { "paper" , "stone" , "scissor"};
// return choosen_option[choice-1];
// }



string enwinner_to_string ( enwinner winner )
{
switch (winner)
{
case player :
return " player\n" ;
case computer :
return " computer\n" ;
case draw :
return " no winner       \n" ;
default :
return " unvalid option\n";
}
}



// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                          FUNCTIONS B
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

int how_many_rounds( )
{
    int count = mlib::get_number( " How many rounds do you want to play ? \n  plz between 1 and 5   \n " , 1 , 5);
    return count ;
}


void round_input (stround_stat& round_stat)  // & modify
{
round_stat.ply_choice  = int_to_enchoices  (mlib::get_number(  " plz enter your choice 1) paper    2) stone    3)scissor \n"  , 1 , 3 ));
round_stat.comp_choice = int_to_enchoices  (mlib::get_random( 1 , 3 ));
cout << " player   choice is   :   " << round_stat.ply_choice  << "    which is  " << enchoices_to_string( round_stat.ply_choice   )<<  "\n";
cout << " computer choice is   :   " << round_stat.comp_choice << "    which is  " << enchoices_to_string( round_stat.comp_choice  )<<  "\n";
}


void who_won (stround_stat& round_stat  , stgame_stat& game_stat) // & size    ,  & modify
{
    if ( round_stat.ply_choice == round_stat.comp_choice ) { round_stat.winner = draw;     game_stat.draw ++ ; }
    else {
       round_stat.winner = ( ( round_stat.ply_choice == paper && round_stat.comp_choice == stone    ) ||
                             ( round_stat.ply_choice == stone && round_stat.comp_choice == scissor  ) ||  
                             ( round_stat.ply_choice == scissor && round_stat.comp_choice == paper  )    )
                                  ? player  :computer  ;
        if ( round_stat.winner == player)    game_stat.player   ++;
        else                                 game_stat.computer ++; 
         }
          cout << " the round winner is    :  " << enwinner_to_string(round_stat.winner);
}


void who_final ( stgame_stat& game_stat ) // & size
{
cout << " ====================\n " ;
cout << "     final result    \n " ;
cout << " ====================\n " ;
cout << " player won   " << game_stat.player   << " times \n";
cout << " computer won " << game_stat.computer << " times \n";
cout << " draw   won   " << game_stat.draw     << " times \n";


if   ( game_stat.player  == game_stat.computer ) game_stat.finalwinner = draw ;
else game_stat.finalwinner = ( game_stat.player > game_stat.computer   ) ? player  : computer   ;

cout << " AT THE END :::::::: the final winner is   :::::::  "  << enwinner_to_string(game_stat.finalwinner);


// if ( game_stat.player  == game_stat.computer ) cout << " no final winner \n";
// else cout << ( ( game_stat.player > game_stat.computer  ) ? " player is the hero \n"    : " computer is the hero  \n" )   ;

// game_stat.player   = 0 ;
// game_stat.computer = 0 ;
// game_stat.draw     = 0 ;

}




// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
//                                                                          FUNCTIONS A
// ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════



void game( )  
{
stround_stat   round_stat  ;  // → Declare variables in the smallest scope that needs them.
stgame_stat game_stat ;

int count = how_many_rounds();

for ( int i = 1 ; i <= count ; i ++ )
    {
    cout << " ==================== \n  round " << i << " starts now \n";
    round_input ( round_stat );
    who_won (round_stat  , game_stat);
    }

who_final ( game_stat );
}


// *********************************************************************************************************************************************
// *********************************************************************************************************************************************
// *********************************************************************************************************************************************


int main ()
{
mlib::reset_screen();

// only define stgame_stat  ,, if it will accumulate results ( here , you want to frsh it each game )
// If main() also needed to read the stats after the game → then pass by reference from main()

do 
{
game();
} while ( mlib::want_to_repeat(" repeat ?      y or n \n"));


return 0 ;
}





#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std ;



void draw_board ( char board_values[3][3] )
{
for ( int i = 0 ; i < 7  ; i ++ )
{

if ( i % 2 == 0 )
for ( int j = 0 ; j < 13 ; j ++ )
cout << "-";

else
{
for ( int j = 0 ; j < 3 ; j ++ )
cout << "| " << board_values[i/2][j] << " " ;
cout << "|";
}

cout << endl ;
}
}



bool continue_game( char board_values[3][3] )
{
if ( board_values[2][0] == board_values[1][1]  &&  board_values[1][1] == board_values[0][2]   &&  board_values[1][1] != ' '  )
return false ;

else if ( board_values[0][0] == board_values[1][1]  &&  board_values[1][1] == board_values[2][2]   &&  board_values[1][1] != ' '  )
return false ;

for ( int i = 0 ; i < 3 ; i ++ )
if ( board_values[i][0] == board_values[i][1]  &&  board_values[i][1] == board_values[i][2]   &&  board_values[i][1] != ' '  )
return false ;

for ( int i = 0 ; i < 3 ; i ++ )
if ( board_values[0][i] == board_values[1][i]  &&  board_values[1][i] == board_values[2][i]   &&  board_values[1][i] != ' '  )
return false ;

return true ;

}


int main()
{

char board_values [3][3] = {{' ' , ' ' , ' '} , {' ' , ' ' , ' '} , {' ' , ' ' , ' '}};


draw_board( board_values);

char current_player = 'X';

int row = 0 , column = 0 , counter = 0 ;

do 
 { cout << " enter position \n";
   cin >> row >> column ;

        if ( row > 0 && row < 4 && column > 0 && column < 4 && board_values[row-1][column-1] == ' '  )
        {
        board_values[row-1][column-1] = current_player ;
        current_player = ( current_player == 'X') ?  'O' : 'X' ;
        continue_game(board_values) ;
        counter ++ ;
        }

        else 
        cout << " \n \n ERROR \n ,, enter correct position in empty place \n";

draw_board( board_values);

 } while ( counter < 9 && continue_game(board_values)  );


if (!continue_game(board_values) )
{
            current_player = ( current_player == 'X') ?  'O' : 'X' ;
cout << " winner is " << current_player << "\n";
}

else
cout << " no winner \n";



}

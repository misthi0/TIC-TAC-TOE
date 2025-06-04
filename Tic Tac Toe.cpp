#include <iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
char current_marker;
int current_player;
void drawBoard() 
{
cout <<endl;
for(int i=0; i<3; i++) 
{
cout << " " << board[i][0] << " | " << board[i][1] << " | " <<board[i][2] << endl;
if(i < 2) cout << "---|---|---"<<endl;
    }
cout << endl;
}
bool placeMarker(int slot) 
{
int row = (slot - 1) / 3;
int col = (slot - 1) % 3;
if(board[row][col] != 'X' && board[row][col] != 'O') 
{
board[row][col] = current_marker;
return true;
    } 
else 
    {
    return false;
    }
}
int winner() 
{
for(int i=0; i<3; i++) 
{
if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
return current_player;
if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
return current_player;
    }
 if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
 return current_player;
if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
return current_player;
return 0;
}
void swapPlayerAndMarker() {
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}
int main() {
cout << "Tic Tac Toe Game (2 Players)"<<endl;
cout << "Player 1, choose your marker (X or O): ";
cin >> current_marker;
while(current_marker != 'X' && current_marker != 'O') 
{
cout << "Invalid marker. Please choose X or O: ";
cin >> current_marker;
    }
current_player = 1;
int moves = 0;
drawBoard();
while(true) 
{
int slot;
cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
cin >> slot;
if(slot < 1 || slot > 9) 
{
cout << "Invalid slot. Try again."<<endl;
continue;
        }
if(!placeMarker(slot)) 
{
cout << "Slot already taken. Try again."<<endl;
continue;
        }
drawBoard();
moves++;
if(winner() == current_player) 
{
cout << "Player " << current_player << " wins!"<<endl;
break;
        } 
  else if(moves == 9) 
  {
    cout << "It's a draw!"<<endl;
    break;
        }
swapPlayerAndMarker();
    }
return 0;
}

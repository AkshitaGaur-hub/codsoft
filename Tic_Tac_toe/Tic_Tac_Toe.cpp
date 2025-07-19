#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int currentplayer;
char currentmarker;
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
    void drawboard(){
cout <<" "<<board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;\
cout <<"---|---|---" << endl;
cout <<" "<<board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
cout <<"---|---|---" << endl;   
cout <<" "<<board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
cout << endl;
    }

    bool place_marker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentmarker;
        return true;
    }
    else{
        return false;
    }
}
int winner(){
    //check rows
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            return currentplayer;
        }
    }
    //check columns
    for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            return currentplayer;
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
        return currentplayer;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
        return currentplayer;
    }
    return 0;
}
void swapplayer(){
    if(currentmarker == 'X'){
        currentmarker = 'O';
    } else {
        currentmarker = 'X';
    }
    if(currentplayer == 1){
        currentplayer = 2;
    } else {
        currentplayer = 1;
    }
}
void game(){
    cout << "Player1 choose your mark (X or O): ";
    char markerp1;
    cin >> markerp1;
    markerp1 = toupper(markerp1);
    char markerp2 = (markerp1 == 'X') ? 'O' : 'X';

     currentplayer = 1;
    currentmarker = markerp1;
    drawboard();
    int won =0;
    for(int i = 0; i < 9; i++) {
        cout << "Player " << currentplayer << "'s turn. Enter a number (1-9): ";
        int slot;
        cin >> slot;
        if(slot <1 || slot >9){
            cout <<"IT is invalid slot, you may try again";
            i--;
            continue;
        }
if(!place_marker(slot)){
            cout <<"This slot is already taken, you may try again";
            i--;
            continue;
        }
        drawboard();
        won = winner();
        if(won == 1){
            cout << "Player 1 wins!" << endl;
            break;
        }
        if(won == 2){
            cout << "Player 2 wins!" << endl;
            break;
        }
        swapplayer();
        currentmarker = (currentplayer == 1) ? markerp1 : markerp2;
    }
    if(won == 0){
        cout << "It's a draw!" << endl;
    }

}
int main()
{
    game();
    return 0;
}
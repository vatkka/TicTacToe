/*Assignment 2
* Dmitrii Frolov
* U214N1483
*/
#include <iostream>

using namespace std;

class TicTacToe {
public:
	TicTacToe();
	bool PlayMove(int Player, int row, int col);
	int Winner()const;
	bool GameOver()const;
	void DisplayBoard() const;

private:	
	int Board[3][3];
	int NoOfMoves;
};
/*initialises the data member NoOfMoves, and 
all the positions of the board to zero.*/
TicTacToe::TicTacToe() {				
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Board[i][j] = {0};
		}
	}
	NoOfMoves = 0;
}

int main() {
	int row, col,player,count = 0;
	bool check;
	TicTacToe game;
	do {		
		do {
			game.DisplayBoard();
			if (count % 2 == 0) {
				player = 1;
			}
			else {
				player = 2;
			}
			cout<< "\nPlayer " << player << " please enter position(column first):  ";
			cin >> row >> col;
			check = game.PlayMove(player, row, col);
		} while (check == false);
		count++;
	} while (game.GameOver() == false);
	game.DisplayBoard();
	if (game.Winner() != 0) {
		cout << "\nPlayer "<< game.Winner()<<" win";
	}
	else {
		cout << "\nDraw ";
	}
}

/*check if the	position(row, col) in the array is free then it will assign to that position the
	playernumber(parameter Player), it will increase the value of the data member NoOfMoves
	by one, and the function will return true, otherwise it will not change the value of the cell
	and the function will return false.*/
bool TicTacToe::PlayMove(int Player, int row, int col) { 
	
	row--;
	col--;
	if (row<3 && row >-1 && col<3 && col >-1) {
		if (Board[col][row] == 0) {
			Board[col][row] = Player;
			NoOfMoves++;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/*will return the winner of the game. A winner occurs
if one of the rows, or one of the columns, or one of the two diagonals belong to the same
player. If there is no winner in the game the function should return zero, otherwise it
should return the winner’s number.
*/
int TicTacToe::Winner() const
{
	for (int i = 0; i < 3; i++) {
		if (Board[i][0] == Board[i][1] && Board[i][0]  == Board[i][2] && Board[i][0] != 0) {
			return Board[i][0];
		}
		if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] && Board[0][i] != 0) {
			return Board[i][0];
		}
	}
	if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != 0) {
		return Board[0][0];
	}
	if (Board[2][0] == Board[1][1] && Board[2][0] == Board[0][2] && Board[2][0] != 0) {
		return Board[2][0];
	}
	return 0;
}

/*check whether a game is over or not. A game is
over if there is a winner or 9 moves have been played.*/
bool TicTacToe::GameOver() const
{
	if (Winner() != 0 || NoOfMoves == 9) {
		return true;
	}
	return false;
}

/*A method to display the game.*/
void TicTacToe::DisplayBoard() const
{	
	system("CLS");
	const int HEIGHT = 2, WIDTH = 4, ROWS = 3, COLS = 3;
	cout << "  1   2   3\n";
	int count2 = 1;
	for (int i = 0; i <= ROWS * HEIGHT; i++)
	{
		for (int j = 0; j <= COLS * WIDTH; j++)
		{
			if (i == 0 && j == 0) cout << char(201);
			else if (i == 0 && j == COLS * WIDTH) cout << char(187);
			else if (i == ROWS * HEIGHT && j == 0) cout << char(200);
			else if (i == ROWS * HEIGHT && j == COLS * WIDTH) cout << char(188);
			else if (i % HEIGHT == 0 && j == 0) cout << char(204);
			else if (i % HEIGHT == 0 && j == COLS * WIDTH) cout << char(185);
			else if (i == 0 && j % WIDTH == 0) cout << char(203);
			else if (i == ROWS * HEIGHT && j % WIDTH == 0) cout << char(202);
			else if (i % HEIGHT == 0 && j % WIDTH == 0) cout << char(206);
			else if (i % HEIGHT == 0) cout << char(205);
			else if (j % WIDTH == 0) { cout << char(186); if (count2 % 4 == 0) { cout << count2 / 4; } count2++; }
			else if ((i + HEIGHT / 2) % HEIGHT == 0 && (j + WIDTH / 2) % WIDTH == 0)
				if (Board[i / HEIGHT][j / WIDTH] == 0)
					cout << ' ';
				else if (Board[i / HEIGHT][j / WIDTH] == 1)
					cout << 'X';
				else
					cout << 'O';
			else cout << ' ';
		}
		cout << endl;
	}
}



#include <iostream>
using namespace std;
void pos(string command, int(&board)[8][8],int &Kx,int &Ky,int &Sx,int &Sy) {
	int x = Kx;
	int y = Ky;
	if(command=="R"){
		x++;
	}
	else if (command == "L") {
		x--;
	}
	else if (command == "L") {
		x--;
	}
	else if (command == "B") {
		y--;
	}
	else if (command == "T") {
		y++;
	}
	else if (command == "RT") {
		x++;
		y++;
	}
	else if (command == "LT") {
		x--;
		y++;
	}
	else if (command == "RB") {
		x++;
		y--;
	}
	else if (command == "LB") {
		x--;
		y--;
	}

	if (x < 0 || x >= 8 || y < 0 || y >= 8) {
		return;
	}
	if (x == Sx && y == Sy) {
		int xsx = Sx + (x - Kx);
		int ysy = Sy + (y - Ky);
		if (xsx < 0 || xsx >= 8 || ysy < 0 || ysy >= 8) return;
		board[Sx][Sy] = 0; 
		Sx = xsx;
		Sy = ysy;
		board[Sx][Sy] = 2; 
	}
	board[Kx][Ky] = 0; 
	Kx = x;
	Ky = y;
	board[Kx][Ky] = 1;

}

int main() {
	int board[8][8] = { 0 };
	string King, Stone, command;
	int N;
	cin >> King >> Stone >> N;
	int Kx = King[0] - 'A';
	int Ky = King[1] - '1';
	int Sx = Stone[0] - 'A';
	int Sy = Stone[1] - '1';
	board[Kx][Ky] = 1;
	board[Sx][Sy] = 2;
	while (N--) {
		cin >> command;
		pos(command, board, Kx, Ky, Sx, Sy);
	}
	cout << char(Kx + 'A') << char(Ky + '1') << '\n';
	cout << char(Sx + 'A') << char(Sy + '1') << '\n';

}
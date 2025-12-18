#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
	int N, K, L;
	cin >> N >> K;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
	vector<char> turn(10001, 0);
	while (K--) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 2;
	}
	cin >> L;
	while (L--) {
		int X; char C;
		cin >> X >> C;
		turn[X] = C;
	}
	deque<pair<int, int>> snake;
	snake.push_back({ 1, 1 });
	board[1][1] = 1;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	int dir = 0;
	int time = 0;
	while (true) {
		time++;
		int x = snake.front().first;
		int y = snake.front().second;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || nx > N || ny < 1 || ny > N)
			break;
		if (board[nx][ny] == 1)
			break;
		if (board[nx][ny] == 2) {
			board[nx][ny] = 1;
			snake.push_front({ nx, ny });
		}
		else {
			board[nx][ny] = 1;
			snake.push_front({ nx, ny });
			pair<int, int> tail = snake.back();
			snake.pop_back();
			board[tail.first][tail.second] = 0;
		}
		if (turn[time] != 0) {
			if (turn[time] == 'L')
				dir = (dir + 3) % 4;
			else
				dir = (dir + 1) % 4;
		}
	}
	cout << time;
	return 0;
}

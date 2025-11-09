#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int clockwise_rota(deque<int>& gear) {
	int temp = gear.back();
	gear.pop_back();
	gear.push_front(temp);
	return 0;
}

int counterclockwise_rota(deque<int>& gear) {
	int temp = gear.front();
	gear.pop_front();
	gear.push_back(temp);
	return 0;
}

int rotation(vector<deque<int>>& gear, int number, int clockwise) {
	int T = gear.size() - 1;
	vector<int> direc(T + 1, 0);
	direc[number] = clockwise;


	for (int i = number - 1; i >= 1; i--) {
		if (gear[i][2] != gear[i + 1][6])
			direc[i] = -direc[i + 1];
		else
			break;
	}

	for (int i = number + 1; i <= T; i++) {
		if (gear[i - 1][2] != gear[i][6])
			direc[i] = -direc[i - 1];
		else
			break;
	}

	for (int i = 1; i <= T; i++) {
		if (direc[i] == 1) clockwise_rota(gear[i]);
		else if (direc[i] == -1) counterclockwise_rota(gear[i]);
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	vector<deque<int>> gear(T + 1);
	for (int i = 1; i <= T; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			gear[i].push_back(c - '0');
		}
	}
	int K, number, clockwise;
	cin >> K;
	while (K--) {
		cin >> number >> clockwise;
		rotation(gear, number, clockwise);
	}
	int count = 0;
	for (int i = 1; i <= T; i++) {
		if (gear[i].front() == 1) count++;
	}
	cout << count;
	return 0;
}

#include <iostream>
using namespace std;
void add(int(&S)[21], int x) {
	if (S[x] == 0) {
		S[x] = 1;
	}
}
void remove(int(&S)[21], int x) {
	if (S[x] == 1) {
		S[x] = 0;
	}
}
void check(int(&S)[21], int x) {
	if (S[x] == 1) {
		cout << 1 << '\n';
	}
	else
		cout << 0 << '\n';
}
void toggle(int(&S)[21], int x) {
	if (S[x] == 1) {
		S[x] = 0;
	}
	else
		S[x] = 1;
}
void all(int(&S)[21]) {
	for (int i = 1; i <= 20; i++) S[i] = 1;
}
void empty(int(&S)[21]) {
	for (int i = 1; i <= 20; i++) S[i] = 0;
}
void action(int(&S)[21], string command, int x = 0) {
	if (command == "add") {
		add(S, x);
	}
	else if (command == "remove") {
		remove(S, x);
	}
	else if (command == "check") {
		check(S, x);
	}
	else if (command == "toggle") {
		toggle(S, x);
	}
	else if (command == "all") {
		all(S);
	}
	else if (command == "empty") {
		empty(S);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int S[21] = { 0 };
	int M;
	cin >> M;
	string command; int x;
	while (M--) {
		cin >> command;
		if (command == "add" || command == "remove" ||
			command == "check" || command == "toggle") {
			cin >> x;
			action(S, command, x);
		}
		else {
			action(S, command);
		}
	}
}
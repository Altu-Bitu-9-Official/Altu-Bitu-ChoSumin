#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int do_turn(deque<int>& do_d, deque<int>& do_g) {
	if (!do_d.empty()) {
		do_g.push_front(do_d.front());
		do_d.pop_front();
	}
	return 0;
}
int su_turn(deque<int>& su_d, deque<int>& su_g) {
	if (!su_d.empty()) {
		su_g.push_front(su_d.front());
		su_d.pop_front();
	}
	return 0;
}
int condition(deque<int>& do_d, deque<int>& do_g, deque<int>& su_d, deque<int>& su_g) {
	if (!do_g.empty() && !su_g.empty() && (do_g.front() + su_g.front()) == 5) {
		while (!do_g.empty()) {
			su_d.push_back(do_g.back());
			do_g.pop_back();
		}
		while (!su_g.empty()) {
			su_d.push_back(su_g.back());
			su_g.pop_back();
		}
		return 0;
	}
	else if ((!do_g.empty() && do_g.front() == 5) || (!su_g.empty() && su_g.front() == 5)) {
		while (!su_g.empty()) {
			do_d.push_back(su_g.back());
			su_g.pop_back();
		}
		while (!do_g.empty()) {
			do_d.push_back(do_g.back());
			do_g.pop_back();
		}
		return 0;
	}
	return 0;
}

int main() {
	int N, M;
	cin >> N >> M;
	deque<int> do_d, su_d, do_g, su_g;
	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		do_d.push_front(temp1);
		su_d.push_front(temp2);
	}
	string winner = " ";
	bool turn_do = true;
	for (int i = 0; i < M; i++) {
		if (turn_do) {
			do_turn(do_d, do_g);
			if (do_d.empty()) { winner = "su"; break; }
			condition(do_d, do_g, su_d, su_g);
		}
		else {
			su_turn(su_d, su_g);
			if (su_d.empty()) { winner = "do"; break; }
			condition(do_d, do_g, su_d, su_g);
		}
		turn_do = !turn_do;
	}

	if (winner == " ") {
		if (do_d.size() > su_d.size()) {
			winner = "do";
		}
		else if (do_d.size() < su_d.size()) {
			winner = "su";
		}
		else
			winner = "dosu";
	}
	cout << winner;
	return 0;
}
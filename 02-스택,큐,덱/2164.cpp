#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main() {
	int N;
	int k = 0;
	cin >> N;
	deque<int> card;
	for (int i = 1; i <= N; i++) {
		card.push_back(i);
	}
	while (card.size() > 1) {
		card.pop_front();
		if (card.size() != 1) {
			k = card.front();
			card.pop_front();
			card.push_back(k);
		}

	}
	cout << card.back();
}
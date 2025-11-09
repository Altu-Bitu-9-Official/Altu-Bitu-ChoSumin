#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, number;
	cin >> N;
	vector<deque<int>> line(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> number;
			line[j].push_back(number);
		}
	}
	priority_queue<pair<int, int>> pq;
	for (int j = 0; j < N; j++) {
		pq.push({ line[j].back(), j });
		line[j].pop_back();
	}
	int count = 0;
	int Gnumber = 0;
	int nextl;
	while (count < N && !pq.empty()) {
		Gnumber = pq.top().first;
		nextl = pq.top().second;
		pq.pop();
		if (!line[nextl].empty()) {
			pq.push({ line[nextl].back(),nextl });
			line[nextl].pop_back();
		}
		count++;
	}
	cout << Gnumber;
	return 0;

}
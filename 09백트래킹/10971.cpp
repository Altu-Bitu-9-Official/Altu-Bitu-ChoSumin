#include <iostream>
#include <vector>
using namespace std;

void visit(int count, int N, int now, int start, vector<vector<int>>& w, int cost, int& min_cost, vector<bool>& visited) {
	if (count == N) {
		if (w[now][start] != 0) {
			if (cost + w[now][start] < min_cost)
				min_cost = cost + w[now][start];
		}
		return;
	}
	for (int next = 0; next < N; next++) {
		if (visited[next] == false && w[now][next] != 0) {
			if (cost + w[now][next] < min_cost) {
				visited[next] = true;
				visit(count + 1, N, next, start, w, cost + w[now][next], min_cost, visited);
				visited[next] = false;
			}
		}
	}
}

int main() {
	int N;
	int cost = 0;
	int min_cost = 1000000 * 10;
	cin >> N;
	vector<vector<int>> w(N, vector<int>(N));
	vector<bool> visited(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
	for (int start = 0; start < N; start++) {
		visited.assign(N, false);
		visited[start] = true;
		visit(1, N, start, start, w, 0, min_cost, visited);
	}
	cout << min_cost;
	return 0;
}

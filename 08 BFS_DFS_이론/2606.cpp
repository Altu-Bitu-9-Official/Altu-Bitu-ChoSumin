#include <iostream>
#include <queue>
using namespace std;
bool visited[101];
int graph[101][101];
int bfs(int start, int n) {
	int cnt = 0;
	queue<int>q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (graph[now][i] == 1) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
					cnt++;
				}
			}
		}
	}

	return cnt;
}
int main() {
	int n, m;

	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	int ans = bfs(1, n);
	cout << ans;
}
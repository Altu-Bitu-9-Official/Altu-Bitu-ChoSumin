#include <iostream>
using namespace std;
bool visited[101];
int family[101][101];
int dfs(int now, int n, int b, int cnt) {
	visited[now] = true;
	if (now == b) {
		return cnt;
	}
	for (int i = 1; i <= n; i++) {
		if (family[now][i] == 1) {
			if (!visited[i]) {
				int result = dfs(i, n, b, cnt + 1);
				if (result != -1)
					return result;
			}
		}
	}
	return -1;
}
int main() {
	int n, a, b, m, ans;
	int cnt = 0;
	cin >> n;
	cin >> a >> b;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		family[x][y] = 1;
		family[y][x] = 1;
	}
	ans = dfs(a, n, b, cnt);
	cout << ans;
}
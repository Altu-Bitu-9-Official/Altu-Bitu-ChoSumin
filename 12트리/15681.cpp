#include <iostream>
#include <vector>
using namespace std;
int dfs(int node, int parent, vector<vector<int>>& adjacent, vector<int>& subtree) {
	subtree[node] = 1;
	for (int i = 0; i < adjacent[node].size(); i++) {
		int child = adjacent[node][i];
		if (child == parent) continue;
		subtree[node] += dfs(child, node, adjacent, subtree);
	}
	return subtree[node];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, R, Q;
	cin >> N >> R >> Q;
	vector<vector<int>> adjacent(N + 1);
	vector<int> subtree(N + 1, 0);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	dfs(R, 0, adjacent, subtree);

	while (Q--) {
		int U;
		cin >> U;
		cout << subtree[U] << "\n";
	}

	return 0;
}

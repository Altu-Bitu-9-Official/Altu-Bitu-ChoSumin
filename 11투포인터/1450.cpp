#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int idx, int end, long long sum, vector<long long>& v, vector<int>& object) {
	if (idx == end) {
		v.push_back(sum);
		return;
	}
	dfs(idx + 1, end, sum, v, object);
	dfs(idx + 1, end, sum + object[idx], v, object);
}
int main() {
	int N;
	long long C;
	cin >> N >> C;
	vector<int> object(N);
	for (int i = 0; i < N; i++) {
		cin >> object[i];
	}
	vector<long long> v1, v2;
	dfs(0, N / 2, 0, v1, object);
	dfs(N / 2, N, 0, v2, object);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long ans = 0;
	int j = v2.size() - 1;

	for (int i = 0; i < v1.size(); i++) {
		while (j >= 0 && v1[i] + v2[j] > C) {
			j--;
		}
		if (j < 0) break;
		ans += (j + 1);
	}


	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int solution(int N, int d, int k, int c, vector<int>& sushi) {
	vector<int> cnt(d + 1, 0);
	int kind = 0;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (cnt[sushi[i]] == 0) kind++;
		cnt[sushi[i]]++;
	}
	if (cnt[c] == 0) {
		ans = kind + 1;
	}
	else {
		ans = kind;
	}

	for (int i = 1; i < N; i++) {
		int remove = sushi[i - 1];
		cnt[remove]--;
		if (cnt[remove] == 0)
			kind--;
		int add = sushi[(i + k - 1) % N];
		if (cnt[add] == 0)
			kind++;
		cnt[add]++;

		if (cnt[c] == 0) {
			ans = max(ans, kind + 1);
		}
		else {
			ans = max(ans, kind);
		}
	}
	return ans;
}
int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	vector<int> sushi(N);
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
	cout << solution(N, d, k, c, sushi);
	return 0;
}

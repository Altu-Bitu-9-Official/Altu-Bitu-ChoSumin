#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> A(n), dp(n, 1), tem;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		len = max(len, dp[i]);
	}
	cout << len;
	return 0;
}
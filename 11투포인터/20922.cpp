#include <iostream>
#include <vector>
using namespace std;
int solution(int N, int K, const vector<int>& array) {
	vector<int> count(100001, 0);
	int ans = 0;
	int left = 0;
	for (int right = 0; right < N; right++) {
		count[array[right]]++;

		while (count[array[right]] > K) {
			count[array[left]]--;
			left++;
			if (left < right)
				continue;
		}
		ans = max(ans, (right - left) + 1);
	}
	return ans;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> array(N);
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cout << solution(N, K, array);
	return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void calc_func(int now, int result, int N, vector<int>& calc, vector<int>& arr, int& max_result, int& min_result) {
	if (now == N) {
		if (result > max_result) {
			max_result = result;
		}
		if (result < min_result) {
			min_result = result;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (calc[i] > 0) {
			calc[i] = calc[i] - 1;
			int next_result;
			switch (i) {
			case 0:
				next_result = result + arr[now];
				break;
			case 1:
				next_result = result - arr[now];
				break;
			case 2:
				next_result = result * arr[now];
				break;
			case 3:
				if (result > 0) {
					next_result = result / arr[now];
				}
				else
					next_result = -(-result / arr[now]);
				break;
			default:
				break;
			}
			calc_func(now + 1, next_result, N, calc, arr, max_result, min_result);
			calc[i] = calc[i] + 1;
		}

	}
	return;
}


int main() {
	int N;
	cin >> N;
	vector<int>arr(N);
	vector<int>calc(4);
	int max_result = INT_MIN;
	int min_result = INT_MAX;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
	calc_func(1, arr[0], N, calc, arr, max_result, min_result);
	cout << max_result << '\n' << min_result;

	return 0;
}


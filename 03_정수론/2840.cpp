#include <iostream>
#include <vector>

using namespace std;

static bool is_available(vector<char>& array, vector<bool>& duplicate, int next_index, char b) {
	if (array[next_index] == '?') {
		if (duplicate[b - 'A']) {
			return false;
		}
	}
	else if (array[next_index] != b) {
		return false;
	}
	return true;
}

int main() {
	int N, K, a;
	char b;
	int index = 0;
	bool is_valid = true;

	cin >> N >> K;
	vector<char> array(N, '?');
	vector<bool> duplicate(26, false);

	for (int i = 0; i < K; ++i) {
		cin >> a >> b;

		int next_index = (index - a % N + N) % N;

		if (is_available(array, duplicate, next_index, b)) {

			if (array[next_index] == '?') {
				array[next_index] = b;
				duplicate[b - 'A'] = true;
			}
			index = next_index;
		}
		else {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		cout << "!";
	}
	else {
		for (int i = 0; i < N; ++i) {
			cout << array[(index + i) % N];
		}
	}

	return 0;
}
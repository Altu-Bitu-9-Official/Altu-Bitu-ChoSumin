#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int digit(const string& s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (isdigit(c)) {
			stringstream ss;
			ss << c;
			int num;
			ss >> num;
			sum += num;
		}

	}
	return sum;
}

bool comp(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}
	int sumS1 = digit(s1);
	int sumS2 = digit(s2);
	if (sumS1 != sumS2) {
		return sumS1 < sumS2;
	}
	return s1 < s2;

}
int main() {
	int N;
	cin >> N;
	vector<string> serials(N);
	for (int i = 0; i < N; i++) {
		cin >> serials[i];
	}
	sort(serials.begin(), serials.end(), comp);
	for (int i = 0; i < N; i++) {
		cout << serials[i] << "\n";
	}
	return 0;
}
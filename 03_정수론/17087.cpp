#include <iostream>
#include <vector>
using namespace std;
int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int main() {
	int N, S;
	cin >> N >> S;
	vector<int>arr(N), distance(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		distance[i] = abs(arr[i] - S);
	}
	int D = distance[0];
	for (int i = 1; i < N; i++) {
		D = gcdIter(D, distance[i]);
	}
	cout << D;
	return 0;
}
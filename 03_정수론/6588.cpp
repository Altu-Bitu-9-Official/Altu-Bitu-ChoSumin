#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void isPrime(int n, vector<bool>& is_prime) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j = j + i) {
				is_prime[j] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	n = 1;
	const int MAX = 1000000;
	vector<bool> is_prime(MAX + 1, true);
	isPrime(MAX, is_prime);
	while (true) {
		cin >> n;
		if (n == 0) break;
		bool found = false;
		for (a = 3; a < n; a = a + 2) {
			b = n - a;
			if (is_prime[a] && is_prime[b]) {
				cout << n << " = " << a << " + " << b << '\n';
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int eating(vector<char>& table, int K, int N) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
			
				if (j >= 0 && j < N && table[j] == 'H') {
					table[j] = 'N'; 
					break;         
				}
			}
		}
	}
	return 0;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<char> table(N);
	string S;
	cin >> S;
	for (int i = 0; i < table.size(); i++) {
		table[i] = S[i];
	}
	eating(table, K, N);
	int eatenpeople = 0;
	for (int i = 0; i < table.size(); i++) {
		if (table[i] == 'N')
			eatenpeople++;
	}
	cout << eatenpeople;
}
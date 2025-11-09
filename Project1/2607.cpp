#include <iostream>
#include <vector>
using namespace std;
int alphabet_f(vector<int>& alphabet, string word) {
	alphabet.assign(26, 0);
	for (char c : word) {
		alphabet[c - 'A']++;
	}
	return 0;
}
bool similar(vector<int>& standard_al, vector<int>& word_al, string word, string standard) {
	int diff = 0;
	for (int i = 0; i < 26; i++) {
		diff = diff + abs(standard_al[i] - word_al[i]);
	}
	if (diff <= 1) {
		return true;
	}
	else if (diff == 2) {
		if (word.size() == standard.size())
			return true;
		else
			return false;
	}
	else
		return false;
}
int main() {
	int n;
	int difference = 0;
	string standard, word;
	cin >> n;
	cin >> standard;
	vector<int> standard_alphabet;
	vector<int> word_alphabet;
	alphabet_f(standard_alphabet, standard);
	n = n - 1;
	while (n--) {
		cin >> word;
		alphabet_f(word_alphabet, word);
		if (similar(standard_alphabet, word_alphabet, standard, word)) {
			difference++;
		}
	}
	cout << difference;
}
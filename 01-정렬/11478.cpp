#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	set<string> str;
	for (int i = 0; i < s.size(); i++) {
		string temp = "";
		for (int j = i; j < s.size(); j++) {
			temp = temp + s[j];
			str.insert(temp);
		}
	}
	cout << str.size();
	return 0;

}
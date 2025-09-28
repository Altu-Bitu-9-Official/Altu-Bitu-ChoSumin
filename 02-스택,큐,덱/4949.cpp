#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {


	string s;
	while (true) {
		getline(cin, s);
		if (s == ".")
			break;
		stack<char> ss;
		bool balance = true;



		for (int j = 0; j < s.size(); j++) {
			char c = s[j];
			if (c == '(') {
				ss.push(c);
			}
			else if (c == '[') {
				ss.push(c);
			}
			else if (c == ')') {
				if (!ss.empty() && ss.top() == '(') {
					ss.pop();
				}
				else {
					balance = false;
					break;
				}

			}
			else if (c == ']') {
				if (!ss.empty() && ss.top() == '[') {
					ss.pop();
				}
				else {
					balance = false;
					break;
				}


			}


		}

		if (balance && ss.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}



	}
	return 0;
}
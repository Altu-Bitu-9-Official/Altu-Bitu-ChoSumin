#include <string>
#include <iostream>
#include <vector>
#include <deque>


using namespace std;

deque<int> sum_calc(deque<int>& A, deque<int>& B, deque<int>& C, int& carry) {

	if (A.back() + B.back() + carry > 9) {
		C.push_front((A.back() + B.back() + carry) % 10);
		carry = 1;
		A.pop_back(); B.pop_back();
	}
	else {
		C.push_front(A.back() + B.back() + carry);
		carry = 0;
		A.pop_back(); B.pop_back();
	}
	return C;
}


using namespace std;
int main() {
	string sA, sB, sC;
	cin >> sA >> sB;
	deque<int> a, b, c;
	int carry = 0;
	for (int i = 0; i < sA.size(); i++) {
		a.push_back(sA[i] - '0');
	}
	for (int i = 0; i < sB.size(); i++) {
		b.push_back(sB[i] - '0');
	}

	while (a.empty() == 0 && b.empty() == 0) {
		sum_calc(a, b, c, carry);
	}

	while (a.empty()) {
		if (b.empty()) {
			break;
		}
		if (b.back() + carry > 9) {
			c.push_front(0);
			carry = 1;

		}
		else {
			c.push_front(b.back() + carry);
			carry = 0;

		}
		b.pop_back();

	}
	while (b.empty()) {
		if (a.empty()) {
			break;
		}
		if (a.back() + carry > 9) {
			c.push_front(0);
			carry = 1;
		}
		else {
			c.push_front(a.back() + carry);
			carry = 0;
		}
		a.pop_back();

	}
	if (carry == 1) {
		c.push_front(1);
	}
	sC = "";
	for (int i = 0; i < c.size(); i++) {
		sC = sC + char(c[i] + '0');
	}
	cout << sC;

	return 0;

}
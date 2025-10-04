#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long W0, I0;
	int T;
	cin >> W0 >> I0 >> T;
	int D;
	long long I, A;
	cin >> D >> I >> A;
	long long W = 0;
	long long ID = 0;
	long long delta = 0;

	//기초 대사량 변화 고려하지 않은 겨우
	bool dead = false;
	W = W0;
	for (int day = 1; day <= D; day++) {
		delta = I - (I0 + A);
		W = W + delta;
		if (W <= 0) {
			dead = true;
			break;
		}
	}
	if (dead == true) {
		cout << "Danger Diet\n";
	}
	else
		cout << W << " " << I0 << "\n";

	//기초 대사량 변화 고려한 겨우
	dead = false;
	W = W0;
	ID = I0;
	for (int day = 1; day <= D; day++) {
		delta = I - (ID + A);
		W = W + delta;
		if (W <= 0) {
			dead = true;
			break;
		}
		if (std::abs(delta) > T) {
			if (delta >= 0) {
				ID = ID + (delta / 2);
			}
			else
				ID = ID + float(delta) / 2.0;
		}
		if (ID <= 0) {
			dead = true;
			break;
		}

	}
	if (dead == true) {
		cout << "Danger Diet\n";
	}
	else
		cout << W << " " << ID << " ";

	if (I0 > ID) {
		cout << "YOYO";
	}
	else
		cout << "NO";

	return 0;

}
#include <iostream>
using namespace std;

int main() {
    int K, direc, length;
    int a, b, x, y;
    pair<int, int> arr[6];

    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> direc >> length;
        arr[i].first = direc;
        arr[i].second = length;
    }

    int maxW = 0, maxH = 0;
    int idxW = -1, idxH = -1;

    for (int i = 0; i < 6; i++) {
        if (arr[i].first == 1 || arr[i].first == 2) {
            if (arr[i].second > maxW) {
                maxW = arr[i].second;
                idxW = i;
            }
        }
        else {
            if (arr[i].second > maxH) {
                maxH = arr[i].second;
                idxH = i;
            }
        }
    }

    a = maxW;
    b = maxH;

    x = abs(arr[(idxW + 5) % 6].second - arr[(idxW + 1) % 6].second);
    y = abs(arr[(idxH + 5) % 6].second - arr[(idxH + 1) % 6].second);

    int width = (a * b) - (x * y);
    cout << width * K;
    return 0;
}

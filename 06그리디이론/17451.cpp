#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {   
        cin >> v[i];
    }
    long long velocity = v[n - 1];   
    for (int i = n - 2; i >= 0; i--) {
        if (velocity % v[i] != 0) {       
            long long times = (velocity + v[i] - 1) / v[i];
            velocity = times * v[i];          
        }
    }

    cout << velocity 
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct person {
    int id;
    int Di;
    int Hi;
    int line;
};


struct cmp {
    bool operator()(const person& a, const person& b) {
        if (a.Di != b.Di) return a.Di < b.Di;
        if (a.Hi != b.Hi) return a.Hi < b.Hi;
        return a.line > b.line;
    }
};

int main() {
    int N, M, K, D, H;
    cin >> N >> M >> K;
    vector<queue<person>> lines(M);
    priority_queue<person, vector<person>, cmp> pq;

    for (int i = 0; i < N; i++) {
        cin >> D >> H;
        person p = { i + 1, D, H, i % M };
        lines[i % M].push(p);
        if (lines[i % M].size() == 1) pq.push(p);
    }

    int count = 0;
    while (!pq.empty()) {
        person cur = pq.top(); pq.pop();
        count++;
        if (cur.id == K + 1) {
            cout << count - 1;
            break;
        }

        int l = cur.line;
        lines[l].pop();
        if (!lines[l].empty()) pq.push(lines[l].front());
    }
}

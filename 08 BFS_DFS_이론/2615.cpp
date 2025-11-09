#include <iostream>
using namespace std;

int graph[20][20];
int dy[4] = { 0, 1, 1, -1 };
int dx[4] = { 1, 0, 1, 1 };

bool search(int r, int c, int color) {
    for (int i = 0; i < 4; i++) {
        int cnt = 1;
        int nr = r + dy[i];
        int nc = c + dx[i];
        while (nr >= 1 && nr <= 19 && nc >= 1 && nc <= 19 && graph[nr][nc] == color) {
            cnt++;
            nr += dy[i];
            nc += dx[i];
        }
        if (cnt == 5) {
            int rr = r - dy[i];
            int cc = c - dx[i];
            if (rr >= 1 && rr <= 19 && cc >= 1 && cc <= 19 && graph[rr][cc] == color)
                continue;
            else
                return true;
        }
    }
    return false;
}

int main() {
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> graph[i][j];
        }
    }

    for (int r = 1; r <= 19; r++) {
        for (int c = 1; c <= 19; c++) {
            if (graph[r][c] == 0) continue;
            if (search(r, c, graph[r][c])) {
                cout << graph[r][c] << "\n" << r << " " << c;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}

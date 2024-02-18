#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 4;
const int dx[K] = { 0, 0, 1, -1 };
const int dy[K] = { 1, -1, 0, 0 };

const int N = 405;
const int INF = 1e18+8;

int a[N][N];
int d[N][N];
pair<int, int> p[N][N];

int n, m;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != -1;
}

signed main() {
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            if (s == "A") {
                sx = i;
                sy = j;
                a[i][j] = 0;
            }
            else if (s == "B") {
                ex = i;
                ey = j;
                a[i][j] = 0;
            }
            else {
                a[i][j] = stoi(s);
            }
            d[i][j] = INF;
        }
    }
    bool upd = true;
    d[sx][sy] = 0;
    while(upd) {
        upd = false;
        for (int cx = 0; cx < n; ++cx) {
            for (int cy = 0; cy < m; ++cy) {
                int cd = d[cx][cy];
                for (int k = 0; k < K; ++k) {
                    int nx = cx+dx[k];
                    int ny = cy+dy[k];
                    if (!valid(nx, ny)) continue;
                    if (cd+a[nx][ny] >= d[nx][ny]) continue;
                    d[nx][ny] = cd+a[nx][ny];
                    p[nx][ny] = {cx, cy};
                    upd = true;
                }
            }
        }
        if (!upd) break;
    }
    pair<int, int> cp = {ex, ey};
    vector<pair<int, int>> ans;
    while (cp != pair<int, int>(sx, sy)) {
        ans.push_back(cp);
        cp = p[cp.first][cp.second];
    }
    ans.push_back({sx, sy});
    reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}
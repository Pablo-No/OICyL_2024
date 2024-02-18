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
    priority_queue<pair<int, pair<int, int>>> pq;
    d[sx][sy] = 0;
    pq.push({0, {sx, sy}});
    while (!pq.empty()) {
        int cd = -pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();
        if (cd != d[cx][cy]) continue;
        for (int k = 0; k < K; ++k) {
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            if (!valid(nx, ny)) continue;
            if (cd+a[nx][ny] >= d[nx][ny]) continue;
            d[nx][ny] = cd+a[nx][ny];
            pq.push({-d[nx][ny], {nx, ny}});
            p[nx][ny] = {cx, cy};
        }
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

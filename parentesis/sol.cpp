#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 205;
const int D = M*N;

int dp[N][N*M*2]; // pos, value (offset) = parenthesis remaining

int main() {
    int t;
    cin >> t;
    string ig;
    getline(cin, ig);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        string line;
        getline(cin, line);
        stringstream lin(line);
        int x;
        lin >> x;
        char c;
        dp[0][D] = 1;
        int cnt = 0;
        while (lin >> c >> x) {
            for (int v = 0; v < N*M*2; ++v) {
                int p = dp[cnt][v];
                if (p) {
                    if (c == '-') ++p;
                    dp[cnt+1][v+((p%2)?x:-x)] = max(dp[cnt+1][v+((p%2)?x:-x)], p);
                    --p;
                    if (c != '-' || p > 1) {
                        dp[cnt+1][v+((p%2)?x:-x)] = max(dp[cnt+1][v+((p%2)?x:-x)], p);
                    }
                }
            }
            ++cnt;
        }
        int ans = 0;
        for (int i = 0; i < N*M*2; ++i) ans += (dp[cnt][i] != 0);
        cout << ans << '\n'; 
    }
}
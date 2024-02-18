#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

const int N = 53;
const int M = 202;
const int D = M*N;

bool dp[N][N][N*M*2]; // pos, value (offset), parenthesis remaining

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
        dp[0][1][D] = 1;
        int cnt = 0;
        while (lin >> c >> x) {
            for (int ip = 1; ip <= cnt+1; ++ip) {
                for (int v = M*(N-cnt); v <= M*(N+cnt); ++v) {
                    int p = ip;
                    if (dp[cnt][p][v]) {
                        if (c == '-') ++p;
                        dp[cnt+1][p][v+((p%2)?x:-x)] = true;
                        --p;
                        if (c != '-' || p > 1) {
                            dp[cnt+1][p][v+((p%2)?x:-x)] = true;
                        }
                    }
                }
            }
            ++cnt;
        }
        set<int> ans;
        for (int p = 1; p <= cnt+1; ++p)
            for (int v = M*(N-cnt); v <= M*(N+cnt); ++v)
                if (dp[cnt][p][v])
                    ans.insert(v);
        cout << ans.size() << '\n'; 
    }
}
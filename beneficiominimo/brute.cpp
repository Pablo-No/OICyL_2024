#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int a, b, q;
    cin >> a >> b >> q;
    map<int, int> f;
    while (q--) {
        char c;
        int v;
        cin >> c >> v;
        if (c == '+') {
            ++f[v];
        }
        else {
            --f[v];
            if (f[v] == 0) f.erase(v);
        }
        int bestv = 0;
        auto pc = f.begin();
        auto pv = f.begin();
        while (pc != f.end()) {
            while (pv != f.end() && (pv->first)*b-(pc->first)*a <= 0) ++pv;
            if (pv == f.end()) break;
            int gain = (pv->first)*b-(pc->first)*a;
            if (bestv == 0 or gain < bestv) bestv = gain;
            ++pc;
        }

        cout << bestv << '\n';
    }
}

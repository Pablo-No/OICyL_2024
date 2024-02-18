#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int v, l, r;
    cin >> v >> l >> r;
    if (v >= r) cout << "A\n";
    else if ((v-l)*100 >= (r-l)*60) cout << "B\n";
    else if ((v-l)*100 > (r-l)*40) cout << "C\n";
    else if (v > l) cout << "D\n";
    else cout << "E\n";
}

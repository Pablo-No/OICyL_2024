#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int bd = 1e9;
    string bs;
    while (n--) {
        string t;
        cin >> t;
        int d = 0;
        for (int i = 0; i < s.size(); ++i) d += (s[i] != t[i]);
        if (d < bd) bd = d, bs = t;
    }
    cout << bs << '\n';
}
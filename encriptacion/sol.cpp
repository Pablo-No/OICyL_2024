#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    int ns = s.size();
    int d = 0;
    while(getline(cin, t)) {
        for (char c : t) {
            cout << (int(c)^((int(s[d%ns])+d/ns)%256)) << ' ';
            ++d;
        }
        cout << '\n';
    }
}

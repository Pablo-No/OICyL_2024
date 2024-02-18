#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string f3 = s.substr(0, 3);
        if (s.size() != 9) cout << "otros\n";
        else if (f3 == "803" ||
            f3 == "806" ||
            f3 == "807" ||
            f3 == "905" ||
            f3 == "907") cout << "$$$\n";
        else if ((s[0] == '9' || s[0] == '8') &&
                 (s[1] != '0' && s[1] != '9')) cout << "fijo\n";
        else if (s[0] == '6' || s[0] == '7') cout << "movil\n";
        else cout << "otros\n";
    }
}
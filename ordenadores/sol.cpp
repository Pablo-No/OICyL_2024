#include <bits/stdc++.h>
using namespace std;

int main() {
    int cy;
    cin >> cy;
    int n;
    cin >> n;
    vector<string> update;
    vector<string> retire;
    while (n--) {
        int y;
        string id, ig;
        cin >> id >> ig >> y >> ig >> ig >> ig >> ig;
        if (y <= cy-3) retire.push_back(id);
        else update.push_back(id);
    }
    cout << "ACTUALIZAR\n";
    for (auto id : update) cout << id << '\n';
    cout << "RETIRAR\n";
    for (auto id : retire) cout << id << '\n';
}

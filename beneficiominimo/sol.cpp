// Esta es la solucion intencionada.
// Intenta tener claridad.
// Complejidad: O(q*log(q))
#include <iostream>
#include <set>
#include <map>

#define int long long

using namespace std;

set<pair<int, int>> opts; // Opciones reales de compra o venta.
// El segundo numero es 0 para compra y 1 para venta.
map<int, int> pos; // Posibles resultados

void ch(pair<int, int> opa, pair<int, int> opb, int ch) {
    if (opb.second == 1 && opa.second == 0) {
        int gain = opb.first-opa.first;
        pos[gain] += ch;
        if (pos[gain] == 0) pos.erase(gain);
    }
}

void add(pair<int, int> op) {
    auto pt = opts.lower_bound(op);
    if (pt != opts.begin()) {
        --pt;
        pair<int, int> opl = *pt;
        ++pt;
        ch(opl, op, +1);
    }
    if (pt != opts.end()) {
        pair<int, int> opr = *pt;
        ch(op, opr, +1);
    }
    if (pt != opts.begin() && pt != opts.end()) {
        pair<int, int> opr = *pt;
        --pt;
        pair<int, int> opl = *pt;
        ++pt;
        ch(opl, opr, -1);        
    }
    opts.insert(op);
}

void rem(pair<int, int> op) {
    opts.erase(op);
    auto pt = opts.lower_bound(op);
    if (pt != opts.begin()) {
        --pt;
        pair<int, int> opl = *pt;
        ++pt;
        ch(opl, op, -1);
    }
    if (pt != opts.end()) {
        pair<int, int> opr = *pt;
        ch(op, opr, -1);
    }
    if (pt != opts.begin() && pt != opts.end()) {
        pair<int, int> opr = *pt;
        --pt;
        pair<int, int> opl = *pt;
        ++pt;
        ch(opl, opr, +1);        
    }
}

signed main() {
    int a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    map<int, int> f; // Frecuencia de cada valor.
    for (int k = 0; k < q; ++k) {
        char c;
        cin >> c;
        int v;
        cin >> v;
        pair<int, int> opc = {v*a+1, 0};
        pair<int, int> opv = {v*b, 1};
        if (c == '+') {
            ++f[v];
            if (f[v] == 1) {
                add(opc);
                add(opv);
            }
        }
        else {
            --f[v];
            if (f[v] == 0) {
                rem(opc);
                rem(opv);
            }
        }
        if (pos.empty()) cout << "0\n";
        else cout << (pos.begin()->first)+1 << '\n';
    }
}

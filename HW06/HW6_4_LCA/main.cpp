#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<int> child[200005];
int p[200005];
int d[200005];
int jmp[200005][19];

void print_parents(int n) {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << "p[" << i << "] = " << p[i] << endl;
    }
}
void print_childs(int n) {
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (auto el:child[i]) {
            cout << el << ", ";
        }
        cout << endl;
    }
}
void print_depths(int n) {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << "d[" << i << "] = " << d[i] << endl;
    }
}
void print_jmp(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int k = 0; k < 6; k++) {
            cout << jmp[i][k] << " ";
        }
        cout << endl;
    }
}

void dfs(int root) {
    for (auto v : child[root]) {
        d[v] = d[root] + 1;
        dfs(v);
    }
}

void precalc(int n) {
    dfs(1);
    for (int i = 1; i <= n; i++) {
        jmp[i][0] = p[i];
    }
    for (int k = 1; k <= (int)log2(n)+1; k++) {
        for (int i = 1; i <= n; i++) {
            jmp[i][k] = jmp[jmp[i][k - 1]][k - 1];
        }
    }
}
int dummy_lca(int u, int v) {
    if (d[v] > d[u]) {
        swap(u, v);
    }
    while (d[v] != d[u]) {
        u = p[u];
    }
    while (u != v) {
        u = p[u];
        v = p[v];
    }
    return v;
}

int dummy_pow(int v, int k) {
    int res = 1;
    while (k--) {
        res *= v;
    }
    return res;
}

int lca(int u, int v, int n) {
    if (d[v] > d[u]) {
        swap(u, v);
    }
    int delta = d[u] - d[v];

    for (int k = (int) (log2(n) + 1); k >= 0; k--) {
        if (delta >= dummy_pow(2, k)) {
            u = jmp[u][k];
            delta -= dummy_pow(2, k);
        }
    }

    if (u == v) {
        return v;
    }

    for (int k = (int) (log2(n) + 1); k >= 0; k--) {
        int new_u = jmp[u][k];
        int new_v = jmp[v][k];
        if (new_u != new_v) {
            u = new_u;
            v = new_v;
        }
    }
    return jmp[u][0];
}

int main() {
    int n = 0;
    int v = 0;
    int u = 0;

    cin >> n;

    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> v;
        p[i] = v;
        child[v].push_back(i);
    }

    precalc(n);



//    print_parents(n);
//    print_childs(n);
//    print_depths(n);
//    print_jmp(n);

    int m = 0;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << lca(u, v, n) << endl;
    }
    return 0;
}
//5
//1
//1
//2
//2
//3
//4 5
//4 2
//3 5

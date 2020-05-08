#include <fstream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<int> child[200005];
int p[200005][2];
int d[200005];
int jmp[200005][19];
int arr_min[200005][19];

const int MAX_EDGE = 10000000;

void dfs(int root) {
    for (auto v : child[root]) {
        d[v] = d[root] + 1;
        dfs(v);
    }
}

void precalc(int n) {
    dfs(1);
    for (int i = 1; i <= n; i++) {
        jmp[i][0] = p[i][0];
        arr_min[i][0] = p[i][1];
    }
    for (int k = 1; k <= (int)log2(n)+1; k++) {
        for (int i = 1; i <= n; i++) {
            int tmp_u = jmp[i][k - 1];
            jmp[i][k] = jmp[tmp_u][k - 1];
            arr_min[i][k] = min(arr_min[i][k - 1], arr_min[tmp_u][k - 1]);
        }
    }
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

    int res = MAX_EDGE;
    for (int k = (int) (log2(n) + 1); k >= 0; k--) {
        if (delta >= dummy_pow(2, k)) {
            res = min(res, arr_min[u][k]);
            u = jmp[u][k];
            delta -= dummy_pow(2, k);
        }
    }

    if (u == v) {
        return res;
    }

    for (int k = (int) (log2(n) + 1); k >= 0; k--) {
        int new_u = jmp[u][k];
        int new_v = jmp[v][k];
        if (new_u != new_v) {
            res = min(res, arr_min[u][k]);
            u = new_u;
            res = min(res, arr_min[v][k]);
            v = new_v;
        }
    }
    return min(arr_min[v][0], min(res, arr_min[u][0]));
}

int main() {
    int n = 0;
    int v = 0;
    int w = 0;
    int u = 0;

    ifstream inp("minonpath.in");
    ofstream out("minonpath.out");

    inp >> n;

    p[1][0] = 1;
    p[1][1] = MAX_EDGE;
    for (int i = 2; i <= n; i++) {
        inp >> v >> w;
        p[i][0] = v;
        p[i][1] = w;
        child[v].push_back(i);
    }

    precalc(n);

    int m = 0;

    inp >> m;
    for (int i = 0; i < m; i++) {
        inp >> u >> v;
        out << lca(u, v, n) << endl;
    }
    return 0;
}

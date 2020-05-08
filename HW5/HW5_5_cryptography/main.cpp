#include <string>
#include <fstream>

using namespace std;

struct matr {
    int el11 = 1;
    int el12 = 0;
    int el21 = 0;
    int el22 = 1;
};

matr tree[500010];

void print(matr mt, ofstream& file) {
    file << mt.el11 << " " << mt.el12 << '\n';
    file << mt.el21 << " " << mt.el22 << '\n';
    file << '\n';
}

matr dot(matr a, matr b, int mod) {
    matr res;
    res.el11 = (a.el11 * b.el11 + a.el12 * b.el21) % mod;
    res.el12 = (a.el11 * b.el12 + a.el12 * b.el22) % mod;
    res.el21 = (a.el21 * b.el11 + a.el22 * b.el21) % mod;
    res.el22 = (a.el21 * b.el12 + a.el22 * b.el22) % mod;

    return res;
}

matr rsq(int idx, int l, int r, int a, int b, int mod) {
    if (l > b || r < a) {
        matr mt;
        return mt;
    }
    if (l >= a && r <= b) {
        return tree[idx];
    }
    int m = (l + r) / 2;
    return dot(rsq(2 * idx + 1, l, m, a , b, mod),
           rsq(2 * idx + 2, m + 1, r, a, b, mod), mod);
}

int main() {
    ifstream inp("crypto.in");
    ofstream out("crypto.out");
    int mod = 0;
    int n = 0;
    int m = 0;

    inp >> mod >> n >> m;

    int bottom_lvl_amm = 1;
    for (; bottom_lvl_amm < n; bottom_lvl_amm *= 2);
    int tree_n = bottom_lvl_amm + (bottom_lvl_amm - 1);

    // fill bottom level
    for (int i = 0; i < n; i++) {
        matr mt;
        inp >> mt.el11 >> mt.el12 >> mt.el21 >> mt.el22;
        tree[bottom_lvl_amm - 1 + i] = mt;
    }

    // fill all levels
    for (int i = tree_n - 1; i > 0; i--) {
        tree[(i - 1) / 2] = dot(tree[i], tree[(i - 1) / 2], mod);
    }

    int l = 0;
    int r = 0;
    for (int i = 0; i < m; i++) {
        inp >> l >> r;
        print(rsq(0, 1, bottom_lvl_amm, l, r, mod), out);
    }

    return 0;
}

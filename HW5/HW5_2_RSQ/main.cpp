#include <iostream>
#include <string>

using namespace std;

int64_t tree[1048600][2];

void update(int64_t where, int64_t v, int64_t n) {
    int start = n / 2;
    int diff = tree[start + where - 1][0] - v;
    int cur = start + where - 1;
    tree[cur][0] -= diff;
    while (cur != 0) {
        cur = (cur - 1) / 2;
        tree[cur][0] -= diff;
    }
}

int64_t rsq(int64_t idx, int64_t l, int64_t r, int64_t a, int64_t b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return tree[idx][0];
    }
    int64_t m = (l + r) / 2;
    return rsq(2 * idx + 1, l, m, a , b) +
           rsq(2 * idx + 2, m + 1, r, a, b);
}

int main() {
    int64_t n = 0;
    cin >> n;

    int64_t bottom_lvl_amm = 1;
    for (; bottom_lvl_amm < n; bottom_lvl_amm *= 2);
    int64_t tree_n = bottom_lvl_amm + (bottom_lvl_amm - 1);

    // fill bottom level
    for (int i = 0; i < n; i++) {
        cin >> tree[bottom_lvl_amm - 1 + i][0];
    }

    // fill all levels
    for (int i = tree_n - 1; i > 0; i--) {
        tree[(i - 1) / 2][0] += tree[i][0];
    }

    string cmd = "";
    int64_t inp1 = 0;
    int64_t inp2 = 0;
    while (std::cin >> cmd)  {
        cin >> inp1 >> inp2;
        if (cmd == "sum") {
            cout << rsq(0, 1, bottom_lvl_amm, inp1, inp2) << endl;
        } else {
            update(inp1, inp2, tree_n);
        }
    }

    return 0;
}

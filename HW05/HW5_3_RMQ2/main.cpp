#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int64_t tree[1048600][3]; //[0] value, [1] add, [2] flag if this value is set
const int64_t MAX = LLONG_MAX;

int64_t get(int64_t v) {
    return tree[v][0] + tree[v][1];
}

void push(int64_t v, int64_t l, int64_t r) {
    if (l == r) {
        if (tree[v][0] != MAX){
            tree[v][0] += tree[v][1];
        }
    } else {
        if (tree[v][2]) {
            tree[2 * v + 1][0] = tree[v][0];
            tree[2 * v + 2][0] = tree[v][0];
            tree[2 * v + 1][2] = 1;
            tree[2 * v + 2][2] = 1;
            tree[2 * v + 1][1] = tree[v][1];
            tree[2 * v + 2][1] = tree[v][1];
        } else {
            tree[2 * v + 1][1] += tree[v][1];
            tree[2 * v + 2][1] += tree[v][1];
        }

        int64_t m = (l + r) / 2;
        tree[v][0] = min(get(2 * v + 1), get(2 * v + 2));
    }
    tree[v][1] = 0;
    tree[v][2] = 0;
}

void add(int64_t v, int64_t l, int64_t r, int64_t a, int64_t b, int64_t x) {
    push(v, l, r);
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        tree[v][1] += x;
        return;
    }
    int64_t m = (l + r) / 2;
    add(2 * v + 1, l, m, a, b, x);
    add(2 * v + 2, m + 1, r, a, b, x);
    tree[v][0] = min(get(2 * v + 1), get(2 * v + 2));
}

int64_t rmq(int64_t v, int64_t l, int64_t r, int64_t a, int64_t b) {
    push(v, l, r);
    if (l > b || r < a) {
        return MAX;
    }
    if (l >= a && r <= b) {
        return get(v);
    }
    int64_t m = (l + r) / 2;
    return min(rmq(2 * v + 1, l, m, a , b),
           rmq(2 * v + 2, m + 1, r, a, b));
}

void set(int64_t v, int64_t l, int64_t r, int64_t a, int64_t b, int64_t x) {
    push(v, l, r);
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        tree[v][0] = x;
        tree[v][2] = 1;
        tree[v][1] = 0;
        return;
    }
    int m = (l + r) / 2;
    set(2 * v + 1, l, m, a, b, x);
    set(2 * v + 2, m + 1, r, a, b, x);
    tree[v][0] = min(get(2 * v + 1), get(2 * v + 2));
}

int main() {
    int64_t n = 0;
    cin >> n;

    int64_t bottom_lvl_amm = 1;
    for (; bottom_lvl_amm < n; bottom_lvl_amm *= 2);
    int64_t tree_n = bottom_lvl_amm + (bottom_lvl_amm - 1);

    for (int i = 0; i < tree_n; i++) {
        tree[i][0] = MAX;
    }

    // fill bottom level
    for (int i = 0; i < n; i++) {
        cin >> tree[bottom_lvl_amm - 1 + i][0];
    }

    // fill all levels
    for (int i = tree_n - 1; i > 0; i--) {
        tree[(i - 1) / 2][0] = min(tree[i][0], tree[(i - 1) / 2][0]);
    }

    string cmd = "";
    int64_t inp1 = 0;
    int64_t inp2 = 0;
    int64_t inp3 = 0;
    while (std::cin >> cmd)  {
        if (cmd == "asd") {
            break;
        }
        cin >> inp1 >> inp2;
        if (cmd == "min") {
            cout << rmq(0, 1, bottom_lvl_amm, inp1, inp2) << endl;
        } else if (cmd == "add") {
            cin >> inp3;
            add(0, 1, bottom_lvl_amm, inp1, inp2, inp3);
        } else {
            cin >> inp3;
            set(0, 1, bottom_lvl_amm, inp1, inp2, inp3);
        }
    }


    return 0;
}

#include <fstream>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

const int MIN_INF = INT32_MIN;
const int MAX_INF = INT32_MAX;

struct request {
    int l = 0;
    int r = 0;
    int v = 0;
};

int arr[100010];
request reqs[100010];
int tree[270000];

int get(int v) {
    return tree[v];
}

int rmq(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return MAX_INF;
    }
    if (l >= a && r <= b) {
        return get(v);
    }
    int m = (l + r) / 2;
    return min(rmq(2 * v + 1, l, m, a , b),
               rmq(2 * v + 2, m + 1, r, a, b));
}

int main() {
    ifstream inp("rmq.in");
    ofstream out("rmq.out");

    int n = 0;
    int m = 0;
    inp >> n >> m;

    for (int i = 0; i < n; i++) {
        arr[i] = MIN_INF;
    }

    for (int i = 0; i < m; i++) {
        request req;
        inp >> req.l >> req.r >> req.v;
        req.l -= 1;
        reqs[i] = req;
    }

    sort(reqs, reqs+m,
            [](const request & a, const request & b) -> bool {return a.l < b.l;});

    set <pair<int, int>, greater<> > ms;
    ms.insert(make_pair(MIN_INF, n+2));
    int j = 0;
    for (int i = 0; i < n; i++) {
        while ((*ms.begin()).second <= i) {
            ms.erase(ms.begin());
        }

        while (j < m && reqs[j].l == i) {
            int end = reqs[j].r;
            int v = reqs[j].v;
            ms.insert(make_pair(v, end));
            j++;
        }

        arr[i] = (*ms.begin()).first;
    }

    // check consistency
    int bottom_lvl_amm = 1;
    for (; bottom_lvl_amm < n; bottom_lvl_amm *= 2);
    int tree_n = bottom_lvl_amm + (bottom_lvl_amm - 1);

    for (int i = 0; i < tree_n; i++) {
        tree[i] = MAX_INF;
    }
    for (int i = 0; i < n; i++) {
        tree[bottom_lvl_amm - 1 + i] = arr[i];
    }
    for (int i = tree_n - 1; i > 0; i--) {
        tree[(i - 1) / 2] = min(tree[i], tree[(i - 1) / 2]);
    }

    int flag = 0;
    for (int i = 0; i < m; i++) {
        if (rmq(0, 1, bottom_lvl_amm, reqs[i].l+1, reqs[i].r) != reqs[i].v) {
            flag = 1;
            break;
        }
    }

    // print result
    if (flag == 1) {
        out << "inconsistent" << endl;
    } else {
        out << "consistent" << endl;
        for (int i = 0; i < n; i++) {
            out << arr[i] << " ";
        }
    }
    return 0;
}

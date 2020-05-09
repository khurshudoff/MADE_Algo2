#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a[100005][17];
int k_arr[100005];

int _min(int l, int r) {
    if (l > r) {
        int tmp = l;
        l = r;
        r = tmp;
    }
    int cur = a[l - 1][0];
    for (int i = l; i < r; i++) {
        cur = min(cur, a[i][0]);
    }
    return cur;
}

int st_min(int l, int r) {
    l -= 1;
    r -= 1;
    if (l > r) {
        int tmp = l;
        l = r;
        r = tmp;
    }
    int k = k_arr[r - l];
    return min(a[l][k], a[r - (1 << k) + 1][k]);
}

int main() {
    int n = 0;
    int m = 0;
    int a1 = 0;
    int64_t cur_u = 0;
    int64_t cur_v = 0;
    int64_t cur_r = 0;

    cin >> n >> m >> a1;
    cin >> cur_u >> cur_v;

    int cur_k = 0;
    for (int i = 2; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            cur_k += 1;
        }
        k_arr[i] = cur_k;
    }

    a[0][0] = a1;
    for (int i = 1; i < n; i++) {
        a[i][0] = (23 * a[i - 1][0] + 21563) % 16714589;
    }

    int K = (int) log2(n);

    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << (k - 1)) >= n) {
                break;
            }
            a[i][k] = min(a[i][k - 1], a[i + (1 << (k - 1))][k - 1]);
        }
    }

    cur_r = st_min(cur_u, cur_v);
    for (int i = 1; i < m; i++) {
        cur_u = (17 * cur_u + 751 + cur_r + 2 * i) % n + 1;
        cur_v = (13 * cur_v + 593 + cur_r + 5 * i) % n + 1;
        cur_r = st_min(cur_u, cur_v);
    }

    cout << cur_u << " " << cur_v << " " << cur_r << endl;

    return 0;
}


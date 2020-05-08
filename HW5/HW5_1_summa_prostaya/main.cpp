#include <iostream>
#include <algorithm>

using namespace std;

int64_t a[10000005];
int64_t b[20000005];

int64_t mod(int64_t v, int mod) {
    return v & ((1 << mod) - 1);
}

int main() {
    int n = 0;
    int x = 0;
    int y = 0;
    int m = 0;
    int z = 0;
    int t = 0;
    int64_t  s = 0;

    cin >> n >> x >> y >> a[0];
    cin >> m >> z >> t >> b[0];

    for (int i = 1; i < n; i++) {
        a[i] = mod(a[i - 1] * x + y, 16);
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    int M = 2 * m;
    for (int j = 1; j < M; j++) {
        b[j] = mod(z * b[j - 1] + t, 30);
    }

    for (int i = 0; i < m; i++) {
        int l = min(b[2 * i] % n, b[2 * i + 1] % n);
        int r = max(b[2 * i] % n, b[2 * i + 1] % n);

        int64_t l_v = 0;
        if (l > 0) {
            l_v = a[l - 1];
        }
        int64_t r_v = a[r];

        s += r_v - l_v;
    }

    cout << s << endl;

    return 0;
}


#include <iostream>

using namespace std;

int T[129][129][129];

int F(int v) {
    return v & (v + 1);
}

int get(int x, int y, int z) {
    int res = 0;
    if (x < 0 || y < 0 || z < 0) {
        return 0;
    }
    for (int i = x; i >= 0; i = F(i) - 1) {
        for (int j = y; j >= 0; j = F(j) - 1) {
            for (int k = z; k >= 0; k = F(k) - 1) {
                res += T[i][j][k];
            }
        }
    }
    return res;
}
int get(int x1, int y1, int z1, int x2, int y2, int z2) {
    return get(x2, y2, z2)- get(x1 - 1, y2, z2)  - get(x2, y1 - 1, z2) + get(x1 - 1, y1 - 1, z2)
            - get(x2, y2, z1 - 1) + get(x1 - 1, y2, z1 - 1) + get(x2, y1 - 1, z1 - 1)  - get(x1 - 1, y1 - 1, z1 - 1);
}
void add(int x, int y, int z, int v, int n) {
    for (int i = x; i < n; i = i | (i + 1)) {
        for (int j = y; j < n; j = j | (j + 1)) {
            for (int k = z; k < n; k = k | (k + 1)) {
                T[i][j][k] += v;
            }
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    while (true) {
        int type = 0;
        cin >> type;
        if (type == 3) {
            break;
        }
        if (type == 1) {
            int x = 0, y = 0, z = 0, k = 0;
            cin >> x >> y >> z >> k;
            add(x, y, z, k, n);
        } else {
            int x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << get(x1, y1, z1, x2, y2, z2) << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment{
    int yl, yr, x, type;
    bool operator<(const Segment& segment) const {
        if (x == segment.x) {
            return type > segment.type;
        }
        return x < segment.x;
    }
};

Segment segm[100003];

struct Rect {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
};

int64_t tree[1048600][2];  //[0] value, [1] add
vector<Rect> rect_arr;
const int64_t MIN = LLONG_MIN;

int64_t get(int64_t v) {
    return tree[v][0] + tree[v][1];
}

void push(int64_t v, int64_t l, int64_t r) {
    if (l == r) {
        if (tree[v][0] != MIN){
            tree[v][0] += tree[v][1];
        }
    } else {
        tree[2 * v + 1][1] += tree[v][1];
        tree[2 * v + 2][1] += tree[v][1];
        int64_t m = (l + r) / 2;
        tree[v][0] = max(get(2 * v + 1), get(2 * v + 2));
    }
    tree[v][1] = 0;
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
    tree[v][0] = max(get(2 * v + 1), get(2 * v + 2));
}

int64_t rmq(int64_t v, int64_t l, int64_t r, int64_t a, int64_t b) {
    push(v, l, r);
    if (l > b || r < a) {
        return MIN;
    }
    if (l >= a && r <= b) {
        return get(v);
    }
    int64_t m = (l + r) / 2;
    return max(rmq(2 * v + 1, l, m, a , b),
               rmq(2 * v + 2, m + 1, r, a, b));
}

int main() {
    int64_t n = 400006;
    int64_t bottom_lvl_amm = 1;
    for (; bottom_lvl_amm < n; bottom_lvl_amm *= 2);
    int64_t tree_n = bottom_lvl_amm + (bottom_lvl_amm - 1);
    for (int i = 0; i < tree_n; i++) {
        tree[i][0] = 0;
    }

    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        Rect tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        tmp.x1 += n / 2;
        tmp.x2 += n / 2;
        tmp.y1 += n / 2;
        tmp.y2 += n / 2;
        rect_arr.push_back(tmp);

        Segment s1;
        s1.x = tmp.x1;
        s1.yl = tmp.y1;
        s1.yr = tmp.y2;
        s1.type = 1;
        segm[2 * i] = s1;

        Segment s2;
        s2.x = tmp.x2;
        s2.yl = tmp.y1;
        s2.yr = tmp.y2;
        s2.type = -1;
        segm[2 * i + 1] = s2;
    }

    sort(segm, segm + 2 * m);


    int max_x = 0;
    int max_v = 0;

    int segm_idx = 0;
    for (int x = 0; x < n; x++) {
        while (segm[segm_idx].x == x and segm[segm_idx].type == 1) {
            auto s = segm[segm_idx++];
            add(0, 1, bottom_lvl_amm, s.yl, s.yr, 1);
        }
        auto v = rmq(0, 1, bottom_lvl_amm, 0, n);
        if (v > max_v) {
            max_v = v;
            max_x = x;
        }
        while (segm[segm_idx].x == x and segm[segm_idx].type == -1) {
            auto s = segm[segm_idx++];
            add(0, 1, bottom_lvl_amm, s.yl, s.yr, -1);
        }
    }

    // мы вычислили x координату, теперь вычислим y.
    vector <pair <int, int> > arr_y;
    for (auto r: rect_arr) {
        if (r.x1 <= max_x and max_x <= r.x2) {
            arr_y.push_back(make_pair(r.y1, -1));
            arr_y.push_back(make_pair(r.y2, 1));
        }
    }

    sort(arr_y.begin(), arr_y.end());

    max_v = 0;
    int cur_v = 0;
    int max_y = 0;
    for (auto el : arr_y) {
        cur_v -= el.second;
        if (cur_v > max_v) {
            max_y = el.first;
            max_v = cur_v;
        }
    }

    cout << max_v << endl;
    cout << max_x - n / 2 << " " << max_y - n / 2 << endl;

    return 0;
}

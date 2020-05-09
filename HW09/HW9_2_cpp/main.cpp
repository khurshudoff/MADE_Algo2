#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const int INF = INT_MAX;

struct Edge{
    int fr;
    int to;
    int fl;
    int cp;
    int idx;
    int w;
    pair<int, int> ed = make_pair(-1, -1);

    Edge (int _fr, int _to, int _fl, int _cp, int _w, int _idx) :
            fr(_fr), to(_to), fl(_fl), cp(_cp), w(_w), idx(_idx) {}
};

int inp[305][305];
int arr[92000][4];
int edg_flow[92000];
vector<Edge> g[605];

vector<int> bellFord(int n_vertex) {
    Edge *p[n_vertex];
    for (int i = 0; i < n_vertex; i++) p[i] = NULL;

    vector<int> d(n_vertex);
    for (int i = 0; i < n_vertex; i++) d[i] = INF;

    int is_in_q[n_vertex];
    for (int i = 0; i < n_vertex; i++) is_in_q[i] = 0;

    d[0] = 0;
    queue<int> q;
    q.push(0);

    while (q.size() > 0) {
        int cur = q.front();
        q.pop();
        is_in_q[cur] = 0;

        for (int i = 0; i < g[cur].size(); i++) {
            auto e = g[cur][i];
            if (e.cp != e.fl) {
                if (d[e.to] > d[e.fr] + e.w) {
                    d[e.to] = d[e.fr] + e.w;
                    p[e.to] = &g[cur][i];
                    if (is_in_q[e.to] == 0) {
                        q.push(e.to);
                        is_in_q[e.to] = 1;
                    }
                }
            }
        }
    }
    return d;
}

int dijkstra (int n_vertex, vector<int>* pot) {
    bool used[n_vertex];
    for (int i = 0; i < n_vertex; i++) used[i] = false;

    Edge *p[n_vertex];
    for (int i = 0; i < n_vertex; i++) p[i] = nullptr;

    int d[n_vertex];
    for (int i = 0; i < n_vertex; i++) d[i] = INF;
    d[0] = 0;


    while (true) {
        int min_v = INF;
        int cur = -1;
        for (int i = 0; i < n_vertex; i++) {
            if (!used[i] && min_v > d[i]) {
                min_v = d[i];
                cur = i;
            }
        }
        if (min_v == INF) break;

        used[cur] = true;

        for (int i = 0; i < g[cur].size(); i++) {
            auto e = g[cur][i];
            if (e.cp != e.fl) {
                if (d[e.to] > d[e.fr] + e.w + (*pot)[e.fr] - (*pot)[e.to]) {
                    d[e.to] = d[e.fr] + e.w + (*pot)[e.fr] - (*pot)[e.to];
                    p[e.to] = &g[cur][i];
                }
            }
        }
    }

    if (!p[n_vertex - 1]) {
        return -INF;
    }

    Edge *cur = p[n_vertex - 1];
    vector<Edge *> way;
    way.emplace_back(p[n_vertex - 1]);
    while ((*cur).fr) {
        way.emplace_back(p[(*cur).fr]);
        cur = p[(*cur).fr];
    }

    int c_min = INF;
    for (int i = 0; i < way.size(); i++) c_min = min(c_min, (*way[i]).cp - (*way[i]).fl);

    for (int i = 0; i < way.size(); i++) {
        (*way[i]).fl += c_min;
        g[(*way[i]).ed.first][(*way[i]).ed.second].fl -= c_min;
        if ((*way[i]).idx > 0) {
            edg_flow[abs((*way[i]).idx)] += c_min;
        } else {
            edg_flow[abs((*way[i]).idx)] -= c_min;
        }
    }

    int res =  c_min * (d[n_vertex - 1] + (*pot)[n_vertex - 1]);

    for (int i = 0; i < n_vertex; i++) {
        (*pot)[i] += d[i];
    }

    return res;
}

int main() {
    ifstream fin("inp.txt");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> inp[i][j];
        }
    }

    int n_edges = 0;
    for (int i = 0; i < N; i++) {
        arr[n_edges][0] = 0; // from
        arr[n_edges][1] = i + 1; // to
        arr[n_edges][2] = 1; // capacity
        arr[n_edges][3] = 0; // weight
        n_edges++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[n_edges][0] = i + 1; // from
            arr[n_edges][1] = N + j + 1; // to
            arr[n_edges][2] = 1; // capacity
            arr[n_edges][3] = inp[i][j]; // weight
            n_edges++;
        }
    }

    for (int i = 0; i < N; i++) {
        arr[n_edges][0] = N + i + 1; // from
        arr[n_edges][1] = 2 * N + 1; // to
        arr[n_edges][2] = 1; // capacity
        arr[n_edges][3] = 0; // weight
        n_edges++;
    }

    int n_vertex = 2 * N + 2;

    for (int i = 0; i < n_edges; i++) {
        int fr = arr[i][0];
        int to = arr[i][1];
        int cp = arr[i][2];
        int w = arr[i][3];
        g[fr].emplace_back(Edge(fr, to, 0, cp, w, i));
        g[to].emplace_back(Edge(to, fr, 0, 0, -w, -i));
        g[fr][g[fr].size() - 1].ed = make_pair(to, g[to].size() - 1);
        g[to][g[to].size() - 1].ed = make_pair(fr, g[fr].size() - 1);
    }

    int res = 0;

    auto p = bellFord(n_vertex);

    while (true) {
        int bf = dijkstra(n_vertex, &p);
        if (bf == -INF) {
            break;
        }
        res += bf;
    }

    cout << res << endl;

    for (int i = 0; i < n_edges; i++) {
        if ((i < N) || (i >= n_edges - N)) {
            continue;
        }
        if (edg_flow[i] == 1) {
            int el = i - N;
            cout << (el / N) + 1 << " " << (el % N) + 1 << endl;
        }
    }

    return 0;
}
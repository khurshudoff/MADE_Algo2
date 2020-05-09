#include <fstream>
#include <iostream>

using namespace std;

int arr[10002];
int steps[10002];
int path[10002];

int main() {
    ifstream inp("input.txt");
    ofstream out("output.txt");
    int N = 0;
    int K = 0;

    inp >> N >> K;
    for (int i = 1; i < N-1; i++) {
        inp >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        int _max = arr[i-1];
        int cur_step = i-1;
        for (int j = max(0, i-K); j < i; j++) {
            if (arr[j] > _max) {
                _max = arr[j];
                cur_step = j;
            }
        }
        steps[i] = cur_step;
        arr[i] += _max;
    }

    int path_idx = 0;
    int cur = N-1;
    while (cur != 0) {
        path[path_idx++] = cur;
        cur = steps[cur];
    }
    path[path_idx] = cur;

    out << arr[N-1] << endl;
    out << path_idx << endl;
    for (;path_idx >0; path_idx--){
        out << path[path_idx]+1 << " ";
    }
    out << path[path_idx]+1 << endl;

    inp.close();
    out.close();
    return 0;
}
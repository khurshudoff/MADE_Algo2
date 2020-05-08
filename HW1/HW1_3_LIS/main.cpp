#include <iostream>

using namespace std;

int arr[2002];
int d[2002][2];
int res[2002];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        d[i][0] = 1;
        d[i][1] = -1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (d[i][0] < d[j][0]+1) {
                    d[i][0] = d[j][0] + 1;
                    d[i][1] = j;
                }
            }
        }
    }
    int max_len  = d[0][0];
    int max_idx = 0;
    for (int i = 0; i < n; i++) {
        if (max_len < d[i][0]) {
            max_len = d[i][0];
            max_idx = i;
        }
    }


    int i = -1;
    while (max_idx != -1) {
        res[++i] = arr[max_idx];
        max_idx = d[max_idx][1];
    }

    cout << i+1 << endl;
    for (; i >=0; i--) cout << res[i] << " ";

    cout << endl;

    return 0;
}
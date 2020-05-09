#include <iostream>

using namespace std;

int arr[1002][1002];
bool path[2004];

int main() {
    int N = 0;
    int M = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = 1; i < N; i++)
        arr[i][0] += arr[i-1][0];
    for (int j = 1; j < M; j++)
        arr[0][j] += arr[0][j-1];

    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            arr[i][j] += max(arr[i][j-1], arr[i-1][j]);

    cout << arr[N-1][M-1] << endl;

    int I = N-1;
    int J = M-1;
    int i = -1;
    while ((I != 0) || (J != 0)) {
        i += 1;
        if (I == 0) {
            J -= 1;
            path[i] = 1;
            continue;
        }

        if (J == 0) {
            I -= 1;
            continue;
        }

        if (arr[I-1][J] > arr[I][J-1]) {
            I -= 1;
        } else {
            J -= 1;
            path[i] = 1;
        }
    }

    for (; i>=0; i--) {
        if (path[i]) cout << "R";
        else cout << "D";
    }
    cout << endl;

    return 0;
}
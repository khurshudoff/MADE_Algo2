#include <iostream>
#include <string>

using namespace std;

int arr[1002][1002];

int main() {

    string s1 = "";
    string s2 = "";

    cin >> s1;
    cin >> s2;

    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i <= n; i++)
        arr[i][0] = i;
    for (int j = 0; j <= m; j++)
        arr[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1];
            else
                arr[i][j] = min(min(arr[i][j-1], arr[i-1][j]), arr[i-1][j-1]) + 1;
        }
    }

    cout << arr[n][m] << endl;

    return 0;
}
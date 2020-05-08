#include <iostream>
#include <vector>

const int N = 1e6 + 2;

int lp[N];
std::vector<int> primes;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (!lp[i]) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (p > lp[i] || i * p >= N) {
                break;
            }
            lp[i * p] = p;
        }
    }

    int n = 0;
    int v = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> v;
        while (v > 1) {
            std::cout << lp[v] << " ";
            v /= lp[v];
        }
        std::cout << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int cambio_min_monedas(const std::vector<int>& v, int N, int M) {
    const int INF = std::numeric_limits<int>::max() / 4;
    std::vector<int> dp(M+1, INF);
    dp[0] = 0;
    for (int j = 0; j < N; ++j) {
        int coin = v[j];
        for (int amount = coin; amount <= M; ++amount) {
            if (dp[amount - coin] + 1 < dp[amount])
                dp[amount] = dp[amount - coin] + 1;
        }
    }
    return (dp[M] >= INF) ? -1 : dp[M];
}

std::vector<int> cambio_vector(const std::vector<int>& v, int N, int M) {
    const int INF = std::numeric_limits<int>::max() / 4;
    std::vector<int> dp(M+1, INF);
    std::vector<int> lastCoin(M+1, -1);
    dp[0] = 0;
    for (int j = 0; j < N; ++j) {
        int coin = v[j];
        for (int amount = coin; amount <= M; ++amount) {
            if (dp[amount - coin] + 1 < dp[amount]) {
                dp[amount] = dp[amount - coin] + 1;
                lastCoin[amount] = j;
            }
        }
    }
    if (dp[M] >= INF) return {};
    std::vector<int> x(N, 0);
    int cur = M;
    while (cur > 0) {
        int c = lastCoin[cur];
        if (c == -1) break;
        x[c]++;
        cur -= v[c];
    }
    return x;
}

int main() {
    std::vector<int> v = {1,4,6};
    int N = (int)v.size();
    int M = 8;

    int minc = cambio_min_monedas(v, N, M);
    std::cout << "Cambio minimo para M=" << M << " con monedas {1,4,6}: " << minc << std::endl;

    auto sol = cambio_vector(v, N, M);
    if (sol.empty()) {
        std::cout << "No hay solución para M=" << M << std::endl;
    } else {
        std::cout << "Vector solución (cantidad de cada moneda): ";
        for (int i = 0; i < N; ++i) std::cout << sol[i] << (i+1==N? "\n" : " ");
    }

    return 0;
}


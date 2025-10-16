#include <iostream>
#include <vector>
#include <algorithm>

int mochila_max_beneficio(int N, const std::vector<int>& p, const std::vector<int>& b, int M, std::vector<int>& sol) {
    std::vector<std::vector<int>> g(N+1, std::vector<int>(M+1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int C = 0; C <= M; ++C) {
            if (p[i-1] > C) {
                g[i][C] = g[i-1][C];
            } else {
                g[i][C] = std::max(g[i-1][C], g[i-1][C - p[i-1]] + b[i-1]);
            }
        }
    }
    sol.assign(N, 0);
    int C = M;
    for (int i = N; i >= 1; --i) {
        if (g[i][C] != g[i-1][C]) {
            sol[i-1] = 1;
            C -= p[i-1];
        } else {
            sol[i-1] = 0;
        }
    }
    return g[N][M];
}

int main() {
    int M = 5;
    std::vector<int> p = {1,3,2,4};
    std::vector<int> b = {10,20,15,20};
    int N = (int)p.size();
    std::vector<int> sol;

    int maxb = mochila_max_beneficio(N, p, b, M, sol);
    std::cout << "Beneficio maximo: " << maxb << std::endl;
    std::cout << "Vector solucion (0/1): ";
    for (int i = 0; i < N; ++i) std::cout << sol[i] << (i+1==N ? "\n" : " ");
    return 0;
}


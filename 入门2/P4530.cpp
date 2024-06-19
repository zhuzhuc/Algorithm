#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 64;
const int M = 20005;
int n, m;

inline int add(int a, int b) {
    return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}

struct Vec {
    int v[N];
    Vec() { memset(v, 0, sizeof(v)); }
    int& operator[](int idx) { return v[idx]; }
};

struct Mat {
    int m[N][N];
    Mat() { memset(m, 0, sizeof(m)); }
    int* operator[](int idx) { return m[idx]; }
};

Mat operator*(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = add(C[i][j], 1LL * A[i][k] * B[k][j] % MOD);
    return C;
}

Vec operator*(const Vec& A, const Mat& B) {
    Vec C;
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            C[i] = add(C[i], 1LL * A.v[k] * B.m[k][i] % MOD);
    return C;
}

Mat matPow(Mat base, int exp) {
    Mat res;
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;
    while (exp) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int A[N][N];
int f[M][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    Mat G;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    int B = sqrt(m) + 1;
    int K = log2(n);
    vector<Vec> Ma(B + 1), Mb(B + 1);

    for (int S = 0; S < n; ++S) {
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                G[j][i] = A[j][i];
                if ((j | S) == j)
                    sum = add(sum, A[j][i]);
            }
            Ma[0][i] = sum;
            Mb[0][i] = ((i | S) == i);
            for (int j = 0; j < n; ++j)
                if ((j | S) == j)
                    G[j][i] = add(G[j][i], sum);
        }
        for (int i = 1; i <= B; ++i)
            Ma[i] = Ma[i - 1] * G;
        G = matPow(G, B);
        for (int i = 1; i <= B; ++i)
            Mb[i] = G * Mb[i - 1];
        for (int i = 0; i < m; ++i)
            f[i + 1][S] = Ma[i % B] * Mb[i / B];
    }

    int ans = 0;
    for (int E = 1; E <= m; ++E) {
        for (int i = 0; i < K; ++i)
            for (int j = 0; j < n; ++j)
                if ((j >> i) % 2 == 0)
                    f[E][j] = add(f[E][j], MOD - f[E][j ^ (1 << i)]);
        for (int i = 0; i < n; ++i)
            ans ^= f[E][i];
    }

    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) return false;}
    return true;
}
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1; 
    }
    return n * factorial(n - 1);
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = i * n + j + 1;
        }
    }
    for (int op = 0; op < m; ++op) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        x -= 1; 
        y -= 1;

      
        int x1 = x - r, x2 = x + r;
        int y1 = y - r, y2 = y + r;

    
        vector<vector<int>> rotated(2 * r + 1, vector<int>(2 * r + 1));

   
        for (int i = 0; i <= 2 * r; ++i) {
            for (int j = 0; j <= 2 * r; ++j) {
                if (z == 0) {
                    rotated[j][2 * r - i] = matrix[x1 + i][y1 + j];
                } else { 
                    rotated[2 * r - j][i] = matrix[x1 + i][y1 + j];
                }
            }
        }

        for (int i = 0; i <= 2 * r; ++i) {
            for (int j = 0; j <= 2 * r; ++j) {
                matrix[x1 + i][y1 + j] = rotated[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
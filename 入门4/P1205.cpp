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

void solve() {

}


// 旋转90度
vector<vector<char>> rotate90(const vector<vector<char>>& matrix) {
    int n = matrix.size();
    vector<vector<char>> result(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[j][n - 1 - i] = matrix[i][j];
        }
    }
    return result;
}

// 旋转180度
vector<vector<char>> rotate180(const vector<vector<char>>& matrix) {
    return rotate90(rotate90(matrix));
}

// 旋转270度
vector<vector<char>> rotate270(const vector<vector<char>>& matrix) {
    return rotate90(rotate180(matrix));
}

// 水平反射
vector<vector<char>> reflect(const vector<vector<char>>& matrix) {
    int n = matrix.size();
    vector<vector<char>> result(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][n - 1 - j] = matrix[i][j];
        }
    }
    return result;
}

// 检查两个矩阵是否相等
bool isEqual(const vector<vector<char>>& a, const vector<vector<char>>& b) {
    return a == b;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> original(n, vector<char>(n));
    vector<vector<char>> target(n, vector<char>(n));

    // 读取原始图案
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> original[i][j];
        }
    }

    // 读取目标图案
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> target[i][j];
        }
    }

    // 检查所有转换方法
    if (isEqual(rotate90(original), target)) {
        cout << "1" << endl;
    } else if (isEqual(rotate180(original), target)) {
        cout << "2" << endl;
    } else if (isEqual(rotate270(original), target)) {
        cout << "3" << endl;
    } else if (isEqual(reflect(original), target)) {
        cout << "4" << endl;
    } else if (isEqual(rotate90(reflect(original)), target)) {
        cout << "5" << endl;
    } else if (isEqual(rotate180(reflect(original)), target)) {
        cout << "5" << endl;
    } else if (isEqual(rotate270(reflect(original)), target)) {
        cout << "5" << endl;
    } else if (isEqual(original, target)) {
        cout << "6" << endl;
    } else {
        cout << "7" << endl;
    }

    return 0;
}

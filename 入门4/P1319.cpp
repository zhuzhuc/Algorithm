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
    vector<int> press;

    int value;
    while(cin >> value){
        press.push_back(value);
    }

    int n = press[0];
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int index = 1;
    int current_value = 0;
    int row = 0, col = 0;
    while(index < press.size()) {
        int count = press[index];
        for (int i = 0; i < count; ++i) {
            matrix[row][col] = current_value;
            col++;
            if (col == n) {
                col = 0;
                row++;
            }
        }
        current_value = 1 - current_value;
        index++;
    }

    for (int i = 0; i < n; ++i) {
        for (int _ = 0; _ < n; ++_) {
            cout << matrix[i][_];
        }
        cout << endl;  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

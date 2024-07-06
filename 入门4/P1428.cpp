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
vector<int> count_less_cute_fish(int n, vector<int>& arr) {
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                count++;
            }
        }
        result[i] = count;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = count_less_cute_fish(n, arr);

    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int INT_MAX = 1e6;
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sum += w[i];
    }

    int m = sum - x;
    vector<int> f(INT_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }

    cout << sum - f[m] << endl;
    return 0;
}
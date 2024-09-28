#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_SIZE = 1e5 + 7;
int T, n, q, coordinates[MAX_SIZE];
map<int, int> countMap;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> coordinates[i];
            int segmentCount = (n - 1) + (i - 1) * (n - i);
            countMap[segmentCount]++;
        }

        for (int i = 1; i < n; i++) {
            int segmentCount = i * (n - i);
            countMap[segmentCount] += (coordinates[i + 1] - coordinates[i] - 1);
        }

        while (q--) {
            int query;
            cin >> query;
            cout << countMap[query] << " ";
        }
        cout << "\n";

        countMap.clear();
    }
    return 0;
}

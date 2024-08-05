#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCut(const vector<int>& logs, int k, int l) {
    long long count = 0;
    for (int length : logs) {
        count += length / l;
        if (count >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> logs(n);
    for (int i = 0; i < n; ++i) {
        cin >> logs[i];
    }

    int left = 1, right = *max_element(logs.begin(), logs.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCut(logs, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}

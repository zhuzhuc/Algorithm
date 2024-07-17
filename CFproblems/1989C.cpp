#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int x = 0, y = 0, neg = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        x += a[i];
      } else if (a[i] < b[i]) {
        y += b[i];
      } else {
        neg += (a[i] < 0);
        pos += (a[i] > 0);
      }
    }
    int ans = -1e9;
    for (int i = -neg; i <= pos; ++i)
      ans = max(ans, min(x + i, y + (pos - neg - i)));
    cout << ans << '\n';
  }
}
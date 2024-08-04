#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x != 1) {
        long long ost = (x / y + 1) * y - x;
                ost = max(1ll, ost);
                ost = min(ost, k);
                x += ost;
        while (x % y == 0) {
            x /= y;
        }
        k -= ost;
    }
    cout << x + k % (y - 1) << '\n';
}
 
int main()
{
#ifdef FELIX
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int tests = 1;
    cin >> tests;
    for (int test = 0; test < tests; test++){
        solve();
    }
 
#ifdef FELIX
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}
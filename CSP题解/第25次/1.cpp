#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int n, m;
bool st[N];

int main() {
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    st[0] = true;

    int res = 0;
    while (m--) {
        int x, y;
        // scanf("%d%d", &x, &y);
        cin >> x >> y;
        if (!st[y]) res++;
        st[x] = true;
    }

    // printf("%d\n", res);
    cout << res << " ";
    return 0;
}
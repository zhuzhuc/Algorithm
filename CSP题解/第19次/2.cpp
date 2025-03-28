#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
typedef long long LL;
const int N = 500010;
// const int N = 500010;
int n, m;
PII a[N], b[N];

int main() {
    scanf("%*d%d%d", &n, &m);
    for (int i = 0; i < n; i++)  cin >> a[i].x >> a[i].y;//scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 0; i < m; i++)  cin >> b[i].x >> b[i].y;//scanf("%d%d", &b[i].x, &b[i].y);

    LL res = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && b[j].x < a[i].x) j++;
        if (j < m && b[j].x == a[i].x) res += (LL)a[i].y * b[j].y;
    }
    cout << res << endl;
    // printf("%lld\n", res);
    return 0;
}

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

const int N = 300 * 1000 + 13;

int n;
pair<pt, int> a[N];

int main() {
    scanf("%d", &n);
    forn(i, n){
        scanf("%d%d", &a[i].x.x, &a[i].x.y);
        a[i].y = i + 1;
    }
    
    sort(a, a + n, [&](pair<pt, int> a, pair<pt, int> b){if (a.x.x != b.x.x) return a.x.x < b.x.x; return a.x.y > b.x.y;});
    
    set<pt> cur;
    forn(i, n){
        while (!cur.empty() && cur.begin()->x < a[i].x.x)
            cur.erase(cur.begin());
        if (!cur.empty() && (--cur.end())->x >= a[i].x.y){
            printf("%d %d\n", a[i].y, (--cur.end())->y);
            return 0;
        }
        cur.insert({a[i].x.y, a[i].y});
    }
    
    puts("-1 -1");
    return 0;
}
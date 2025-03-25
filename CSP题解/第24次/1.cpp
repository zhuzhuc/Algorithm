#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 210;
int main(){
    int n,m;
    cin >> n >> m;
    int a[N];
    for(int i = 1; i <= n; i ++) cin >> a[i];
    a[n + 1] = m;
    int res = 0;
    for(int i = 1; i <= n; i ++)
        res += i * (a[i + 1] - a[i]);
    cout << res << endl;
    return 0;
}
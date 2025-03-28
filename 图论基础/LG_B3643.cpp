#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int M = 1001, N = 1e5+10;
int g[M][M];
int e[2 * N], ne[2 * N], h[M], idx;
int cnt[M];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main() {
    int n,m;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a,b;cin >> a >> b;
        g[a][b]=1;g[b][a]=1;
        add(a,b);
        add(b,a);
        cnt[a]++;cnt[b]++;
    }
    // 输出邻接矩阵
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){  // 修正这里：j <= n 而不是 j <= m
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    // 输出邻接表
    for(int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
        for(int j = h[i]; j != -1; j = ne[j]){
            int k = e[j];
            cout << k << " ";  // 直接输出相邻节点
        }
        cout << endl;
    }
    
    return 0;
}
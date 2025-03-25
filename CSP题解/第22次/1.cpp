#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, L;
    cin >> n >> m >> L;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<int> h(L, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            h[a[i][j]]++;
    for(int i  =0; i < L; i++)
        cout << h[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int Left, Right, minn, ans;
int s[5];
int a[21][5];


void search(int x, int y) {
    if (x > s[y]) {
        minn = min(minn, max(Left, Right));
        return;
    }
    Left += a[x][y];
    search(x + 1, y);
    Left -= a[x][y];
    Right += a[x][y];
    search(x + 1, y);
    Right -= a[x][y];
}

int main() {
    
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    
    
    for (int i = 1; i <= 4; i++) {
        Left = Right = 0;
        minn = INT_MAX; 
        for (int j = 1; j <= s[i]; j++)
            cin >> a[j][i];
     
        search(1, i);
        ans += minn;
    }
    
    cout << ans;
    return 0;
}

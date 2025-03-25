#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // 创建前缀和二维数组
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    
    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = a[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    int count = 0; // 用来记录处于较暗区域的像素个数
    
    // 遍历每个像素，计算它的邻域均值
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 定义邻域的边界
            int x1 = max(0, i - r);
            int y1 = max(0, j - r);
            int x2 = min(n - 1, i + r);
            int y2 = min(n - 1, j + r);
            
            // 计算邻域元素的总和
            int sum = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
            
            // 邻域元素的个数
            int count_neighbors = (x2 - x1 + 1) * (y2 - y1 + 1);
            
            // 计算邻域均值
            double avg = sum * 1.0 / count_neighbors;
            
            // 判断是否为较暗区域
            if (avg <= t) {
                count++;
            }
        }
    }
    
    // 输出较暗区域的像素个数
    cout << count << endl;
    
    return 0;
}

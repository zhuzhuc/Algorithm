// #include <iostream>

// using namespace std;

// const int N = 4e5 + 10;

// int main() {
//     int n, m, k;
//     int b[N] = {0}; // 差分数组初始化为 0

//     cin >> n >> m >> k;

//     int t, c;
//     // 读取出行计划并构造差分数组
//     for (int i = 1; i <= n; i++) {
//         cin >> t >> c;
//         int left = t - c + 1;
//         left = left > 0 ? left : 1; // 保证 left 不小于 1
//         int right = t;
//         b[left]++;      // 左端点增加
//         b[right + 1]--; // 右端点后一位减少
//     }

//     // 前缀和计算实际区间覆盖的次数
//     for (int i = 1; i < N; i++) {
//         b[i] = b[i - 1] + b[i];
//     }

//     // 处理查询
//     for (int i = 1; i <= m; i++) {
//         int q;
//         cin >> q;
//         cout << b[q + k] << endl; // 输出查询时刻结果
//     }

//     return 0;
// }
//q <= t - k
//q >= t - k - c + 1;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5+1;

int b[N];

int n,m,k;
int main(){
    cin >> n >> m >> k;
    while(n --){
        int t,c;
        cin >> t >> c;
        int l = max(1, t-k-c+1);
        int r = t - k;
        if(r > 0){
            b[l]++;b[r+1]--;
        }
            
    }
    for(int i = 1; i < N; i++) b[i] += b[i - 1];
    while(m--){
        int q;cin >> q;
        cout << b[q] << endl;
    }
    return 0;
}
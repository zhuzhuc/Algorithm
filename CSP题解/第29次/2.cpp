#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>    
using namespace std;
typedef long long ll;
const int N = 10010, D = 21;
ll Q[N][D], KT[D][N], V[N][D], W[N];
ll temp[D][D], res[N][D];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d;
    cin >> n >> d;
    
    // 输入优化：一次性读取
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=d;j++) 
            cin >> Q[i][j];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            cin >> KT[j][i];  // 直接存储转置
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            cin >> V[i][j];
    
    for(int i=1;i<=n;i++)
        cin >> W[i];
    
    // 第一层矩阵乘法：KT × V → temp (d×d)
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            // 去掉 register 关键字
            ll sum = 0;
            for(int k=1;k<=n;k++){
                sum += KT[i][k] * V[k][j];
            }
            temp[i][j] = sum;
        }
    }
    
    // 第二层矩阵乘法：Q × temp → res (n×d)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            // 去掉 register 关键字
            ll sum = 0;
            for(int k=1;k<=d;k++){
                sum += Q[i][k] * temp[k][j];
            }
            res[i][j] = sum * W[i];
        }
    }
    
    // 输出优化
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            cout << res[i][j] << " \n"[j==d];
        }
    }
    
    return 0;
}
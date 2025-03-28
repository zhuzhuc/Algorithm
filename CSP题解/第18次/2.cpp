#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 1010;

int ans[5];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
pair<int, int> q[N];

/**
 * @brief 主函数，程序的入口点
 * 
 * 该函数用于读取二维平面上的点集，统计满足特定条件的点的数量，并输出结果。
 * 
 * @return int 程序的退出状态码，0 表示正常退出
 */
int main(){
    // 定义一个整数变量 n，用于存储输入的点的数量
    int n;
    // 从标准输入读取一个整数赋值给 n
    cin >> n;
    
    // 循环 n 次，读取每个点的坐标
    for(int i = 0; i < n; i++){
        // 读取一对整数，分别存储在 q[i] 的 first 和 second 成员中
        cin >> q[i].first >> q[i].second;
    }
    
    // 遍历每个点
    for(int i = 0; i < n; i++){
        // 初始化一个长度为 8 的数组 s，用于记录点 q[i] 周围 8 个方向上是否有点
        int s[8] = {0};
        // 遍历所有点
        for(int j = 0; j < n; j++){
            // 遍历 8 个方向
            for(int k = 0; k < 8; k++){
                // 检查点 q[j] 是否在点 q[i] 的第 k 个方向上
                if(q[i].first + dx[k] == q[j].first and q[i].second + dy[k] == q[j].second){
                    // 如果是，则将 s[k] 加 1
                    s[k]++;
                }
            }
        }
        // 检查点 q[i] 的上、右、下、左四个方向上是否都有点
        if(s[1] and s[3] and s[5] and s[7]){
            // 如果满足条件，则将 ans 数组中对应位置的值加 1
            ans[s[0] + s[2] + s[4] + s[6]]++;
        }
    }
    // 循环 5 次，依次输出 ans 数组中的每个元素
    for(int i = 0; i < 5; i++){
        // 输出 ans[i] 的值并换行
        cout << ans[i] << endl;
    }

    // 表示程序正常结束
    return 0;
}
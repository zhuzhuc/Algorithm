#include <iostream>
#include <vector>
using namespace std;

// 判断胜负的函数，返回1表示A赢，-1表示B赢，0表示平局
int judge(int a, int b) {
    // 定义胜负关系表
    int results[5][5] = {
        // 剪刀 石头 布 蜥蜴人 斯波克
        {  0,   -1,   1,    1,   -1}, // 剪刀
        {  1,    0,  -1,   -1,    1}, // 石头
        { -1,    1,   0,    1,   -1}, // 布
        { -1,    1,  -1,    0,    1}, // 蜥蜴人
        {  1,   -1,   1,   -1,    0}  // 斯波克
    };
    return results[a][b];
}

int main() {
    int N, N_A, N_B;
    cin >> N >> N_A >> N_B;
    
    vector<int> A(N_A);
    vector<int> B(N_B);
    
    // 读取小A的出拳规律
    for (int i = 0; i < N_A; ++i) {
        cin >> A[i];
    }
    
    // 读取小B的出拳规律
    for (int i = 0; i < N_B; ++i) {
        cin >> B[i];
    }
    
    int scoreA = 0, scoreB = 0;
    
    for (int i = 0; i < N; ++i) {
        int a = A[i % N_A];
        int b = B[i % N_B];
        int result = judge(a, b);
        if (result == 1) {
            ++scoreA;
        } else if (result == -1) {
            ++scoreB;
        }
    }
    
    cout << scoreA << " " << scoreB << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int k1, k2;
    
    // 读取第一个多项式
    cin >> k1;
    vector<pair<int, double>> poly1(k1);
    for (int i = 0; i < k1; i++) {
        cin >> poly1[i].first >> poly1[i].second;
    }
    
    // 读取第二个多项式
    cin >> k2;
    vector<pair<int, double>> poly2(k2);
    for (int i = 0; i < k2; i++) {
        cin >> poly2[i].first >> poly2[i].second;
    }
    
    // 结果数组，最大指数为2000
    vector<double> result(2001, 0.0);
    
    // 多项式乘法
    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            int exp = poly1[i].first + poly2[j].first;
            double coeff = poly1[i].second * poly2[j].second;
            result[exp] += coeff;
        }
    }
    
    // 统计非零项的数量
    int count = 0;
    for (int i = 2000; i >= 0; i--) {
        if (abs(result[i]) > 1e-6) {  // 避免浮点数精度问题
            count++;
        }
    }
    
    // 输出结果
    cout << count;
    for (int i = 2000; i >= 0; i--) {
        if (abs(result[i]) > 1e-6) {
            cout << " " << i << " " << fixed << setprecision(1) << result[i];
        }
    }
    cout << endl;
    
    return 0;
}
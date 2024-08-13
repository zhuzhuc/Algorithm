#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        
        // 排序三个点
        int arr[3] = {x1, x2, x3};
        sort(arr, arr + 3);
        
        // 最小 f(a) 对应于中间点 arr[1]
        int min_fa = (arr[1] - arr[0]) + (arr[2] - arr[1]);
        
        // 输出结果
        cout << min_fa << endl;
    }

    return 0;
}

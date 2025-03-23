
/*
给定一个按照升序排列的长度为 n
 的整数数组，以及 q
 个查询。

对于每个查询，返回一个元素 k
 的起始位置和终止位置（位置从 0
 开始计数）。

如果数组中不存在该元素，则返回 -1 -1。

输入格式
第一行包含整数 n
 和 q
，表示数组长度和询问个数。

第二行包含 n
 个整数（均在 1∼10000
 范围内），表示完整数组。

接下来 q
 行，每行包含一个整数 k
，表示一个询问元素。

输出格式
共 q
 行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回 -1 -1。

数据范围
1≤n≤100000

1≤q≤10000

1≤k≤10000

输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/
#include <iostream>
#include <algorithm>    
using namespace std;
const int N = 100001;
int a[N];

bool isblue1(int num, int x) {
    return num < x;
}
int binary_search1(int q[], int len, int x) {
    int l = -1, r = len;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (isblue1(q[mid], x)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // 检查 r 是否越界
    if (r < len && q[r] == x) return r;
    return -1;
}
bool isblue2(int num, int x) {
    return num <= x;
}

int binary_search2(int q[], int len, int x) {
    int l = -1, r = len;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (isblue2(q[mid], x)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // 检查 l 是否有效
    if (l >= 0 && q[l] == x) return l;
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (m--) {
        int x;
        cin >> x;
        int res1 = binary_search1(a, n, x);
        int res2 = binary_search2(a, n, x);
        cout << res1 << " " << res2 << endl;
    }
    return 0;
}

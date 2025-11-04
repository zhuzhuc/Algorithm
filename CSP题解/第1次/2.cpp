#pragma comment(linker, "/STACK:1024000000,1024000000")
#ifndef _GLIBCXX_NO_ASSERT
#include<cassert>
#endif
#include<cctype>
#include<cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define dou double
using namespace std;

typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
 
/*
在某图形操作系统中，有 N
 个窗口，每个窗口都是一个两边与坐标轴分别平行的矩形区域。

窗口的边界上的点也属于该窗口。

窗口之间有层次的区别，在多于一个窗口重叠的区域里，只会显示位于顶层的窗口里的内容。

当你点击屏幕上一个点的时候，你就选择了处于被点击位置的最顶层窗口，并且这个窗口就会被移到所有窗口的最顶层，而剩余的窗口的层次顺序不变。

如果你点击的位置不属于任何窗口，则系统会忽略你这次点击。

现在我们希望你写一个程序模拟点击窗口的过程。

输入格式
输入的第一行有两个正整数，即 N
 和 M
。

接下来 N
 行按照从最下层到最顶层的顺序给出 N
 个窗口的位置。

每行包含四个非负整数 x1,y1,x2,y2
，表示该窗口的一对顶点坐标分别为 (x1,y1)
 和 (x2,y2)
。保证 x1<x2,y1<y2
。

接下来 M
 行每行包含两个非负整数 x,y
，表示一次鼠标点击的坐标。

题目中涉及到的所有点和矩形的顶点的 x,y
 坐标分别不超过 2559
 和 1439
。

输出格式
输出包括 M
 行，每一行表示一次鼠标点击的结果。

如果该次鼠标点击选择了一个窗口，则输出这个窗口的编号(窗口按照输入中的顺序从 1
 编号到 N
)。

如果没有，则输出 IGNORED。

数据范围
1≤N,M≤10

输入样例：
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5
输出样例：
2
1
1
IGNORED
样例解释
第一次点击的位置同时属于第 1
 和第 2
 个窗口，但是由于第 2
 个窗口在上面，它被选择并且被置于顶层。

第二次点击的位置只属于第 1
 个窗口，因此该次点击选择了此窗口并将其置于顶层。现在的三个窗口的层次关系与初始状态恰好相反了。

第三次点击的位置同时属于三个窗口的范围，但是由于现在第 1
 个窗口处于顶层，它被选择。

最后点击的 (0,5)
 不属于任何窗口。

难度：简单
时/空限制：1s / 256MB
总通过数：1999
总尝试数：3826
来源：
第一次CCF-CSP计算机软件能力认证
算法标签

 */
const int N = 15;
int n, m;
struct win {
    int x1, y1, x2, y2, id;
} w[N];

int get(int x, int y) {
    for (int i = n; i > 0; i--) {
        if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2) {
            return i;
        }
    }
    return 0; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	int x1, x2, y1, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	w[i] = {x1, y1, x2, y2, i};
    }
    while (m--) {
        int x, y;
        cin >> x >> y;

     
        int t = get(x, y);
        if (t == 0) {
            cout << "IGNORED" << endl;
        } else {
            cout << w[t].id << endl;

      
            win selectedWindow = w[t];
            for (int i = t; i < n; i++) {
                w[i] = w[i + 1];
            }
            w[n] = selectedWindow; 
        }
    }
    return 0;
}
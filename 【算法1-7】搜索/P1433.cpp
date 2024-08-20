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
 
 
const int MAX_N = 15;
double dist[MAX_N][MAX_N];
double dp[1 << MAX_N][MAX_N];
pair<double, double> cheese[MAX_N];

double distance(int i, int j) {
    return sqrt((cheese[i].first - cheese[j].first) * (cheese[i].first - cheese[j].first) +
                (cheese[i].second - cheese[j].second) * (cheese[i].second - cheese[j].second));
}

int main() {
    int n;
    cin >> n;
    
    // 输入奶酪坐标
    for (int i = 0; i < n; i++) {
        cin >> cheese[i].first >> cheese[i].second;
    }

    // 计算所有奶酪之间的距离
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = distance(i, j);
        }
    }

    // 初始化 DP 数组
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = 1e9;  // 一个极大的数
        }
    }

    // 初始条件：从 (0, 0) 点到每块奶酪的距离
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = sqrt(cheese[i].first * cheese[i].first + cheese[i].second * cheese[i].second);
    }

    // 动态规划 + 状态压缩
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // 如果第 i 个奶酪在当前状态 mask 中被访问过
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) {  // 如果第 j 个奶酪在当前状态 mask 中没有被访问
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i][j]);
                    }
                }
            }
        }
    }

    // 计算最终答案，所有奶酪都被访问的最小距离
    double answer = 1e9;
    int full_mask = (1 << n) - 1;  // 所有奶酪都被访问的状态
    for (int i = 0; i < n; i++) {
        answer = min(answer, dp[full_mask][i]);
    }

    // 输出结果，保留 2 位小数
    cout << fixed << setprecision(2) << answer << endl;

    return 0;
}
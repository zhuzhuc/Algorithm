// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> a(n + 1), b(n + 1), w(n + 1, 0);

//     for (int i = 0; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> b[i];

//     // 计算正常情况下的最小 w
//     int w_min = a[0], curr_energy = w_min;
//     for (int i = 1; i <= n; i++) {
//         curr_energy -= a[i - 1];
//         if (curr_energy < 0) {  // 如果能量不足，需要补足
//             w_min += -curr_energy;
//             curr_energy = 0;
//         }
//         curr_energy += b[i];  // 吸收补给
//     }
//     curr_energy -= a[n];  // 最后回到 0 号区域
//     if (curr_energy < 0) w_min += -curr_energy;

//     // 计算 w(i)
//     for (int i = 1; i <= n; i++) {
//         int w_i = w_min;
//         curr_energy = w_min;
//         for (int j = 1; j <= n; j++) {
//             curr_energy -= a[j - 1];
//             if (curr_energy < 0) {
//                 w_i += -curr_energy;
//                 curr_energy = 0;
//             }
//             if (j == i) continue;  // 第 i 号区域不补给
//             curr_energy += b[j];
//         }
//         curr_energy -= a[n];
//         if (curr_energy < 0) w_i += -curr_energy;
//         w[i] = w_i;
//     }

//     // 输出 w(1), w(2), ..., w(n)
//     for (int i = 1; i <= n; i++) {
//         cout << w[i] << " ";
//     }

//     return 0;
// }
//前缀和解法
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
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i <= n; i++) cin >> a[i];
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> sum(n+1);//前缀数组
    vector<int> pre_max(n+1);//前缀最大数组
    sum[0] = a[0];pre_max[0] = sum[0];
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i] - b[i];
        pre_max[i] = max(sum[i], pre_max[i - 1]);
    }
    vector<int> suf_max(n+1);
    suf_max[n] = sum[n];
    for(int i = n - 1; i >= 1; i--){
        suf_max[i] = max(sum[i], suf_max[i + 1]);
    }
    for(int i = 1; i <= n; i++){
        int ans = max(pre_max[i - 1], suf_max[i] + b[i]);
        cout << ans << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

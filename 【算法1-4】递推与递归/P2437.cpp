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



#define ll long long
#define dou double
using namespace std;

typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
 
 
 
void solve(){

    int m, n;
    cin >> m >> n;

    int len = 1; 
    vector<vector<int>> f(1005, vector<int>(1005, 0)); 

    f[1][1] = 1;
    f[2][1] = 2;

    auto plus = [&](int x) {
        for (int i = 1; i <= len; i++)
            f[x][i] = f[x-1][i] + f[x-2][i];
        for (int i = 1; i <= len; i++) {
            if (f[x][i] > 9) {
                f[x][i + 1] += f[x][i] / 10;
                f[x][i] %= 10;
            }
        }
        if (f[x][len + 1]) len++;
    };

    for (int i = 3; i <= n - m; i++) plus(i);

    for (int i = len; i > 0; i--)
        cout << f[n - m][i];
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
                    
    solve();
    return 0;
}
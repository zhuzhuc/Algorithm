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

int N, M, K, visited[1000];
vector<int> v[1000];
int lost;

void dfs(int mm) {
    visited[mm] = 1;
    for (int x : v[mm]) {
        if (x != lost && !visited[x]) {
            dfs(x);
        }
    }
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int j, k;
        cin >> j >> k;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    
    int check_count = K; 
    while (check_count--) {
        cin >> lost;
        for (int i = 1; i <= N; i++) visited[i] = 0;
        
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && i != lost) {
                ans++;
                dfs(i);
            }
        }
        cout << ans - 1 << endl;  
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}
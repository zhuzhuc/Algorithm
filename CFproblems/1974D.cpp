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
 
 
 
unordered_map<char, char> inv = {
    {'N', 'S'}, {'S', 'N'},
    {'E', 'W'}, {'W', 'E'}
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'N') {
            y += 1;
        }
        if (c == 'S') {
            y -= 1;
        }
        if (c == 'E') {
            x += 1;
        }
        if (c == 'W') {
            x -= 1;
        }
    }

    if (x % 2 != 0 || y % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<char> ans(n, 'R');
    if (x == 0 && y == 0) {
        if (n == 2) {
            cout << "NO" << endl;
            return;
        }
        ans[0] = 'H';
        ans[s.find(inv[s[0]])] = 'H';
    } else {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N' && y > 0) {
                y -= 2;
                ans[i] = 'H';
            }
            if (s[i] == 'S' && y < 0) {
                y += 2;
                ans[i] = 'H';
            }
            if (s[i] == 'E' && x > 0) {
                x -= 2;
                ans[i] = 'H';
            }
            if (s[i] == 'W' && x < 0) {
                x += 2;
                ans[i] = 'H';
            }
        }
    }

    for (char c : ans) {
        cout << c;
    }
    cout << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t; while(t--){             
    solve();}
    return 0;
}
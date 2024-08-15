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
 
 
 
void solve(int tc) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    vector<pair<int, int>> ver, hor;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ver.push_back({x, y});
        hor.push_back({y, x});
    }

    set<pair<int, int>> deleted;
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());

    int ans[2] = {0, 0};
    int u = 1, d = a, l = 1, r = b;
    int hl = 0, hr = n - 1, vl = 0, vr = n - 1;

    for (int i = 0; i < m; ++i) {
        char c;
        int k;
        cin >> c >> k;

        if (c == 'U') {
            u += k;
            while (vl <= vr && ver[vl].first < u) {
                if (deleted.find(ver[vl]) == deleted.end()) {
                    ans[i % 2] += 1;
                    deleted.insert(ver[vl]);
                }
                vl++;
            }
        }
        if (c == 'D') {
            d -= k;
            while (vl <= vr && ver[vr].first > d) {
                if (deleted.find(ver[vr]) == deleted.end()) {
                    ans[i % 2] += 1;
                    deleted.insert(ver[vr]);
                }
                vr--;
            }
        }
        if (c == 'L') {
            l += k;
            while (hl <= hr && hor[hl].first < l) {
                if (deleted.find({hor[hl].second, hor[hl].first}) == deleted.end()) {
                    ans[i % 2] += 1;
                    deleted.insert({hor[hl].second, hor[hl].first});
                }
                hl++;
            }
        }
        if (c == 'R') {
            r -= k;
            while (hl <= hr && hor[hr].first > r) {
                if (deleted.find({hor[hr].second, hor[hr].first}) == deleted.end()) {
                    ans[i % 2] += 1;
                    deleted.insert({hor[hr].second, hor[hr].first});
                }
                hr--;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
                    
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
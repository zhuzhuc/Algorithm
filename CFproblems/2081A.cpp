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
// const int MOD = 1000000007;
// ll power(ll a, ll b, ll mod) {
//     ll res = 1;
//     while(b){
//         if(b % 2) res = (res * a) % mod;
//         a = (a * a) % mod;
//         b /= 2;
//     }
//     return res;
// }
 
// void solve(){

//     int n;
//     cin >> n;
//     string bin;
//     cin >> bin;
//     ll x = 0;
//     for(char c : bin){
//         x = (x * 2 + (c - '0')) % MOD;
//     }
//     ll ex = 0;
//     ll cur = x;
//     while(cur  > 1){
//         ex = (ex + 1) % MOD;
//         cur = cur / 2;
//     }
//     cout << ex << "\n";
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, r = 0, c = 0;
        cin >> n >> m;
        
        vector<int> colXOR(m, 0);  

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int rowXOR = 0;
            for (int j = 0; j < m; ++j) {
                int bit = s[j] - '0';
                rowXOR ^= bit;
                colXOR[j] ^= bit;  
            }
            if (rowXOR) r++; 
        }

        for (int j = 0; j < m; ++j) {
            if (colXOR[j]) c++;  
        }

        cout << max(r, c) << endl;  
    }

    return 0;
}
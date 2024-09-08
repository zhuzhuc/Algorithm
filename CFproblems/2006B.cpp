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

namespace FastIO {
	template <typename T> inline T read() { 
        T x = 0, w = 0; 
        char ch = getchar(); 
        while (ch < '0' || ch > '9') 
            w |= (ch == '-'), ch = getchar(); 
        while ('0' <= ch && ch <= '9') 
            x = x * 10 + (ch ^ '0'), ch = getchar(); 
        return w ? -x : x; 
    }
	template <typename T> inline void write(T x) { 
        if (!x) 
            return; 
        write<T>(x / 10), putchar(x % 10 ^ '0'); 
    }
	template <typename T> inline void print(T x) { 
        if (x < 0) 
            putchar('-'), x = -x; 
        else if (x == 0) 
            putchar('0'); 
        write<T>(x); 
    }
	template <typename T> inline void print(T x, char en) { 
        if (x < 0) 
            putchar('-'), x = -x; 
        else if (x == 0) 
            putchar('0'); 
        write<T>(x), putchar(en); 
    }
}; using namespace FastIO;

#define MAXN 200001
int fa[MAXN], dep[MAXN];
int c1[MAXN], c2[MAXN], len[MAXN];

void solve() {
	int N = read<int>(); 
    long long w = read<long long>();
	for (int i = 2; i <= N; ++i) fa[i] = read<int>();
	for (int i = 2; i <= N; ++i) dep[i] = dep[fa[i]] + 1;
	for (int i = 1; i <= N; ++i) len[i] = c1[i] = 0;
	for (int i = 1, x, y; i <= N; ++i) {
		x = i, y = (i == N ? 1 : i + 1);
		while (x != y) {
			if (dep[x] < dep[y]) std::swap(x, y);
			(c1[x] ? c2[x] : c1[x]) = i, x = fa[x], ++len[i];
		}
	}
	long long sum = 0, sur = N;
	for (int i = 1, x; i < N; ++i) {
		x = read<int>(), sum += read<long long>();
		if ((--len[c1[x]]) == 0) --sur;
		if ((--len[c2[x]]) == 0) --sur;
		print<long long>(sum * 2 + sur * (w - sum), " \n"[i == N - 1]);
	}
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = read<int>(); 
    while (T--) solve(); 
    
    return 0; 
}

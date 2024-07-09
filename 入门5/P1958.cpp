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

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define dou double
using namespace std;

typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
 
 
 
void solve(){
    // Initialize frequency array for 26 uppercase letters
    vector<int> freq(26, 0);
    
    // Process each line of input
    string line;
    for (int i = 0; i < 4; ++i) {
        getline(cin, line);
        // Count frequencies of uppercase letters
        for (char c : line) {
            if (c >= 'A' && c <= 'Z') {
                freq[c - 'A']++;
            }
        }
    }
    
    // Find maximum frequency to determine number of lines needed
    int max_freq = *max_element(freq.begin(), freq.end());
    
    // Output vertical histogram
    for (int i = max_freq; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (freq[j] >= i) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    // Output last line with all letters
    for (char c = 'A'; c <= 'Z'; ++c) {
        cout << c << " ";
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
                    
    solve();
    return 0;
}
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
long long trans(char c){
    if(c >= '0'&&c <= '9') return c-'0';
    else return c - 'a' + 10;
}
long long transs(string N, ll r){
    ll Sum = 0;
    for(ll i = N.size() - 1, unit=1; i>=0; i--, unit*=r){
        ll j = trans(N[i]);
        Sum += j * unit;
    }
    return Sum;
}
int trans2(string N, ll r, ll value){
    ll Sum = 0;
    for(ll i = N.size()-1,unit=1; i>=0; i--, unit*=r){
        if(unit>value)return 1;
        ll j = trans(N[i]);
        Sum += j*unit;
    }
    if(Sum>value)return 1;
    if(Sum==value) return 0;
    if(Sum<value) return -1;
}
int main(){
    string N1,N2;
    ll tag, r1, r2;
    cin >> N1 >> N2 >> tag >> r1;
    if(tag==2){
        auto a=N1,N1=N2,N2=a;
    }
    ll value=transs(N1,r1);
    ll Maxdigit=0;
    for(char c : N2){
        ll j = trans(c);
        if(j > Maxdigit) Maxdigit=j;
    }
    ll low, high;
    if(transs(N2, Maxdigit+1)==value){
        cout <<Maxdigit+1;return 0;
    }
    for(low = Maxdigit+1, high = INT_MAX;low <= high;){
        ll mid =  (low + high) / 2;
        int temp = trans2(N2, mid, value);
        if(temp == 0) cout << mid; return 0;
        if(temp < 0)low =mid+1;
        else high = mid + 1;
    }
    cout << "Impossible";
    
    return 0;
}
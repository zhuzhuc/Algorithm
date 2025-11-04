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
int N,M,K,Q,m;
struct customer{
    int processing_time, leave_time = 0;
};
customer c[1001];
int main(){
    cin >> N >> M >> K >> Q;
    queue<int> q[N];
    int cur = 1;
    for(int i = 1; i <= K; i++) cin >> c[i].processing_time;
    for(int Time = 480; Time < 1020; Time++){
        for(int i = 0; i < N; i++){
            if(q[i].size()){
                int j = q[i].front();
                if(c[j].leave_time == Time){
                    q[i].pop();
                }
            }
        }
        for(int j = 1; j <=M; j++){
            for(int i = 0; i < N; i++){
                if(q[i].size()<j){
                    if(cur <= K){
                        q[i].push(cur);
                        cur++;
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(q[i].size()){
                int j = q[i].front();
                if(c[j].leave_time == 0){
                    c[j].leave_time = Time + c[j].processing_time;
                }
            }
        }
    }
    while(Q--){
        cin >> m;
        if(c[m].leave_time == 0){
            cout << "Sorry\n";
        }else{
            printf("%02d:%02d\n", c[m].leave_time/60, c[m].leave_time%60);
        }
    }
    return 0;
}
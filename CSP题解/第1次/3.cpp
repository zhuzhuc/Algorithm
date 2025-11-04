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
 
const int N = 30;
int n;
bool o1[N], o2[N];
string ans[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string fmt;
    cin >> fmt;

    // 解析格式字符串
    bool noArg[26] = {0}, hasArg[26] = {0};
    for (int i = 0; i < (int)fmt.size(); i++) {
        char c = fmt[i];
        if (i + 1 < (int)fmt.size() && fmt[i + 1] == ':') {
            hasArg[c - 'a'] = true;
            i++;
        } else {
            noArg[c - 'a'] = true;
        }
    }

    int N;
    cin >> N;
    cin.ignore(); // 读掉换行

    for (int t = 1; t <= N; t++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> tokens;
        string tmp;
        while (ss >> tmp) tokens.push_back(tmp);

        map<char, string> used; // 记录选项（按字母升序）

        for (int i = 1; i < (int)tokens.size(); i++) {
            string cur = tokens[i];
            if (cur.size() != 2 || cur[0] != '-' || cur[1] < 'a' || cur[1] > 'z') {
                break; // 非法选项，停止分析
            }
            char opt = cur[1];
            if (noArg[opt - 'a']) {
                used[opt] = "";
            } else if (hasArg[opt - 'a']) {
                if (i + 1 < (int)tokens.size()) {
                    used[opt] = tokens[i + 1]; // 保存参数
                    i++;
                } else {
                    break; // 参数缺失，停止
                }
            } else {
                break; // 不在格式字符串里，停止
            }
        }

        cout << "Case " << t << ":";
        for (auto &kv : used) {
            cout << " -" << kv.first;
            if (!kv.second.empty()) cout << " " << kv.second;
        }
        cout << "\n";
    }

    return 0;
}

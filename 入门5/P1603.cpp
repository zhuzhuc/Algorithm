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
 
 
std::vector<int> extract_numbers(const std::string& sentence) {
    std::unordered_map<std::string, int> word_to_number = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
        {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
        {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18},
        {"nineteen", 19}, {"twenty", 20},
        {"a", 1}, {"both", 2}, {"another", 1}, {"first", 1}, {"second", 2}, {"third", 3}
    };

    std::istringstream iss(sentence);
    std::string word;
    std::vector<int> numbers;
    
    while (iss >> word) {
       
        if (word.back() == '.') {
            word.pop_back();
        }
        auto it = word_to_number.find(word);
        if (it != word_to_number.end()) {
            numbers.push_back(it->second);
        }
    }

    return numbers;
}

std::string calculate_password(const std::vector<int>& numbers) {
    std::vector<int> mod_numbers;
    for (int num : numbers) {
        mod_numbers.push_back((num * num) % 100);
    }
    
    if (mod_numbers.empty()) {
        return "0";
    }

    std::sort(mod_numbers.begin(), mod_numbers.end());

    std::string min_number;
    for (int num : mod_numbers) {
        min_number += (num < 10 ? "0" : "") + std::to_string(num);
    }
    min_number.erase(0, min_number.find_first_not_of('0'));

    return min_number.empty() ? "0" : min_number;
}

void solve(){

	std::string input_sentence;
    std::getline(std::cin, input_sentence);

    std::vector<int> numbers = extract_numbers(input_sentence);
    std::string password = calculate_password(numbers);
    std::cout << password << std::endl;



}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
                    
    solve();
    return 0;
}
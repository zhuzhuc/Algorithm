#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

string multiply(string num1, int num2) {
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        int product = (num1[i] - '0') * num2 + carry;
        num1[i] = (product % 10) + '0';
        carry = product / 10;
    }
    while (carry) {
        num1.insert(num1.begin(), (carry % 10) + '0');
        carry /= 10;
    }
    return num1;
}

string factorial(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }
    return result;
}

int count_digit(const string& number, char digit) {
    return count(number.begin(), number.end(), digit);
}
struct Candidate {
    int id;
    int score;
};

// 比较函数，用于排序
bool compareCandidates(const Candidate &a, const Candidate &b) {
    if (a.score == b.score) {
        return a.id < b.id;
    }
    return a.score > b.score;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Candidate> candidates(n);

    // 读取选手数据
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].id >> candidates[i].score;
    }

    // 按成绩降序排列，成绩相同则按报名号升序排列
    sort(candidates.begin(), candidates.end(), compareCandidates);

    // 计算面试分数线的位置
    int cutoffIndex = (int)(m * 1.5);
    int cutoffScore = candidates[cutoffIndex - 1].score;

    // 筛选出所有达到面试分数线的选手
    vector<Candidate> qualifiedCandidates;
    for (const auto &candidate : candidates) {
        if (candidate.score >= cutoffScore) {
            qualifiedCandidates.push_back(candidate);
        }
    }

    // 输出面试分数线和达到面试分数线的选手人数
    cout << cutoffScore << " " << qualifiedCandidates.size() << endl;

    // 输出所有达到面试分数线的选手
    for (const auto &candidate : qualifiedCandidates) {
        cout << candidate.id << " " << candidate.score << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

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

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

struct Student {
    string name;
    int Chinese;
    int math;
    int English;
    int total;

    Student(string name, int Chinese, int math, int English)
        : name(name), Chinese(Chinese), math(math), English(English) {
        total = Chinese + math + English;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Student> students;

    string name;
    int Chinese, math, English;
    for (int i = 0; i < n; ++i) {
        cin >> name >> Chinese >> math >> English;
        students.emplace_back(name, Chinese, math, English);
    }

    Student* topStudent = &students[0];

    for (int i = 1; i < n; ++i) {
        if (students[i].total > topStudent->total) {
            topStudent = &students[i];
        }
    }

    cout << topStudent->name << " " << topStudent->Chinese << " " << topStudent->math << " " << topStudent->English << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

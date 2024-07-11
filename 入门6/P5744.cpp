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

struct P5744 {
    string id;
    int age;
    int score;

    void increment_age() {
        age += 1;
    }

    void update_score() {
        score = min(600, static_cast<int>(score * 1.2));
    }
};

void process_student(P5744 &student) {
    student.increment_age();
    student.update_score();
}

void solve() {
    int n;
    cin >> n;
    vector<P5744> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].age >> students[i].score;
    }

    for (int i = 0; i < n; ++i) {
        process_student(students[i]);
    }

    for (const auto &student : students) {
        cout << student.id << " " << student.age << " " << student.score << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

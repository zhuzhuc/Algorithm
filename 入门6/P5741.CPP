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
    for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) return false;}
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
    int chinese;
    int math;
    int english;
};

bool comparePairs(const pair<string, string>& a, const pair<string, string>& b) {
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int N;
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;
    }

    vector<pair<string, string>> result;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (abs(students[i].chinese - students[j].chinese) <= 5 &&
                abs(students[i].math - students[j].math) <= 5 &&
                abs(students[i].english - students[j].english) <= 5 &&
                abs((students[i].chinese + students[i].math + students[i].english) - 
                    (students[j].chinese + students[j].math + students[j].english)) <= 10) {
                if (students[i].name < students[j].name)
                    result.emplace_back(students[i].name, students[j].name);
                else
                    result.emplace_back(students[j].name, students[i].name);
            }
        }
    }

    sort(result.begin(), result.end(), comparePairs);

    for (const auto& pair : result) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
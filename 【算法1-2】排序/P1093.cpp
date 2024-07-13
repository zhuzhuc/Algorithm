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
struct P1093
{
	int id,chinese,math,english,total;
};
bool compre(const P1093 &a, const P1093 &b){
	if (a.total != b.total)
	{
		return a.total > b.total;
	}
	if(a.chinese != b.chinese){
		return a.chinese > b.chinese;
	}
	return a.id > b.id;
}
struct stu
{
    int num;
    int c,m,e; 
    int sum;
}student[310];
bool cmp(stu a,stu b)
{
    if(a.sum>b.sum) return 1;
    else if(a.sum<b.sum) return 0;
    else
    {
        if(a.c>b.c) return 1;
        else if(a.c<b.c) return 0;
        else
        {
            if(a.num>b.num) return 0;
            else return 1;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        student[i].num=i;
        cin>>student[i].c>>student[i].m>>student[i].e;
        student[i].sum=student[i].c+student[i].m+student[i].e;
    }
    sort(student+1,student+1+n,cmp);
    for(int i=1;i<=5;i++)
        cout<<student[i].num<<' '<<student[i].sum<<endl;
    return 0;
}
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

class BigInteger {
public:
    BigInteger(const string& number) : digits(number) {
        reverse(digits.begin(), digits.end());
        if (number[0] == '-') {
            is_negative = true;
            digits.pop_back();
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        if (is_negative == other.is_negative) {
            return add(digits, other.digits, is_negative);
        } else {
            return subtract(digits, other.digits, is_negative);
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (is_negative == other.is_negative) {
            return subtract(digits, other.digits, is_negative);
        } else {
            return add(digits, other.digits, !is_negative);
        }
    }

    BigInteger operator*(const BigInteger& other) const {
        string result = multiply(digits, other.digits);
        bool result_negative = is_negative != other.is_negative;
        return BigInteger((result_negative && result != "0" ? "-" : "") + result);
    }

    BigInteger operator/(const BigInteger& other) const {
        string result = divide(digits, other.digits);
        bool result_negative = is_negative != other.is_negative;
        return BigInteger((result_negative && result != "0" ? "-" : "") + result);
    }

    friend ostream& operator<<(ostream& out, const BigInteger& bigint) {
        if (bigint.is_negative) out << '-';
        for (int i = bigint.digits.length() - 1; i >= 0; --i) {
            out << bigint.digits[i];
        }
        return out;
    }

private:
    string digits;
    bool is_negative = false;

    static BigInteger add(const string& num1, const string& num2, bool negative) {
        string result;
        int carry = 0;
        int n = max(num1.size(), num2.size());

        for (int i = 0; i < n || carry; ++i) {
            int sum = carry;
            if (i < num1.size()) sum += num1[i] - '0';
            if (i < num2.size()) sum += num2[i] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return BigInteger((negative ? "-" : "") + result);
    }

    static BigInteger subtract(const string& num1, const string& num2, bool negative) {
        string result, a = num1, b = num2;
        if (is_smaller(a, b)) {
            swap(a, b);
            negative = !negative;
        }

        int n = a.size(), m = b.size(), diff, borrow = 0;
        for (int i = 0; i < n; i++) {
            diff = (a[i] - '0') - (i < m ? b[i] - '0' : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result += diff + '0';
        }

        while (result.size() > 1 && result.back() == '0') result.pop_back();
        reverse(result.begin(), result.end());
        return BigInteger((negative ? "-" : "") + result);
    }

    static string multiply(const string& num1, const string& num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> result(num1.size() + num2.size(), 0);
        int idx1 = 0, idx2 = 0;

        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';
            idx2 = 0;

            for (int j = num2.size() - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = n1 * n2 + result[idx1 + idx2] + carry;
                carry = sum / 10;
                result[idx1 + idx2] = sum % 10;
                idx2++;
            }

            if (carry > 0) {
                result[idx1 + idx2] += carry;
            }
            idx1++;
        }

        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0) i--;
        if (i == -1) return "0";

        string s;
        while (i >= 0) s += to_string(result[i--]);
        return s;
    }

    static string divide(const string& num1, const string& num2) {
      
        return "1";  
    }

    static bool is_smaller(const string& a, const string& b) {
        int n1 = a.length(), n2 = b.length();
        if (n1 < n2) return true;
        if (n2 < n1) return false;

        for (int i = 0; i < n1; i++)
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;

        return false;
    }
};

void solve() {
    string num1, num2;
    cin >> num1 >> num2;
    BigInteger b1(num1), b2(num2);

    cout <<  b1 + b2 << endl;
    //cout << "Difference: " << b1 - b2 << endl;
    //cout << "Product: " << b1 * b2 << endl;
    //cout << "Quotient: " << b1 / b2 << endl;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}


	
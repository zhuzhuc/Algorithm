
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Minister {
    int left, right;
    char leftProduct[10000], totalProduct[10000];
    char leftStr[100];
    char coins[10000];
    int coinLength;
};

bool compareMinisters(Minister a, Minister b) {
    return a.left * a.right < b.left * b.right;
}

bool compareCoins(Minister a, Minister b) {
    if (a.coinLength != b.coinLength)
        return a.coinLength > b.coinLength;
    for (int i = 0; i < a.coinLength; ++i) {
        if (a.coins[i] != b.coins[i])
            return a.coins[i] > b.coins[i];
    }
    return true;
}

void intToCharArray(int num, char arr[]) {
    int len = 0;
    while (num > 0) {
        arr[len++] = num % 10 + '0';
        num /= 10;
    }
    arr[len] = '\0';
}

void addArrays(char a[], char b[], int offset) {
    int lenA = strlen(a), carry = 0, temp;
    for (int i = 0; i < lenA; ++i, ++offset) {
        temp = (b[offset] ? b[offset] - '0' : 0) + a[i] - '0' + carry;
        b[offset] = temp % 10 + '0';
        carry = temp / 10;
    }
    if (carry) {
        b[offset++] = carry + '0';
    }
    b[offset] = '\0';
}

void multiplyArrays(char a[], char b[], char result[]) {
    int lenA = strlen(a), lenB = strlen(b);
    char temp[10000];
    for (int i = 0; i < lenA; ++i) {
        int carry = 0, lenTemp = 0;
        for (int j = 0; j < lenB; ++j) {
            int prod = (a[i] - '0') * (b[j] - '0') + carry;
            temp[lenTemp++] = prod % 10 + '0';
            carry = prod / 10;
        }
        if (carry) {
            temp[lenTemp++] = carry + '0';
        }
        temp[lenTemp] = '\0';
        addArrays(temp, result, i);
    }
}

void divideArray(char a[], int b, char result[]) {
    int lenA = strlen(a), carry = 0, lenResult = 0;
    for (int i = 0; i < lenA; ++i) {
        carry = carry * 10 + (a[i] - '0');
        if (lenResult || carry >= b) {
            result[lenResult++] = carry / b + '0';
            carry %= b;
        }
    }
    if (lenResult == 0) {
        result[lenResult++] = '0';
    }
    result[lenResult] = '\0';
}

int main() {
    int n;
    cin >> n;
    vector<Minister> ministers(n + 1);
    cin >> ministers[0].left >> ministers[0].right;

    for (int i = 1; i <= n; ++i) {
        cin >> ministers[i].left >> ministers[i].right;
    }

    sort(ministers.begin() + 1, ministers.end(), compareMinisters);

    intToCharArray(ministers[0].left, ministers[0].leftStr);
    ministers[0].leftProduct[0] = '1';
    ministers[0].leftProduct[1] = '\0';

    for (int i = 1; i <= n; ++i) {
        intToCharArray(ministers[i].left, ministers[i].leftStr);
        multiplyArrays(ministers[i - 1].leftProduct, ministers[i - 1].leftStr, ministers[i].leftProduct);
    }

    for (int i = 1; i <= n; ++i) {
        int len = strlen(ministers[i].leftProduct);
        for (int j = 0; j < len; ++j) {
            ministers[i].totalProduct[j] = ministers[i].leftProduct[len - j - 1];
        }
        ministers[i].totalProduct[len] = '\0';
    }

    for (int i = 1; i <= n; ++i) {
        divideArray(ministers[i].totalProduct, ministers[i].right, ministers[i].coins);
        ministers[i].coinLength = strlen(ministers[i].coins);
    }

    int maxCoinsIndex = 1;
    for (int i = 2; i <= n; ++i) {
        if (!compareCoins(ministers[maxCoinsIndex], ministers[i])) {
            maxCoinsIndex = i;
        }
    }

    cout << ministers[maxCoinsIndex].coins << endl;
    return 0;
}


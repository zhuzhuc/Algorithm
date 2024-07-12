#include<bits/stdc++.h>
using namespace std;

int n;

struct node {
    string na, zw, xzw;
    long long bg;
    int le, h;
} ab[115];

int change(string a) {
    if (a == "BangZhu") return 0;
    if (a == "FuBangZhu") return 1;
    if (a == "HuFa") return 2;
    if (a == "ZhangLao") return 3;
    if (a == "TangZhu") return 4;
    if (a == "JingYing") return 5;
    if (a == "BangZhong") return 6;
    return 7; 
}

bool cmp1(node x, node y) {
    if (x.bg == y.bg) return x.h < y.h;
    return x.bg > y.bg;
}

bool cmp2(node x, node y) {
    if (change(x.xzw) == change(y.xzw)) {
        if (x.le == y.le) return x.h < y.h;
        return x.le > y.le;
    }
    return change(x.xzw) < change(y.xzw);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ab[i].na >> ab[i].zw >> ab[i].bg >> ab[i].le;
        ab[i].h = i;
    }

    sort(ab + 4, ab + 1 + n, cmp1);


    for (int i = 1; i <= n; i++) {
        if (i == 1) ab[i].xzw = "BangZhu";
        else if (i == 2 || i == 3) ab[i].xzw = "FuBangZhu";
        else if (i == 4 || i == 5) ab[i].xzw = "HuFa";
        else if (i >= 6 && i <= 9) ab[i].xzw = "ZhangLao";
        else if (i >= 10 && i <= 16) ab[i].xzw = "TangZhu";
        else if (i >= 17 && i <= 41) ab[i].xzw = "JingYing";
        else ab[i].xzw = "BangZhong";
    }

    sort(ab + 1, ab + 1 + n, cmp2);


    for (int i = 1; i <= n; i++) {
        cout << ab[i].na << " " << ab[i].xzw << " " << ab[i].le << endl;
    }

    return 0;
}

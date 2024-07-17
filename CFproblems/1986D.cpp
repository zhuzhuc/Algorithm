#include<bits/stdc++.h>
using namespace std;
 
const int N = 25;
 
int t, n, a[N];
 
int main(){
    // freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n); bool if_end = false;
        for(int i=1; i<=n; i++){
            scanf("%1d", &a[i]);
        }
 
        if(n == 2){ //n-2=0，即不需要添加运算符，直接输出
            int ans = 0;
            ans = a[1] * 10 + a[2];
            printf("%d\n", ans);
            continue;
        }
        if(n == 3){
            if(a[1] == 0 or a[3] == 0){//特判0
                puts("0");
                continue;
            }
            if(a[2] == 0){//n=3，只能有一个运算符，第二位数为0答案不为0
                if(a[1] == 1) printf("%d\n", a[3]);
                else if(a[3] == 1) printf("%d\n", a[1]);
                else printf("%d\n", a[1]+a[3]);
                continue;
            }
        }
 
        int sm = 2008, id = 0;//记个位数不为1的最小二位数及位置
        int _1 = 2008, id_1 = 0;//个位数为1的最小二位数及位置
        for(int i=1; i<=n; i++){
            if(n > 3 and a[i] == 0){ //有0，全部相乘便为0
                puts("0"); if_end = true; break;
            }

            int now = a[i-1] * 10 + a[i];
            if(i > 1 and a[i] == 1){
                if(_1 > now) _1 = now, id_1 = i;
            }
            if(i > 1 and a[i] != 1){
                if(sm > now) id = i, sm = now;
            }
        }
        if(if_end) continue;
 
        int y = sm - sm % 10;//y为个位数不为1的最小二位数的十位数
        if(_1 < y and _1) sm = _1, id = id_1;//此时最优二位数为最小的个位数为1的二位数
 
        int ans = sm;
        for(int i=1; i<=n; i++){ //1之外的加和
            if(i == id or i == id - 1 or a[i] == 1) continue;
            ans += a[i];
        }
 
        printf("%d\n", ans);
 
    }
 
    return 0;
}
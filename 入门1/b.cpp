#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define MOD 1000000007 
#define do double

int gcd(int a, int b) { 
    return b == 0 ? abs(a) : gcd(b, a % b);
}


void solve() {
    int s,v,cnt,h,sum;
    cin>>s>>v;//输入
    if(s%v==0) cnt=s/v;//除法处理
    else cnt=s/v+1;
    cnt+=10;
    if(cnt<=60)
    {
        if(60-cnt<10) cout<<"07:0"<<60-cnt;
        else cout<<"07:"<<60-cnt;
    }
    else
    {
        if(cnt%60==0) h=cnt/60;//小时数+除法处理
        else h=cnt/60+1;
        if((8-h)<0)//继续特判，超过8个小时
        {
            if(h%8==0) sum=h/8;
            else sum=h/8+1;
            if(60-cnt%60==60) cout<<((8+sum*24)-h)%24+1<<":00";//判断整点
            else
            {
                if(60-(cnt%60)<10) cout<<((8+sum*24)-h)%24<<":0"<<60-(cnt%60);//判断小于10分钟的情况
                else cout<<((8+sum*24)-h)%24<<":"<<60-(cnt%60);
            }
        }
        else//否则，就是8个小时以内的情况
        {
            if(60-(cnt%60)<10) cout<<"0"<<8-h<<":0"<<60-(cnt%60);
            else cout<<"0"<<8-h<<":"<<60-(cnt%60);
        }
    }

}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    solve(); 

    return 0; 
}

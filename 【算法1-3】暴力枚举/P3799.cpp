#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5*1e3+500,mod=1e9+7;
int num[maxn],n,Max=-1,Min=0x3f3f,ans=0;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        num[a]++;
        Max=max(Max,a);Min=min(Min,a);
    }
    for(int i=Min+1;i<=Max;i++)
    {
        if(num[i]>=2)
        {
            for(int j=Min;j<=i/2;j++)
            {
                if(j!=i-j)
                    ans+=num[i]*(num[i]-1)*num[j]*num[i-j]/2%mod;
                else if(num[j]>=2&&j*2==i)
                    ans+=num[i]*(num[i]-1)*num[i/2]*(num[i/2]-1)/4%mod;
            }
            ans%=mod;
        }
    }
    cout<<ans;
}
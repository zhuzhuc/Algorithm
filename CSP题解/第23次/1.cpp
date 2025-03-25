#include<iostream>

using namespace std;

const int N=110;

int n;
int b[N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];

    int max=0,min=0;
    for(int i=1;i<=n;i++)
    {
        max+=b[i];
        if(b[i]>b[i-1]) min+=b[i];
    }
    cout << max << "\n" << min << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        /* code */cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i =0, j = n  -1, count = 0;
    while(i < j){
        int sum = v[i] + v[j];
        if(sum == 0){
            count++;
            i++;
            j--;
        }else if(sum < 0){
            i++;
        }else{
            j--;
        }
    }
    cout << count << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long M, N;
    cin >> M >> N;
    
    vector<int> digit_count(10, 0);
    
    for (long long i = M; i <= N; ++i) {
        long long num = i;
        while (num > 0) {
            int digit = num % 10;
            digit_count[digit]++;
            num /= 10;
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        if (i != 0) cout << " ";
        cout << digit_count[i];
    }
    cout << endl;
    
    return 0;
}

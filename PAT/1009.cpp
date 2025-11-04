#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int k1, k2;
    
    cin >> k1;
    vector<pair<int, double>> poly1(k1);
    for (int i = 0; i < k1; i++) {
        cin >> poly1[i].first >> poly1[i].second;
    }
    
    cin >> k2;
    vector<pair<int, double>> poly2(k2);
    for (int i = 0; i < k2; i++) {
        cin >> poly2[i].first >> poly2[i].second;
    }

    vector<double> result(2001, 0.0);
    
    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            int exp = poly1[i].first + poly2[j].first;
            double coeff = poly1[i].second * poly2[j].second;
            result[exp] += coeff;
        }
    }
    
    int count = 0;
    for (int i = 2000; i >= 0; i--) {
        if (abs(result[i]) > 1e-6) {  
            count++;
        }
    }

    cout << count;
    for (int i = 2000; i >= 0; i--) {
        if (abs(result[i]) > 1e-6) {
            cout << " " << i << " " << fixed << setprecision(1) << result[i];
        }
    }
    cout << endl;
    
    return 0;
}
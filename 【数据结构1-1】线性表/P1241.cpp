#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    int n = a.length();


    stack<pair<char, int>> st;
    string res = a;  
    for (int i = 0; i < n; i++) {
        if (a[i] == '(' || a[i] == '[') {

            st.push({a[i], i});
        } else if (a[i] == ')') {
 
            if (!st.empty() && st.top().first == '(') {
                
                st.pop();
            } else {
             
                res.insert(res.begin() + i, '(');
                i++;  
            }
        } else if (a[i] == ']') {

            if (!st.empty() && st.top().first == '[') {
            
                st.pop();
            } else {
               
                res.insert(res.begin() + i, '[');
                i++;  
            }
        }
    }


    while (!st.empty()) {
        char leftBracket = st.top().first;
        int pos = st.top().second;
        st.pop();

        if (leftBracket == '(') {
            res.insert(res.begin() + pos + 1, ')');
        } else if (leftBracket == '[') {
            res.insert(res.begin() + pos + 1, ']');
        }
    }

    cout << res << endl;

    return 0;
}

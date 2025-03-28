#include<iostream>
using namespace std;
 
int main(){
    int size, count;
    cin >> size >> count;
    for(int i = 0; i < count; i++) {
        int x, y;
        cin >> x >> y;
        string keys;
        cin >> keys;
        for(char key : keys) {
            switch (key) {
                case 'f': {
                    if(y + 1 <= size) {
                        y += 1;
                    }
                    break;
                }
                case 'r': {
                    if(x + 1 <= size){
                        x += 1;
                    }
                    break;
                }
                case 'b': {
                    if( y - 1 > 0){
                        y -= 1;
                    }
                    break;
                }
                case 'l': {
                    if(x - 1 > 0) {
                        x -=1;
                    }
                    break;
                }
            }
            cout << x << " " << y;
            cout << endl;
        }
    }
    return 0;
}
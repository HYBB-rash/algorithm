#include <iostream>
#include <algorithm>

using namespace std;

int main () {

    int n, d2 = 0, d5 = 0;
    cin >> n;
    int res = 1;
    for (int i = 0; i < n; i ++) {
        int x = i + 1;
        while (x % 2 == 0) x /= 2, d2 ++;
        while (x % 5 == 0) x /= 5, d5 ++;
        res = res * x % 10;
        
    }
    for (int i = 0; i < d2 - d5; i ++) res = res * 2 % 10;
    cout << res << endl;
    return 0;
}
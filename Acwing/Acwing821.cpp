#include<iostream>
using namespace std;

const int N = 100100;

int main () {

    int f[N];
    int n = 0;
    cin >> n;
    f[0] = 0, f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i ++) {
        f[i] = (f[i - 1] + f[i - 2]);
    }
    cout << f[n] << endl;
    return 0;
}
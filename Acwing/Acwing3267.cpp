#include <iostream>

using namespace std;

int light[4];

int main () {

    cin >> light[1] >> light[2] >> light[3];
    int n;
    cin >> n ;
    int time = 0;
    for (int i = 0; i < n; i ++) {
        int k , t;
        cin >> k >> t;
        if (k == 0) time += t;
        else if (k == 1) time += t;
        else if (k == 2) time += t + light[1];
    }
    cout << time << endl;
    return 0;
}
#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N];
int nums[N];
int n, m;

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> nums[i];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (j < nums[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - nums[i]] + 1);
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << f[n][m] ;
    return 0;
}
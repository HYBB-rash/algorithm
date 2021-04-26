#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    vector<vector<int>> f(n + 1, vector<int>(2, -1e8));
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        f[i][0] = max(f[i - 1][1] + nums[i - 1], f[i - 1][0]);
        f[i][1] = max(f[i - 1][0] - nums[i - 1], f[i - 1][1]);
    }
    cout << max(f[n][0], f[n][1]);
    return 0;
}
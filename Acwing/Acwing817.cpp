#include <iostream>
#include <unordered_map>

using namespace std;

int main () {
    unordered_map<int, bool> memo;
    int n; cin >> n;
    int res = 0;
    for (int i = 0; i < n; i ++) {
        int tmp; cin >> tmp;
        if (!memo[tmp]) {
            memo[tmp] = true;
            res ++;
        }
    }
    cout << res;
    return 0;
}
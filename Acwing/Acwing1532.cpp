
/** 
 * *  @File        :   Acwing1532.cpp
 * *  @Time        :   2021/05/10 18:57:39
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1532
**/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100100;

int coins[N];

int n = 0, m = 0;

int bin_search(int l, int r, int target) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (coins[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + n);
    for (int i = 0; i < n; i++) {
        int one = coins[i];
        int another = m - one;
        int res_find = bin_search(0, n - 1, another);
        if (another == coins[res_find] && i != res_find) {
            cout << one << " " << another;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
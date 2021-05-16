
/** 
 * *  @File        :   Acwing1227.cpp
 * *  @Time        :   2021/05/09 17:32:26
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1227
**/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

const int N = 100100;
vector<pii> choco;
int n, k, min_size = 0x3f3f3f3f;

int compute_choco(int size) {
    int res = 0;
    for (auto shape : choco) {
        res += (shape.first / size) * (shape.second / size);
    }
    return res;
}

int main() {
    cin >> n >> k;
    choco.resize(n);
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        choco.push_back({h, w});
    }
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = l + ((r - l + 1) >> 1);
        int split = compute_choco(mid);
        if (split >= k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}
/** 
 * *  @File        :   Acwing1589.cpp
 * *  @Time        :   2021/04/27 09:47:12
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   每日一题
**/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

int n = 0;
PII tree[N];
vector<int> val(N, -1), ans(N, -1);
queue<int> q;
int p = 0;

void dfs(int root) {
    if (root == -1) return;
    dfs(tree[root].first);
    ans[root] = val[p ++];
    dfs(tree[root].second);
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int a, b; cin >> a >> b;
        tree[i] = {a, b};
    }
    for (int i = 0; i < n; i ++) {
        int node = 0;
        cin >> val[i];
    }
    sort(val.begin(), val.begin() + n);
    dfs(0);
    q.push(0);
    while (q.size()) {
        int t = q.front();
        q.pop();
        cout << ans[t] << " ";
        int left = tree[t].first, right = tree[t].second;
        if (left != -1) q.push(left);
        if (right != -1) q.push(right);
    }
    return 0;
}

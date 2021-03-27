#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 40;

int inorder[N], postorder[N];
unordered_map<int, int> l, r, pos;
int q[N];

int build(int l_i, int r_i, int l_p, int r_p) {
    int root = postorder[r_p];
    int k = pos[root];
    if (l_i < k) l[root] = build(l_i, k - 1, l_p, l_p + (k - 1 - l_i));
    if (k < r_i) r[root] = build(k + 1, r_i, l_p + k - l_i, r_p - 1);
    return root;
}

void bfs(int root, int n) {
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt) {
        int t = q[hh ++];
        if (l.count(t)) q[++ tt] = l[t];
        if (r.count(t)) q[++ tt] = r[t];
    }
    cout << q[0];
    for (int i = 1; i < n; i ++) cout << " " << q[i];
    
}

int main () {
    int n = 0; cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root, n);
    return 0;
}
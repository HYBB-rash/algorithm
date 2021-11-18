#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> tmp;
vector<vector<int>> ans;

int n, m;

void dfs (int start, int step) {

    if (n + step - start < m) return ;

    if (step == m + 1) {
        ans.push_back(tmp);
        return ;
    }
    for (int i = start; i <= n; i ++) {
        tmp.push_back(i);
        dfs(i + 1, step + 1);
        tmp.pop_back();
    }
}

int main () {
    cin >> n >> m;
    dfs(1, 1);
    for (auto a : ans) {
        for (auto v : a) cout << v << " ";
        cout << endl;
    }
    return 0;
}

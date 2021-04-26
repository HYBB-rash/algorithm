#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0;
int max_ans = 0;
vector<int> emp(100100), tmp;
unordered_map<int, int> rel;

void dfs(int n, int cur) {
    if (tmp.size()) {
        int cnt = 0;
        for (auto a : tmp) {
            int boss = rel[a];
            for (auto a : tmp)
                if (a == boss){
                    cnt -= emp[a];
                }
            cnt += emp[a];
        }
        max_ans = max(max_ans, cnt);
    }
    for (int i = cur; i <= n; i ++) {
        tmp.push_back(i);
        dfs(n, i + 1);
        tmp.pop_back();
    }
}

int main () {

    
    cin >> n;
    
    for (int i = 0; i < n; i ++) cin >> emp[i + 1];
    for (int i = 1; i < n; i ++) {
        int a, b; cin >> a >> b;
        rel[a] = b;
    }
    dfs(n, 1);
    cout << max_ans;
    return 0;
}
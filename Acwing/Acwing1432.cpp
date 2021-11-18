
/** 
 * *  @File        :   Acwing1432.cpp
 * *  @Time        :   2021/05/12 17:17:52
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1432
**/
#include <vector>
#include <iostream>

using namespace std;

const int N = 1010;

bool left_line[N], right_line[N], x_header[N];
vector<int> tmp;
int cnt_sum = 0;

void dfs(int n, int y) {
    if (n < y) {
        cnt_sum ++;
        if (cnt_sum <= 3) {
            for (auto &num : tmp) cout << num << " ";
            cout << endl;
        } 
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!x_header[i] && !left_line[i + y] && !right_line[i - y + n]) {
            x_header[i] = right_line[i - y + n] = left_line[i + y] = true;
            tmp.push_back(i);
            dfs(n, y + 1);
            tmp.pop_back();
            x_header[i] = left_line[i + y] = right_line[i - y + n] = false;

        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    dfs(n, 1);
    cout << cnt_sum << endl;
    return 0;
}
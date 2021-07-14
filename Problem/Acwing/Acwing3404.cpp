
/**
 * *  @File        :   Acwing3404.cpp
 * *  @Time        :   2021/05/18 20:12:50
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3404
 **/

#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 310;
int reader[N];

int main() {
    unordered_map<int, int> cnt;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> reader[i];
        cnt[reader[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int res = cnt[reader[i]] - 1;
        if (res == 0)
            cout << "BeiJu" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
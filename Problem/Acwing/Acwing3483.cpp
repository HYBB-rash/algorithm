/**
 * *  @File        :   Acwing3483.cpp
 * *  @Time        :   2021/05/19 22:33:55
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 3483
 **/

#include <iostream>
#include <string>

using namespace std;

string dfs_mi(int x) {
    if (x == 0) return "0";
    string res = "";
    for (int i = 31; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (u) {
            if (i != 1)
                res += "2(" + dfs_mi(i) + ")+";
            else
                res += "2+";
        }
    }
    return res.substr(0, res.size() - 1);
}

int main() {
    int n;
    while (cin >> n) {
        cout << dfs_mi(n) << endl;
    }
    return 0;
}
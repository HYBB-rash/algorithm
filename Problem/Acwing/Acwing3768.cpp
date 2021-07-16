
/*
 *  @File        :   Acwing3768.cpp
 *  @Time        :   2021/07/16 12:41:11
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3768. 字符串删减 Acwing 每日一题
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    string str;
    cin >> n >> str;
    str.push_back('c');

    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (str[i] == 'x') {
            if (i - j < 2)
                continue;
            else
                res++;
        } else {
            j = i + 1;
        }
    }

    cout << res;

    return 0;
}
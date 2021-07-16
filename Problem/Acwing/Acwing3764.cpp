
/*
 *  @File        :   Acwing3764.cpp
 *  @Time        :   2021/07/16 12:00:50
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3764. 三元数异或 Acwing 每日一题
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {

    int T = 0;
    cin >> T;
    while (T--) {

        int n = 0;
        string str;
        cin >> n >> str;

        string a, b;
        int greator = 0;

        for (auto val : str) {
            if (greator == 0) {
                if (val == '2')
                    a.push_back('1'), b.push_back('1');
                else if (val == '0')
                    a.push_back('0'), b.push_back('0');
                else if (val == '1') {
                    a.push_back('1'), b.push_back('0');
                    greator = 1;
                }
            } else if (greator == 1) {
                if (val == '2')
                    a.push_back('0'), b.push_back('2');
                else if (val == '1')
                    a.push_back('0'), b.push_back('1');
                else if (val == '0')
                    a.push_back('0'), b.push_back('0');
            }
        }

        cout << a << "\n" << b << "\n";
    }
    return 0;
}
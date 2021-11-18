
/** 
 * *  @File        :   Acwing3554.cpp
 * *  @Time        :   2021/05/28 14:28:28
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   Acwing 3554 每日一题
**/

#include <iostream>
#include <algorithm>

using namespace std;

string add(string a, int addition) {
    int tmp = addition;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        tmp += a[i] - '0';
        a[i] = (tmp % 2) + '0';
        tmp /= 2;
    }
    for (; tmp; tmp /= 2) a.push_back((tmp % 2) + '0');
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        cout << add(a, 1) << endl << add(a, 3) << endl;
    }
    return 0;
}
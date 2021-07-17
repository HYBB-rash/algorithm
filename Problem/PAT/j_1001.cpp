
/*
 *  @File        :   j_1001.cpp
 *  @Time        :   2021/07/17 08:39:43
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   甲级  1001 A + B format
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    long long a, b, c;
    cin >> a >> b;
    c = a + b;

    string c_str = to_string(c), res;
    reverse(c_str.begin(), c_str.end());
    for (int i = 0, j = 0; i < c_str.size(); i++) {
        if (i - j > 2) {
            if (c_str[i] != '-') res.push_back(',');
            j = i;
        }
        res.push_back(c_str[i]);
    }
    reverse(res.begin(), res.end());

    cout << res << endl;
    return 0;
}

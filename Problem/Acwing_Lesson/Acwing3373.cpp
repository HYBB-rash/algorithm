
/*
 *  @File        :   Acwing3373.cpp
 *  @Time        :   2021/07/14 10:31:51
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 进制转换1
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {

    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--, r %= b) {
        r = r * 10 + A[i];
        C.push_back(r / b);
    }
    reverse(C.begin(), C.end());
    while (C.size() && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    string str;

    while (cin >> str) {

        if (str == "0") {
            cout << "0\n";
            continue;
        }

        vector<int> A;
        for (int i = str.size() - 1; i >= 0; i--) { A.push_back(str[i] - '0'); }

        string res;
        while (A.size()) {
            int r = 0;
            A = div(A, 2, r);
            res += to_string(r);
        }

        reverse(res.begin(), res.end());
        cout << res << "\n";
    }

    return 0;
}
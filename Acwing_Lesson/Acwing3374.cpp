
/*
 *  @File        :   Acwing3374.cpp
 *  @Time        :   2021/07/14 10:54:21
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 进制转换2
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;

vector<int> div(vector<int> &A, int b, int &r) {

    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--, r %= b) {
        r = r * n + A[i];
        C.push_back(r / b);
    }
    reverse(C.begin(), C.end());
    while (C.size() && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    cin >> n >> m;

    string str;
    cin >> str;

    if (str == "0") {
        cout << "0\n";
        return 0;
    }

    vector<int> A;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] >= 'A')
            A.push_back(str[i] - 'A' + 10);
        else
            A.push_back(str[i] - '0');
    }

    string res;
    while (A.size()) {
        int r = 0;
        A = div(A, m, r);
        if (r < 10)
            res += to_string(r);
        else
            res.push_back(('a' + (r - 10)));
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
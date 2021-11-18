
/*
 *  @File        :   Acwing794.cpp
 *  @Time        :   2021/07/11 17:46:23
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   高精度除法
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> divi(vector<int> &A, int b, int &r) {
    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--, r %= b) {
        r = r * 10 + A[i];
        C.push_back(r / b);
    }

    reverse(C.begin(), C.end());
    while (C.size() != 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    int r = 0;
    auto C = divi(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << "\n" << r;

    return 0;
}
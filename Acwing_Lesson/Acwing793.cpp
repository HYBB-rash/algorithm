
/* 
 *  @File        :   Acwing793.cpp
 *  @Time        :   2021/07/11 17:33:22
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   高精度乘法
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 100100;

vector<int> mul(vector<int> &A, int b) {

    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || t; i++, t /= 10) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    return 0;
    
}

/*
 *  @File        :   Acwing792.cpp
 *  @Time        :   2021/07/11 17:17:27
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   高精度减法模板题
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100100;

bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i]) return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size(); i++, t < 0 ? t = 1 : t = 0) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
    }

    while (C.size() != 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    bool cmp_res = cmp(A, B);
    auto C = cmp_res ? sub(A, B) : sub(B, A);

    cmp_res ? cout << "" : cout << "-";
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}
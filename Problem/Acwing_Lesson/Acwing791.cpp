
/*
 *  @File        :   Acwing791.cpp
 *  @Time        :   2021/07/11 17:10:21
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 高精度加法 模板
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 100100;

vector<int> sum(vector<int> &A, vector<int> &B) {
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++, t /= 10) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
    }

    if (t) C.push_back(t);

    return C;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = sum(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}
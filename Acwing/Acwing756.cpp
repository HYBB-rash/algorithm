
/** 
 * *  @File        :   Acwing756.cpp
 * *  @Time        :   2021/05/12 08:32:54
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 756
**/

#include <iostream>
using namespace std;

int main() {
    
    int query = 0;
    while (true) {
        cin >> query;
        if (query == 0) break;
        for (int i = 0; i < query; i++) {
            for (int j = 0; j < query; j++) {
                cout << abs(i - j) + 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
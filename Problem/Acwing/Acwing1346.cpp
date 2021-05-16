
/**
 * *  @File        :   Acwing1346.cpp
 * *  @Time        :   2021/05/09 13:51:13
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1346题
 **/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char num_table[30] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string convert_to_B(int x, int B) {
    string res;
    while (x) {
        int tail = x % B;
        res.push_back(num_table[tail]);
        x /= B;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int B = 0;
    cin >> B;
    for (int i = 1; i <= 300; i++) {
        int square = i * i;
        string convert = convert_to_B(square, B);
        bool flag = true;
        for (int j = 0; j < convert.size() >> 1; j++) {
            int h = j, t = convert.size() - 1 - j;
            if (convert[h] != convert[t]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << i << " " << convert << endl;
    }
    return 0;
}

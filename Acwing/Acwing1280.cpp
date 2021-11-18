
/** 
 * *  @File        :   Acwing1280.cpp
 * *  @Time        :   2021/05/10 11:23:02
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   acwing 1280
**/

#include <string>
#include <iostream>

using namespace std;

void reverse(string &str, int index) {
    if (str[index] == 'o')
        str[index] = '*';
    else if (str[index] == '*')
        str[index] = 'o';
    if (index + 1 < str.size()) {
        index++;
        if (str[index] == 'o')
            str[index] = '*';
        else if (str[index] == '*')
            str[index] = 'o';
    }
}

int main() {
    string start, end;
    cin >> start >> end;
    int res = 0;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] != end[i]) {
            reverse(start, i);
            res++;
        }
    }
    cout << res;
    return 0;
}
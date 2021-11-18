
/**
 * *  @File        :   Acwing78.cpp
 * *  @Time        :   2021/05/03 09:07:40
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   每日一题
 **/

class Solution {
public:
  string leftRotateString(string str, int n) {
    return str.substr(n, str.size() - n) + str.substr(0, n);
  }
};
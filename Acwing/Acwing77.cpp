#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s == "") return s;
        s += ' ';
        vector<string> ans;
        for (int p = 0, q = 1; q < s.size(); q ++) {
            if (s[q] == ' ') {
                ans.push_back(s.substr(p, q - p));
                p = q + 1;
            }
        }
        string res = ans[ans.size() - 1];
        for (int i = ans.size() - 2; i >= 0; i --) res += " " + ans[i];
        return res;
    }
};
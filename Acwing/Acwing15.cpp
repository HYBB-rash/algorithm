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
    bool searchArray(vector<vector<int>> array, int target) {
        if (array.size() == 0 || array[0].size() == 0) return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            if (array[i][j] > target) j --;
            else if (array[i][j] < target) i ++;
            else return true;
        }
        return false;
    }
};
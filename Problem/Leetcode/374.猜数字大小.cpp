/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int guess(int num);

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
    int guessNumber(int n) {
        long long left = 1, right = n;
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (guess(mid) <= 0)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

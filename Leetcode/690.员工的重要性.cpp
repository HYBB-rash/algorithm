/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <vector>

using namespace std;
class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    int import_ans = 0;
    for (auto e : employees) {
      if (e->id == id) {
        import_ans += e->importance;
        for (auto i : e->subordinates) {
          import_ans += getImportance(employees, i);
        }
        break;
      }
    }
    return import_ans;
  }
};
// @lc code=end

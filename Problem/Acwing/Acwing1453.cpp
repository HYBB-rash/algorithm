#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
    string nums;
    int k;
    cin >> nums >> k;
    if (k >= nums.size()) {
        cout << 0 << endl;
        return 0;
    }
    while (k --) {
        string min = nums.substr(1, nums.size() - 1);
        for (int i = 1; i < nums.size(); i ++) {
            string tmp = nums;
            tmp.erase(tmp.begin() + i);
            if (tmp < min) min = tmp;
        }
        for (int i = 0; i < min.size() - 1; i ++) 
            if(min[i] != '0'){
                min = min.substr(i, min.size() - i);
                break;
            }
        nums = min;
    }
    cout << nums;
    return 0;
}
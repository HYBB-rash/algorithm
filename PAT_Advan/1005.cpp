#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, string> table = {
    { '1', "one" },  { '2', "two" }, { '3', "three" }, { '4', "four" },
    { '5', "five" }, { '6', "six" }, { '7', "seven" }, { '8', "eight" },
    { '9', "nine" }, { '0', "zero" } };

int main() {
    string nums;
    cin >> nums;
    int sum = 0;
    for ( auto &c : nums ) {
        sum += c - '0';
    }
    string convert = to_string( sum );

    int cnt = 0;
    for ( auto &c : convert ) {
        if (cnt != 0) cout << " ";
        cout << table[ c ];
        cnt ++;
    }
    return 0;

}
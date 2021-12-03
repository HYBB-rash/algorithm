
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main () {
    int a, b;
    cin >> a >> b;

    int c = a + b;
    
    int abs_c = abs(c);
    string handle_c = to_string(abs_c);
    string ans;
    for (int i = handle_c.size() - 1, ans_count = 0; i >= 0; i --) {
        ans.push_back(handle_c[i]), ans_count ++;
        handle_c.pop_back();
        if (ans_count % 3 == 0 && handle_c.size() != 0) ans.push_back(',');
    }
    reverse(ans.begin(), ans.end());

    if (c < 0) cout << "-";
    cout << ans;
    return 0;
}
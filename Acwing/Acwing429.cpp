
/** 
 * *  @File        :   Acwing429.cpp
 * *  @Time        :   2021/05/10 09:42:14
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   Acwing 429
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class stu {
   public:
    int id;
    int chin;
    int math;
    int eng;
    int total;
};

bool cmp(stu a, stu b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.chin != b.chin) return a.chin > b.chin;
    return a.id < b.id;
}

int main() {

    int n = 0;

    cin >> n;
    vector<stu> stu_list(n);
    for (int i = 0; i < n; i++) {
        cin >> stu_list[i].chin >> stu_list[i].math >> stu_list[i].eng;
        stu_list[i].total =
            stu_list[i].chin + stu_list[i].math + stu_list[i].eng;
        stu_list[i].id = i + 1;
    }
    sort(stu_list.begin(), stu_list.end(), cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu_list[i].id << " " << stu_list[i].total << endl;
    }
    return 0;
}
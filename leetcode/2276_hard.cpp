#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional> 
#include<algorithm>
#include<numeric>
#include<bitset>
#include<set>
#include<bit>
using namespace std;

class CountIntervals {
public:
    vector<pair<int, int>> ans;
    int cnt = 0;
    CountIntervals() {

    }

    void add(int left, int right) {
        auto pn = upper_bound(ans.begin(), ans.end(), make_pair(0, left - 1), [](auto& a, auto& b) {
            return a.second <= b.second;
            });
        auto nt = upper_bound(ans.begin(), ans.end(), make_pair(right + 1, 0), [](auto& a, auto& b) {
            return a.first < b.first;
            });
        if (pn == ans.end()) {
            ans.push_back({ left,right });
            cnt += right - left + 1;
            return;
        }
        if (nt == ans.begin()) {
            ans.insert(ans.begin(), { left,right });
            cnt += right - left + 1;
            return;
        }
        if (pn == nt) {
            ans.insert(pn, { left,right });
            cnt += right - left + 1;
            return;
        }
        for (auto t = pn; t != nt; t++) {
            cnt -= t->second - t->first + 1;
        }
        (*pn).first = min((*pn).first, left);
        (*pn).second = max((*(nt - 1)).second, right);
        cnt += (*pn).second - (*pn).first + 1;
        auto x = pn + 1;
        for (auto y = nt; x != ans.end() && y != ans.end(); x++, y++) {
            x->first = y->first;
            x->second = y->second;
        }
        while (x != ans.end()) {
            x = ans.erase(x);
        }
    }

    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
int main() {
    CountIntervals entity;
    entity.add(2, 3);
	entity.add(7, 10);
    cout << entity.count() << endl;
	entity.add(5, 8);
    cout << entity.count() << endl;
}
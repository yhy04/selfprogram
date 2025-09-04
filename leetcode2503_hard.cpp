#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional> 
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        queue<pii> q1, q2;
        int ans = 0;
        int cnt1 = n - 1, cnt2 = n - 1;
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find;
        find = [&find, &parent](int x) {
            // if(parent[a]==a)return a;
            // return find(parent[a]);
            return parent[x] == x ? x : parent[x] = find(parent[x]);
            };
        for (auto& _ : edges) {
            if (_[0] == 1)q1.push(make_pair(_[1], _[2]));
            else if (_[0] == 2)q2.push(make_pair(_[1], _[2]));
            else {
                int x = find(_[1]), y = find(_[2]);
                if (x == y)ans++;
                else {
                    if (x > y)swap(x, y);
                    parent[y] = x;
                    cnt1--;
                    cnt2--;
                }
            }
        }
        vector<int> temp = parent;
        while (!q1.empty()) {
            auto [fi, se] = q1.front();
            q1.pop();
            int x = find(fi), y = find(se);
            if (x == y)ans++;
            else {
                if (x > y)swap(x, y);
                parent[y] = x;
                cnt1--;
            }
        }
        parent = temp;
        while (!q2.empty()) {
            auto [fi, se] = q2.front();
            q2.pop();
            int x = find(fi), y = find(se);
            if (x == y)ans++;
            else {
                if (x > y)swap(x, y);
                parent[y] = x;
                cnt2--;
            }
        }
        if (cnt1 == 0 && cnt2 == 0)return ans;
        return -1;
    }
};
int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges{ {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4 } };
    cout << sol.maxNumEdgesToRemove(n, edges);
}
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

class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        if (edges.empty()) {
            sort(score.begin(), score.end());
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += score[i] * (i + 1);
            }
            return ans;
        }
        vector<int> lock(n, 0);
        for (auto& _ : edges) {
            lock[_[1]] += (1 << _[0]);
        }
        int temp = 0;
        int ans = 0;
        int t = 0;
        vector<int> memo(1 << n, -1);
        function<void(int)> dfs;
        dfs = [&](int key) {
            if (temp <= memo[key])return;
            memo[key] = temp;
            for (int i = 0; i < n; i++) {
                if ((key >> i & 1) == 0 && (lock[i] & key) == lock[i]) {
                    temp += score[i] * ++t;
                    dfs(key + (1 << i));
                    temp -= score[i] * t--;
                }
            }
            ans = max(ans, temp);
            };
        dfs(0);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 13;
    vector<vector<int>> edges = { {0,4},{6,11},{1,10},{7,11},{3,11} };
    vector<int> score = { 478,42107,68594,86478,59141,36187,52400,52539,8636,23897,45518,64889,37298 };
    cout << sol.maxProfit(n, edges, score);
}
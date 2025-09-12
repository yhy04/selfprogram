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
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++) {
            int& x = group[i], & y = profit[i];
            for (int v = n - x; v >= 0; v--) {
                for (int u = minProfit; u >= 0; u--) {
                    int _u = min(u + y, minProfit);
                    dp[v + x][_u] = (dp[v + x][_u] + dp[v][u]) % mod;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[i][minProfit]) % mod;
        }
        return ans;
    }
};

int main() {
    Solution sol; 
    int n = 10;
	int minProfit = 5;
	vector<int> group = { 2,3,5 };
	vector<int> profit = { 6,7,8 };
    cout << sol.profitableSchemes(n, minProfit, group, profit) << endl;
}
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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        int ans = 0;
        function<int(int, int)> dfs;
        vector<vector<int>> direction{ {0,1},{0,-1},{1,0},{-1,0} };
        dfs = [&](int x, int y) {
            if (dp[x][y] != 1)return dp[x][y];
            int t = 0;
            for (auto& _ : direction) {
                int n_x = x + _[0], n_y = y + _[1];
                if (n_x >= 0 && n_x < m && n_y >= 0 && n_y<n && matrix[n_x][n_y]>matrix[x][y]) {
                    t = max(t, dfs(n_x, n_y));
                }
            }
            dp[x][y] = max(dp[x][y], t + 1);
            return t + 1;
            };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol; 
    vector<vector<int>> matrix{ { 9,9,4 },{6,6,8} ,{2,1,1} };
	cout << sol.longestIncreasingPath(matrix) << endl;
}
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> l(n + 1), r(n + 1);
        int min_t = prices[0];
        for (int i = 0; i < n; i++) {
            l[i + 1] = max(l[i], prices[i] - min_t);
            min_t = min(prices[i], min_t);
        }
        int max_t = prices.back();
        for (int i = n - 1; i >= 0; i--) {
            r[i] = max(r[i + 1], max_t - prices[i]);
            max_t = max(prices[i], max_t);
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, l[i] + r[i]);
        }
        return ans;
    }
};

int main() {
	Solution sol; 
    vector<int> prices = { 3,3,5,0,0,3,1,4 };
	cout << sol.maxProfit(prices) << endl;
}
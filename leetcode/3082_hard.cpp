#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
#include<algorithm>
#include<assert.h>
using namespace std;


class Solution {
public:
    int mod = 1e9 + 7;
    long long q(int n) {
        long long tot = 1;
        long long temp = 2;
        while (n) {
            if (n & 1)tot = tot * temp % mod;
            temp = temp * temp % mod;
            n >>= 1;
        }
        return tot;
    }
    int sumOfPower(vector<int>& nums, int k) {
        vector<map<int, int>> res(k + 1);
        res[0][0] = 1;
        for (auto& _ : nums) {
            for (int i = k; i >= _; i--) {
                for (auto& [key, val] : res[i - _]) {
                    res[i][key + 1] += val;
                    res[i][key + 1] %= mod;
                }
            }
        }
        long long ans = 0;
        int s = nums.size();
        for (auto& [key, val] : res[k]) {
            ans = (ans + q(s - key) * val) % mod;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = { 2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1 };
	int k = 49;
    int ans = sol.sumOfPower(nums, k);
	cout << ans << endl;
    assert(ans == 999634217);
	return 0;
}
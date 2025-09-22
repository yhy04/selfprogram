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
    int sumSubseqWidths(vector<int>& nums) {
        int a = 0, mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)a = (a * 2 + nums[n - i - 1] - nums[i]) % mod;
        return (a + mod) % mod;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 5,69,89,92,31,16,25,45,63,40,16,56,24,40,75,82,40,12,50,62,92,44,67,38,92,22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89,4,16,94,16,77,92,9,30,13 };
    cout << sol.sumSubseqWidths(nums);
}
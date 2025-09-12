#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional> 
#include<algorithm>
#include<numeric>
#include<bitset>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> mset{ 2,3,5,7,11,13,17,19,23,29 };
    bitset<10> res;
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        int po2 = 0;
        for (int i = 0; i < n; i++) {
            int& _ = nums[i];
            if (_ == 1) { po2++; continue; }
            res.reset();
            for (int j = 0; j < 10; j++) {
                if (_ % mset[j] == 0) {
                    _ /= mset[j];
                    res.set(j);
                }
                if (_ % mset[j] == 0)break;
                if (_ == 1) {
                    int t = res.to_ulong();
                    if (mp[t] == 0)ans.push_back(t);
                    mp[t]++;
                    break;
                }
            }
        }
        long long answer = -1;
        function<void(int, int, long long)> dfs;
        dfs = [&](int index, int curr, long long cnt) {
            if (index == ans.size()) {
                answer = (answer + cnt) % mod;
                return;
            }
            dfs(index + 1, curr, cnt);
            int a = (ans[index] ^ curr), b = (ans[index] + curr);
            if (a == b)dfs(index + 1, a, (cnt * mp[ans[index]]) % mod);
            };
        dfs(0, 0, 1);
        // while(po2--)answer=answer*2%mod;
        answer = answer * q_pow(po2) % mod;
        return answer;
    }
    int q_pow(int t) {
        long long sum = 1;
        long long curr = 2;
        while (t) {
            if (t & 1)sum = (sum * curr) % mod;
            curr = (curr * curr) % mod;
            t >>= 1;
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 2, 17, 8, 1, 30, 26, 6, 2, 5, 10, 28, 15, 11, 15, 25, 24, 24, 13, 23, 27, 23, 24, 20, 1, 25, 1, 21, 23, 10, 21, 12, 14, 13, 26, 18, 21, 12, 14, 26, 8, 16, 11, 21, 8, 9, 5, 3, 25, 2, 14, 23, 23, 16, 8, 19, 5, 9, 26, 17, 15, 15, 17, 9, 18, 25, 14, 10, 30, 20, 21, 23, 19, 11, 21, 25, 8, 25, 1, 5, 17, 30, 4, 6, 2, 22, 18, 10, 18, 30, 12, 8, 6, 18, 23, 22, 4, 23, 27, 23, 27, 19, 11, 25, 20, 30, 16, 29, 1, 22, 26, 19, 2, 13, 8, 19, 23, 3, 27, 20, 18, 11, 2, 23, 3, 5, 16, 3, 23, 22, 7, 24, 25, 16, 13, 5, 17, 24, 14, 10, 19, 11, 29, 8, 16, 5, 14, 8, 26, 15, 7, 3, 11, 19, 12, 27, 24, 1, 6, 4, 16, 8, 7, 25, 12, 21, 20, 15, 25, 29, 6, 25, 5, 28, 10, 3, 27, 19, 12, 1, 13, 22, 5, 13, 5, 18, 6, 2, 10, 24, 7, 14, 7, 26, 10, 4, 17, 4, 24, 6, 5, 5, 1, 7, 5, 14, 18, 23, 10, 20, 7, 2, 28, 15, 30, 16, 8, 24, 11, 2, 4, 13, 10, 29, 11, 20, 8, 3, 17, 8, 4, 26, 26, 5, 16, 30, 7, 7, 22, 22, 14, 3, 29, 20, 17, 27, 2, 20, 23, 1, 7, 4, 16, 9, 15, 15, 23, 8, 11, 14, 18, 12, 3, 26, 27, 13, 17, 20, 27, 11, 5, 14, 12, 18, 19, 21, 20, 4, 27, 5, 17, 19, 5, 1, 18, 22, 16, 8, 29, 21, 3, 20, 17, 3, 15, 29, 4, 27, 2, 10 };
	cout<<sol.numberOfGoodSubsets(nums);
}
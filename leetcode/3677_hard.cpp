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
    int f(int m) {
        int ans = 0;
        for (int i = m; i > 0; i--) {
            ans += (1 << ((i - 1) / 2));
        }
        return ans + 1;
    }
    int countBinaryPalindromes(long long n) {
        if (n <= 1)return n + 1;
        vector<int> res;
        while (n) {
            res.push_back(n & 1);
            n >>= 1;
        }
        reverse(res.begin(), res.end());
        int m = res.size();
        long long ans = f(m - 1);
        vector<int> dp((m + 1) / 2); dp[0] = 1;
        bool flag = true;
        for (int i = 1; i < (m + 1) / 2; i++) {
            dp[i] = dp[i - 1] * 2;
            if (res[i] == 0)dp[i]--;
        }
        for (int i = (m - 1) / 2, j = m / 2; i >= 0; i--, j++) {
            if (res[i] > res[j]) { ans--; break; }
            else if (res[i] < res[j]) { break; }
        }
        return ans + dp.back();
    }
};

int main() {
    Solution sol; 
    int n = 9;
    cout << sol.countBinaryPalindromes(n) << endl;
}
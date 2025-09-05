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
    int count(string& s) {
        int mod = 1e9 + 7;
        vector<int> cnt(10, 0);
        vector<int> temp;
        bool flag = false;
        for (char i = '1'; i <= s[0]; i++)cnt[i - '0']++;
        for (int i = 1; i < s.size(); i++) {
            temp = cnt;
            for (int j = 1; j < 9; j++)cnt[j] = (temp[j - 1] + temp[j + 1] + 1) % mod;
            cnt[0] = temp[1];
            cnt[9] = temp[8] + 1;
            if (!flag) {
                if (s[i] > s[i - 1] + 1)flag = true;
                if (s[i] == s[i - 1] + 1);
                if (s[i] == s[i - 1]) { flag = true; if (s[i - 1] < '9')cnt[s[i - 1] + 1 - '0']--; }
                if (s[i] == s[i - 1] - 1) { if (s[i - 1] < '9')cnt[s[i - 1] + 1 - '0']--; }
                if (s[i] < s[i - 1] - 1) { flag = true; if (s[i - 1] < '9')cnt[s[i - 1] + 1 - '0']--; cnt[s[i - 1] - 1 - '0']--; }
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0, [&mod](int a, int b) {return (a + b) % mod; });
    }
    int countSteppingNumbers(string low, string high) {
        int mod = 1e9 + 7;
        for (int i = low.size() - 1; i >= 0; i--) {
            if (low[i] != '0') { low[i]--; break; }
            else low[i] = '9';
        }
        return (count(high) - count(low) + mod) % mod;
    }
};

int main() {
    Solution sol; 
    string low = "1";
    string high = "12345678910111213141516171819202122232425262728293031323334353637383940";
	cout << sol.countSteppingNumbers(low, high) << endl;
}
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
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<>());
        int ans = 0;
        int t = 0;
        int temp = 0;
        for (auto& _ : satisfaction) {
            t += _;
            temp += t;
            ans = max(ans, temp);
        }
        return ans;
    }
};

int main() {
    Solution sol; 
    vector<int> satisfaction{ -1,-8,0,5,-7 };
	cout << sol.maxSatisfaction(satisfaction) << endl;
}
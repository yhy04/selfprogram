#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<assert.h>
using namespace std;


class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        int m = values.size(), n = values[0].size();
        auto comp = [&](int a, int b) {
            return values[a / n][a % n] > values[b / n][b % n];
            };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 1; i <= m; i++)pq.push(i * n - 1);
        long long t = 0;
        while (!pq.empty()) {
            int z = pq.top();
            pq.pop();
            ans += (++t) * values[z / n][z % n];
            if (z % n != 0)pq.push(z - 1);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> values{ {8, 5, 2},{6, 4, 1},{9, 7, 3} };
    int ans = sol.maxSpending(values);
	cout << ans << endl;
    assert(ans == 285);
	return 0;
}
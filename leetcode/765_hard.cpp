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
    int minSwapsCouples(vector<int>& row) {
        for (auto& _ : row) {
            _ /= 2;
        }
        int n = row.size() / 2;
        vector<int> parent(n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find;
        find = [&](int i) {
            if (parent[i] == i)return i;
            return parent[i] = find(parent[i]);
            };
        int ans = 0;
        for (int i = 0; i < n * 2; i += 2) {
            int x = find(row[i]), y = find(row[i + 1]);
            if (x == y)continue;
            if (x > y)swap(x, y);
            parent[y] = x;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> row = { 0,3,2,1,4,7,6,9,8,11,10,5 };
	cout << sol.minSwapsCouples(row) << endl;
}
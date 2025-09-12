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
    vector<int> res[4] = {
        {1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289},
        {1,8,27,64,125,216},
        {1,16,81,256},
        {1,32,243}
    };
    int mod = 1e9 + 7;

    int numberOfWays(int n, int x) {
        if (x != 1) {
            vector<int> a(301, 0);
            a[0] = 1;
            for (auto& i : res[x - 2]) {
                for (int j = n - i; j >= 0; j--) {
                    a[j + i] = (a[j + i] + a[j]) % mod;
                }
            }
            return a[n];
        }
        else {
            vector<int> a(301, 0);
            a[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = n - i; j >= 0; j--) {
                    a[j + i] = (a[j + i] + a[j]) % mod;
                }
            }
            return a[n];
        }
        return 0;
    }
};

int main() {
    Solution sol; 
    cout << sol.numberOfWays(300, 1) << endl;
    for (int i = 1; i <= 300; i++) {
        cout << sol.numberOfWays(i, 1)<<',';
    }
}
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
    long long f(int width, int t) {
        if (t < 0)return 0;
        long long res = 1;
        t = min(t, width - t);
        for (int i = 1; i <= t; i++) res = res * (width - i + 1) / i;
        return res;
    }
    long long popcountDepth(long long n, int k) {
        if (k == 5)return 0;
        if (k == 0)return 1;
        set<int> mySet;
        if (k == 1)mySet = { 1 };
        else if (k == 2)mySet = { 2,4,8,16,32 };
        else if (k == 3)mySet = { 3,5,6,9,10,12,17,18,20,24,33,34,36,40,48,15,23,27,29,30,39,43,45,46,51,53,54,57,58,60 };
        else if (k == 4)mySet = { 7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56,31,47,55,59,61,62,63 };
        long long ans = 0;
        long long t = ++n;
        while (t) {
            t = t & (t - 1);
			bitset<64> width_b((n^t)-1);
            bitset<64> place_b(t);
			int width = width_b.count();
			int __place = place_b.count();
            //int width = __popcount(static_cast<unsigned long long>((n ^ t) - 1));
            //int __place = __popcount(static_cast<unsigned long long>(t));
            for (auto _ : mySet) {
                if (width < _ - __place)break;
                ans += f(width, _ - __place);
            }
            n = t;
        }
        return k == 1 ? --ans : ans;
    }
};

int main() {
    Solution sol; 
    long long n = 66905320;
    int k = 3;
	cout << sol.popcountDepth(n, k) << endl;
}
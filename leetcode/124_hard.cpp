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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* rt) {
            if (!rt)return 0;
            int l_val = max(0, dfs(rt->left));
            int r_val = max(0, dfs(rt->right));
            int p = rt->val + l_val + r_val;
            ans = max(ans, p);
            return rt->val + max(l_val, r_val);
            };
        dfs(root);
        return ans;
    }
};

int main() {
	Solution sol; 
    TreeNode* root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << sol.maxPathSum(root) << endl;
}
/**
 * Definition for binary tree
 */
#include <iostream>
#include <stddef.h>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
			vector<vector<int> > res;
			if (!root)
				return res;

			if (!root->left && !root->right && sum == root->val) {
				vector<int> tmp(1, root->val);
				res.push_back(tmp);
				return res;
			}

			vector<vector<int> > ret1 = pathSum(root->left, sum - root->val);
			if (ret1.size()) {
				for (int i = 0; i < ret1.size(); ++i) {
					ret1[i].insert(ret1[i].begin(), root->val);
				}
				res.insert(res.end(), ret1.begin(), ret1.end());
			}
			vector<vector<int> > ret2 = pathSum(root->right, sum - root->val);
			if (ret2.size()) {
				for (int i = 0; i < ret2.size(); ++i) {
					ret2[i].insert(ret2[i].begin(), root->val);
				}
				res.insert(res.end(), ret2.begin(), ret2.end());
			}
			return res;
    }
};

int main (int argc, char **argv) {
	return 0;
}

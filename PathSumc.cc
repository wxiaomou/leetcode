/**
 * Definition for binary tree
 */
#include <iostream>
#include <stddef.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
			if (!root)
				return false;

			if (!root->left && !root->right && sum == root->val)
				return true;

			return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};

int main (int argc, char **argv) {
	return 0;
}

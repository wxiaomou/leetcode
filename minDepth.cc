/**
 * Definition for binary tree
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode *root) {
			if (!root)
				return 0;

			int left = minDepth(root->left);
			int right = minDepth(root->right);
			
			if (left ^ right)
				return min(left, right) + 1;
			else 
				return max(left, right) + 1;
    }

    //---------------------------------------//
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int left = _min(root->left);
        int right = _min(root->right);
        return min(left, right) + 1;
        
    }
    
    int _min(TreeNode *root) {
        if (!root) return INT_MAX;
        if (!root->left && !root->right) return 1;
        int left = _min(root->left);
        int right = _min(root->right);
        return min(left, right) + 1;
    }
};

int main (int argc, char **argv) {
	return 0;
}

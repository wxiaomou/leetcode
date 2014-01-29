/**
 * Definition for binary tree
 */
#include <iostream>
#include <stddef.h>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
        //recursion way
		bool isSymmetric(TreeNode *root) {
			if (!root)
				return true;
			return isSame(root->left, root->right);
		}

		bool isSame(TreeNode *left, TreeNode *right) {
			if (!left && !right)
				return true;
			if (!left || !right)
				return false;

			if (left->val == right->val) 
				return isSame(left->left, right->right) && isSame(left->right, right->left);
			else 
				return false;
		}

		// iterate by level and compare
        bool isSymmetric2(TreeNode *root) {
            if (!root) return true;
            queue<TreeNode *> l;
            queue<TreeNode *> r;
            l.push(root->left);
            r.push(root->right);
            while (l.size() && r.size()) {
                TreeNode *left = l.front();
                TreeNode *right = r.front();
                l.pop();
                r.pop();
                if ((left && !right) || (!left && right)) return false;
                if (left) {
                    if (left->val != right->val) return false;
                    l.push(left->left);
                    l.push(left->right);
                    r.push(right->right);// !!attention Mirror!!
                    r.push(right->left);
                }
        }
        return true;
    }
};

int main(int argc, char **argv) {
	return 0;
}

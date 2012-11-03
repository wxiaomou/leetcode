/**
 * Definition for binary tree
 */
#include <iostream>
#include <vector>
#include <stddef.h>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		int pre = INT_MIN;
		return recursion(root, pre);
	}

	bool recursion(TreeNode *root, int &pre) {
		if (!root)
			return true;

		if (recursion(root->left, pre)) {
			if (root->val > pre) {
				pre = root->val;
				return recursion(root->right, pre);
			} else {
				return false;
			}
		}
		return false;
	}
	// o(n) time and O(n) space.
	 bool isValidBST2(TreeNode *root) {
           vector<int> com;
				if (!root)
					return true;

				inorder(root, com);
				for (int i = 0; i < com.size() - 1; i++) {
					if (com[i] >= com[i + 1])
						return false;
				}
				return true;
    }

		void inorder(TreeNode *root, vector<int> &com) {
			if (!root)
				return;
			inorder(root->left, com);
			com.push_back(root->val);
			inorder(root->right, com);
			return;
		}
};

int main(int argc, char **argv) {
	return 0;
}

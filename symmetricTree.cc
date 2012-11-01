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
		// iterative way but exceed memory. need revise
    bool isSymmetric2(TreeNode *root) {
			if (!root)
				return true;
			if (!root->left && !root->right)
				return true;
			if (!root->left || !root->right)
				return false;
			queue<TreeNode *> que;
			vector<int> com;
			int count;
			que.push(root);
			count = que.size();
			TreeNode *fill = new TreeNode(-1);
			while (!que.empty()) {
				TreeNode *tmp = que.front();
				if (tmp) {
					com.push_back(tmp->val);
					if (tmp->left)
						que.push(tmp->left);
					else
						que.push(fill);
					if (tmp->right)
						que.push(tmp->right);
					else
						que.push(fill);
				} 
				com.push_back(tmp->val);
				count--;
				if (count == 0) {
						count = que.size();
						if (!check(com))
							return false;
						com.clear();
				}
			}

			return true;
    }

		bool check(vector<int> com) {
			if (com.size() == 1)
				return true;

			for (int i = 0; i < com.size() / 2; i ++) {
				if (com[i] != com[com.size() - 1 - i])
					return false;
			}

			return true;
		}
};

int main(int argc, char **argv) {
	return 0;
}

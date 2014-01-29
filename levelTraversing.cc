/**
 * Definition for binary tree
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
			vector<vector<int> > ret;
			if (!root)
				return ret;
			int count = 0;
			queue<TreeNode*> que;
			que.push(root);
			count = que.size();

			vector<int> lev;
			while (que.size()) {
				TreeNode *tmp = que.front();
				que.pop();
				lev.push_back(tmp->val);
				
				if (tmp->left)
					que.push(tmp->left);

				if (tmp->right)
					que.push(tmp->right);

				count--;
				if (!count) {
					ret.push_back(lev);
					lev.clear();
					count = que.size();
				}

			}
			return ret;
    }
};

int main(int argc, char **argv) {
	return 1;

}

/**
 * Definition for binary tree
 */
#include <iostream>
#include <stddef.h>
#include <queue>
#include <vector>
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
    		vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
    			if (!root)
						return res;

					queue<TreeNode *> que;
					que.push(root);
					
					vector<int> tmp;
					int count = que.size();
					while (!que.empty()) {
						TreeNode *a = que.front();
						que.pop();
						tmp.push_back(a->val);

						if (a->left)
							que.push(a->left);
						if (a->right)
							que.push(a->right);

						count--;
						if (!count) {
							count = que.size();
							res.push_back(tmp);
							tmp.clear();
						}
					}
					reverse(res.begin(), res.end());
					return res;
				}


};

int main(int argc, char **argv) {
	TreeNode tmp(1);
	TreeNode tmp1(2);
	tmp.right = &tmp1;
	Solution sol;
	vector<vector<int> > ret = sol.levelOrderBottom(&tmp);

	for (int i = 0; i < ret.size(); ++i) {
		vector<int> t1 = ret[i];
		for (int j = 0; j < t1.size(); ++j)
			cout << t1[j] << " ";
		cout << endl;
	}
	return 0;
}

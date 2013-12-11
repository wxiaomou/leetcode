/**
 * Definition for binary tree
 */
#include <iostream>
#include <vector>
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
		vector<TreeNode *> generateTrees(int n) {
			return doGenerateTrees(1, n);
		}

    vector<TreeNode *> doGenerateTrees(int start, int end) {
			vector<TreeNode *> res;
			if(start > end) {
				res.push_back(NULL); // Need to push NULL or the size of lef1 or right1 will be 0, and it cannot go into the for loop.
				return res;
			}
			for (int i = start; i <= end; i++) {
				vector<TreeNode *> left1 = doGenerateTrees(start, i - 1);
				vector<TreeNode *> right1 = doGenerateTrees(i + 1, end);
				for (int j = 0; j < left1.size(); j++) {
					for (int k = 0; k < right1.size(); k++) {
						TreeNode *root = new TreeNode(i);
						root->left = left1[j];
						root->right = right1[k];
						
						res.push_back(root);
					}
				}
			}	
			return res;
    }		
};

int main(int argc, char **argv) {
	Solution sol;
	sol.generateTrees(1);
	return 0;
}

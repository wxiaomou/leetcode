/**
 * Definition for binary tree */
#include <iostream>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (!root) return ret;
        stack<pair<TreeNode *, bool> > s;
        s.push(pair<TreeNode *, bool>(root, false));
        while (s.size()) {
            pair<TreeNode *, bool> &tmp = s.top(); //!!!need to be refernece other the line 39 won't chage the second part
            if (!tmp.second) {
                if (!tmp.first->right && !tmp.first->left) {
                    ret.push_back(tmp.first->val);
                    s.pop();
                    continue;
                }
                if(tmp.first->right) {
                    s.push(pair<TreeNode *, bool>(tmp.first->right, false));
                }
                if(tmp.first->left) {
                    s.push(pair<TreeNode *, bool>(tmp.first->left, false));
                }
                tmp.second = true;
            } else {
                ret.push_back(tmp.first->val);
                s.pop();
            }
        }
        return ret;
    }
};

int main() {
	Solution sol;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	sol.postorderTraversal(root);
}

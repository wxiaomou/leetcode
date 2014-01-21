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
    //betterway
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return vector<int>();
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(root);
        while (s.size()) {
            TreeNode *tmp = s.top();
            s.pop();
            if (tmp) {
                if (tmp->left) s.push(tmp->left);
                if (tmp->right) s.push(tmp->right);
                ret.insert(ret.begin(), tmp->val);
            }
        }
        return ret;
    }
    //-------------------------------------------------------//
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (!root) return ret;
        stack<pair<TreeNode *, bool> > s;http://www.codeskulptor.org/#examples-spaceship.py
        while (s.size()) {
            pair<TreeNode *, bool> &tmp = s.top(); //!!!need to be refernece other the line 40 won't chage the second part
												   //change line 40 to s.top().second = true not work, because s will add new item, so we need tmp to be a reference
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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<int> *l;
        l = new vector<int>;
        //deque<TreeNode *> q;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        int cnt = 1;
        s1.push(root);
        int round = 0;
        while (s1.size() || s2.size()) {
            TreeNode *tmp = NULL;
            if (round % 2 == 0) {
                tmp = s1.top();
                s1.pop();
                l->push_back(tmp->val);
                if (tmp->left)
                    s2.push(tmp->left);
                if (tmp->right)
                    s2.push(tmp->right);
                
            } else {
                tmp = s2.top();
                s2.pop();
                l->push_back(tmp->val);
                if (tmp->right)
                    s1.push(tmp->right);
                if (tmp->left)
                    s1.push(tmp->left);
            }
            cnt--;
            if (!cnt) {
                ret.push_back(*l);
                l = new vector<int>;
                if (round % 2 == 0) {
                    cnt = s2.size();
                } else {
                    cnt = s1.size();
                }
                round++;
            }
        }
        return ret;
    }
};
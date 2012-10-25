/**
 * Definition for binary tree
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
              vector<TreeNode *> inorder;
    void recoverTree(TreeNode *root) {
  			if (!root)
					return;
				fillTmp(root);

				for (int i = 0; i < inorder.size(); ++i) cout << inorder[i]->val << " ";
				cout << endl;
				int first, second;  
        for (int i = 0; i < inorder.size()-1; ++i)  
        {  
            if (inorder[i]->val > inorder[i+1]->val)  
            {  
                first = i;  
                break;  
            }  
        }  
          
        for (int i = inorder.size()-1; i > 0; --i)  
        {  
            if (inorder[i]->val < inorder[i-1]->val)  
            {  
                second = i;  
                break;  
            }  
        }  
          
        int tmp = inorder[first]->val;  
        inorder[first]->val = inorder[second]->val;  
        inorder[second]->val = tmp;  
				inorder.clear();
				fillTmp(root);
				for (int i = 0; i < inorder.size(); ++i) cout << inorder[i]->val << " ";
				cout << endl;
    }  

		void fillTmp(TreeNode *root) {
			if (!root)
				return;

			if (root->left)
				fillTmp(root->left);
			inorder.push_back(root);

			if (root->right)
				fillTmp(root->right);

			return;
		}
};

int main (int argc, char **argv) {
	TreeNode *root = new TreeNode(1);
	//TreeNode *left = new TreeNode(3);
	TreeNode *right = new TreeNode(3);
	root->right = right;
	TreeNode *rr = new TreeNode(2);
	right->right = rr;
	Solution sol;
	sol.recoverTree(root);
	return 0;
}

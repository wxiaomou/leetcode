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
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        	int n = preorder.size();
        	if (!n) return NULL;
        	return build(preorder, 0, n - 1, inorder, 0, n - 1);
    	}
    
  		TreeNode *build(vector<int> &preorder, int p_b, int p_e, vector<int> &inorder, int i_b, int i_e) {
        	if (p_b > p_e) return NULL;
        	TreeNode *root = new TreeNode(preorder[p_b]);
        	if (p_b == p_e) return root;
        	int len = 0;
        
        	for (int i = i_b; i <= i_e; ++i) {
            	if (inorder[i] == preorder[p_b]) break;
            	len++;
        	}
        	root->left = build(preorder, p_b + 1, p_b + len, inorder, i_b, i_b + len - 1);
        	root->right = build(preorder, p_b + len + 1, p_e, inorder, i_b + len + 1, i_e);
    	}

		//------------------------------------------------------//
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
						int pend = preorder.size() - 1;
						int iend = inorder.size() - 1;
						if (pend <= -1 || iend <= -1) return NULL;
						return _build(preorder, 0, pend, inorder, 0, iend);
        }
				
	   TreeNode * _build(vector<int> &preorder, int p_begin, int pend, vector<int> &inorder, int i_begin, int iend) {
					if (p_begin > pend || i_begin > iend) return NULL;
					TreeNode *root = new TreeNode(preorder[p_begin]);
					int index = i_begin;
					while (inorder[index] != preorder[p_begin]) index++;
					int pre_left_len = index - i_begin;
					root->left = _build(preorder, p_begin + 1, p_begin + pre_left_len, inorder, i_begin, index - 1);
					root->right = _build(preorder, p_begin + pre_left_len + 1, pend, inorder, index + 1, iend);
					return root;
		}
};

int main() {
	return 0;
}

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
/* O(1) Solution

class Solution {
public:
    TreeNode *pre;
    TreeNode *p, *q;
    void recoverTree(TreeNode *root) {
        if (!root) return;
        pre = NULL;
        p = NULL;
        q = NULL;
        traverse(root, pre, p, q);
        if (p && q) {
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
        }
    }

//Inorder traverse, pre should increasing only, if failed then we find the node,
//first time should be the node which moved from right to left. so p = pre, and second
//time should vice versa so q = root;
//We use pre as a pointer scan the in order traverse result, and just compare it with it right elements.
//Pre is the one element which before root int the in order transverse.

    void traverse(TreeNode *root, TreeNode *&pre, TreeNode *&p, TreeNode *&q) {
        if (!root) return;
        traverse(root->left, pre, p, q);
        //if (!pre) {
        //    pre = root;
        //} //we can this if block, but we cannot return here. eg, we only have right child, this return will ignore the all right branch.
       if (pre && pre->val > root->val) {
           if (!p) p = pre;
           q = root;  // in case {0,1} conner case, no else here since this will only happen just once.
         }
        pre = root;
        traverse(root->right, pre, p, q);
    }
    
};


*/

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

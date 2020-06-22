/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findSubTree(TreeNode* A, TreeNode* B){
        if(nullptr == B) return true;
        if(nullptr == A) return false;

        if(A->val != B->val) return false;

        return findSubTree(A->left, B->left) && findSubTree(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(nullptr == B || nullptr == A) return false;
        if(A->val == B->val && findSubTree(A->left, B->left)
            && findSubTree(A->right, B->right)){
                return true;
        }

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

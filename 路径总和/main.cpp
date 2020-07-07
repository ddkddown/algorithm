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
int s;
bool getAnswer(TreeNode* root, int count){
    if(!root){
        return false;
    }

    if(count == s && !root->left && !root->right){
        return true;
    }

    if(root->left){
        if(getAnswer(root->left, count+root->left->val)){
            return true;
        }
    }

    if(root->right){
        if(getAnswer(root->right, count+root->right->val)){
            return true;
        }
    }

    return false;
}
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        s = sum;
        return getAnswer(root, root->val);
    }
};
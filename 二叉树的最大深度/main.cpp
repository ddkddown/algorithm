/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
    int depth(TreeNode* p, int d)
    {
        if(nullptr == p) return d;
        ++d;
        if(nullptr == p->right && nullptr == p->left) return d;
        int l = 0;
        int r = 0;
        l = depth(p->left, d);
        r = depth(p->right, d);
        return l >= r ? l : r;
    }
public:
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
    vector<int> m_preorder;
    map<int, int> dic;
public:
    TreeNode* build(int pre_root, int in_left, int in_right){
        if(in_left > in_right){
            return nullptr;
        }

        TreeNode* root = new TreeNode(m_preorder[pre_root]);
        int index = dic[m_preorder[pre_root]];
        root->left = build(pre_root+1, in_left, index-1);
        root->right = build(pre_root+index-in_left+1, index+1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m_preorder = preorder;
        for(int i = 0; i < inorder.size(); ++i){
            dic[inorder[i]] = i;
        }

        return build(0,0,preorder.size()-1);
    }
};
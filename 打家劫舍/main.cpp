#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    unordered_map<TreeNode* int> f;
    unordered_map<TreeNode*, int> g;

    void dfs(TreeNode* o){
        if(!o){
            return;
        }

        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    }

    int rob(TreeNode* o){
        dfs(o);
        return max(f[o], g[o]);
    }

};
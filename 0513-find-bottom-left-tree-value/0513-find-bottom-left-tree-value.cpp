/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth=-1;
    int ans;
    int rec(TreeNode * root,int depth){
        if(root==NULL){
            return 0;
        }
        if(maxDepth<depth){
            ans=(root->val);
        }
        
        
        rec(root->left,depth+1);
        rec(root->right,depth+1);

        maxDepth=max(maxDepth,depth);
        
        return ans;
    }
    int findBottomLeftValue(TreeNode* root) {

        return rec(root,0);
        
        
    }
};
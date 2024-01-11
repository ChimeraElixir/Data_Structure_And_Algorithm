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
    int diff=0;
    void Difference(TreeNode* root,int ma,int mi){
        if(root==NULL){
            return;
        }
        ma=max(ma,root->val);
        mi=min(mi,root->val);

        diff=max(diff,ma-mi);

        Difference(root->left,ma,mi);
        Difference(root->right,ma,mi);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ma=INT_MIN,mi=INT_MAX;
        Difference(root,ma,mi);
        return diff;
    }
};
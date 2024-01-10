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

    void ToGraph(map <int ,vector<int>>& adj,TreeNode* root){

        if(root == NULL) {
            return;
        }
        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            ToGraph(adj, root->left);
        }

        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            ToGraph(adj, root->right);
        }
        
    }
    
    
 
    
    int Tree(TreeNode* root) {

        
        map <int ,vector<int>> adj;
        ToGraph(adj,root);



        for(auto i: adj ){
            cout<<i.first<<" ";
            for(auto j: i.second){
                cout<<j;
            }
            cout<<endl;
        }

        return ;
    }
};
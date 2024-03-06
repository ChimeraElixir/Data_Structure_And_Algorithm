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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        pair<int,int> p1;
        pair<int,int> p2;
        q.push(root);
        q.push(NULL);
        int counter=0;

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                counter++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left){
                    if(temp->left->val==x){
                        p1.first=temp->val;
                        p1.second=counter+1;
                    }
                    if(temp->left->val==y){
                        p2.first=temp->val;
                        p2.second=counter+1;
                    }
                    q.push(temp->left);
                }
                if(temp->right){
                    if(temp->right->val==x){
                        p1.first=temp->val;
                        p1.second=counter+1;
                    }
                    if(temp->right->val==y){
                        p2.first=temp->val;
                        p2.second=counter+1;
                    }
                    q.push(temp->right);
                }
            }
        }
        
        if(p1.first != p2.first && p1.second==p2.second){
            return true;
        }
        return false;


    }
};
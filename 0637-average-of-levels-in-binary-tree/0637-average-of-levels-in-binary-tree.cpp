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
    vector<double> averageOfLevels(TreeNode* root) {
         if (root ==NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<double> ans;
        double j=0;
        int count=0;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                ans.push_back(j/count);
                j=0;
                count=0;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                j+=temp->val;
                count++;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
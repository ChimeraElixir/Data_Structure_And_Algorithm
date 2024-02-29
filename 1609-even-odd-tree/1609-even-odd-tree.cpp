/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
         if (!root) {
            return true;
        }

        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        q.push(nullptr); // Use nullptr as a delimiter for each level

        int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX; // Initialize prev_val based on level's parity

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                if (q.empty()) {
                    break; // Reached the end of the tree
                }

                // Move to the next level
                level++;
                prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX; // Reset prev_val based on new level's parity
                q.push(nullptr); // Push delimiter for the next level
                continue;
            }

            // Check if the values follow the conditions
            if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val)) ||
                (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val))) {
                return false;
            }

            prev_val = node->val;

            // Add children to the queue
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        return true;
    }
    
};
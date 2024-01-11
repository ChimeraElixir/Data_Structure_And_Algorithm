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
    int max_=0;
    int max_1=0;
    void ToGraph(map<int, vector<int>>& adj, TreeNode* root) {

        if (root == NULL) {
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

    void dfs(int node, unordered_map<int, bool>& visited, vector<int>& ans,
             map<int,vector<int>>& adj) {
        visited[node] = true;
        ans.push_back(node);
        for (auto j : adj[node]) {
            if (!visited[j]) {
                max_=max(max_,++max_1);
                dfs(j, visited, ans, adj);
                max_=max(max_,--max_1);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {

        map<int, vector<int>> adj;
        ToGraph(adj, root);

        // for(auto i: adj ){
        //     cout<<i.first<<" ";
        //     for(auto j: i.second){
        //         cout<<j;
        //     }
        //     cout<<endl;
        // }

        vector<int> ans;
        unordered_map<int, bool> visited;

        if (!visited[start]){
            dfs(start, visited, ans,adj);
        }
        
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        return max_;
    }
};
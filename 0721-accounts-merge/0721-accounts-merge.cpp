class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int A , int B){
        int parentA = findParent(A);
        int parentB = findParent(B);
        if(parentA == parentB) return ;
        if(size[parentA]>=size[parentB]){
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
        else{
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
    }
};

class Solution {
  public:
   vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int numAccounts = accounts.size();
      map<string, int> emailToAccountId;
      DisjointSet ds(numAccounts);

      
      for(int accountId = 0; accountId < numAccounts; accountId++) {
          for(int j = 1; j < accounts[accountId].size(); j++) {
              string currentEmail = accounts[accountId][j];
              if(emailToAccountId.find(currentEmail) == emailToAccountId.end()) {
                  emailToAccountId[currentEmail] = accountId;
              }
              else {
                  ds.unionBySize(emailToAccountId[currentEmail], accountId);
              }
          }
      }

      
      vector<vector<string>> mergedEmails(numAccounts);
      for(auto it : emailToAccountId) {
          string email = it.first;
          int accountId = it.second;
          int parentAccountId = ds.findParent(accountId);
          mergedEmails[parentAccountId].push_back(email);
      }

      
      vector<vector<string>> mergedAccounts;
      for(int accountId = 0; accountId < numAccounts; accountId++) {
          if(mergedEmails[accountId].empty()) continue;

          sort(mergedEmails[accountId].begin(), mergedEmails[accountId].end());

          vector<string> accountEntry;
          accountEntry.push_back(accounts[accountId][0]);  // Add name
          for(auto email : mergedEmails[accountId]) {
              accountEntry.push_back(email);
          }

          mergedAccounts.push_back(accountEntry);
      }

      return mergedAccounts;
  }
};
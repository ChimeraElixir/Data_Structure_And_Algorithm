class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<int, int> m;
        priority_queue <int, vector<int>, greater<int> > pq;

        if (k >= n) {
            return 0;
        }

        for (auto i : arr) {
            m[i]++;
        }
    

        for (auto i : m) {
            pq.push(i.second);
        }
      

        while (k > 0 ) {
            int top = pq.top();
            if (k - top >= 0) {
                k -= top;
                pq.pop();
            } else {
                break;
            }
        }
        
        return pq.size();
    }
};
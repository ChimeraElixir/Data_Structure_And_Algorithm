class Solution {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                int element = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int element = arr[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (matrix[i][j] - '0');
                if (matrix[i][j] == '0')
                    sum = 0;
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, solve(prefixSum[i]));
        }
        return maxArea;
    }
};
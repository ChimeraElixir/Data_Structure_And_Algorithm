class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n ,0);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i != m && j != n) {
            if (nums1[i] <= nums2[j]) {
                v[k++] = nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                v[k++] = nums2[j++];
            }
        }
        cout << endl;
        while (i != m) {
            v[k++] = nums1[i++];
        }
        while (j != n) {
            v[k++] = nums2[j++];
        }
        for (auto i : v) {
            cout << i << " ";
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=v[i];
        }
    }
};
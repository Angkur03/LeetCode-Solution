class Solution {
public:
    int dp(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        int result = 0;
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    result = max(result, t[i][j]);
                } else
                    t[i][j] = 0;
            }
        }
        
        return result;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return dp(nums1, nums2, nums1.size(), nums2.size());
    }
};
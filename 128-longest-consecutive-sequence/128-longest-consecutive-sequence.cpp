class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        int cnt = 0 ;
        int mx = 0;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i] + 1;
            cnt = 1;
            if(!st.count(nums[i] - 1)){
            while(st.count(val)) {
                val++;
                cnt++;
            }
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            mp[val]++;
        }
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            if(val>=k) {
                continue;
            }
            if(mp[val] > 0) {
                int diff = abs(val - k);
                if(diff == val && mp[diff] > 1) {
                    cout<<diff<<" - "<<val<<" "<<mp[diff]<<" "<<mp[val]<<endl;
                
                    cnt++;
                    mp[diff]--;
                    mp[val]--;
                } else if(diff != val && mp[diff] > 0) {
                    cout<<diff<<" -- "<<val<<" "<<mp[diff]<<" "<<mp[val]<<endl;
                
                    cnt++;
                    mp[diff]--;
                    mp[val]--;
                }
            }
        }
        return cnt;
    }
};
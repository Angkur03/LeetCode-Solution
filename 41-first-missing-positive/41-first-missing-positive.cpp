class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        int n=1;
        while(1) {
            if(mp.find(n) == mp.end())
                return n;
            n++;
        }
    }
};
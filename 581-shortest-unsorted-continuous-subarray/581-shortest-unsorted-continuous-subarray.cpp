class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>input;
        input = nums;
        sort(input.begin(), input.end());
        
        int start = -1;
        int end = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != input[i]) {
                start = i;
                break;
            }
        }
        
        for(int i=nums.size() - 1; i>=0; i--) {
            if(nums[i] != input[i]) {
                end = i;
                break;
            }
        }
        
        //cout<<start<<" -- "<<end<<endl;
        if(end == start) {
            return 0;
        }
        return end-start + 1;
        
    }
};
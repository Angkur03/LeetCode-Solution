class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonCircular = getMax(nums);
        int total = 0;
        for(int i=0; i<nums.size(); i++) {
            total+=nums[i];
            nums[i] *= - 1;
        }
        
        int circularSum = total + getMax(nums);
        if(circularSum == 0)
            return nonCircular;
        return max(circularSum,nonCircular);
    }
    
    int getMax(vector<int>& nums) {
        int sum = nums[0];
        int mx = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(sum < 0) {
                sum = 0;
            }
            
            sum+=nums[i];
            
            mx = max(mx,sum);
        }
        return mx;
    }
};

/*
[5,-3,5]
[-3,-2,-3]
*/
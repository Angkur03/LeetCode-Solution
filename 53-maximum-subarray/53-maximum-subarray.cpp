class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentMax = 0 ;
        int totalMax = INT_MIN ;
        
        for(int i=0; i<nums.size(); i++){
            
            int val = nums[i] ;
            currentMax = currentMax + val ;
            if(currentMax > totalMax)
                totalMax = currentMax ;
            
            if(currentMax < 0)
                currentMax = 0 ;
            
        }
        
        return totalMax ;
        
    }
};
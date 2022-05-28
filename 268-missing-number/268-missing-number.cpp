class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long total = nums.size() ;
        long long sum = total * (total + 1)  ;
        sum = sum / 2 ;
        
        long long res = 0 ;
        for (int i = 0; i< nums.size(); i++) {
        res = res + nums[i] ;
        }
        
        return sum - res ;
    }
};
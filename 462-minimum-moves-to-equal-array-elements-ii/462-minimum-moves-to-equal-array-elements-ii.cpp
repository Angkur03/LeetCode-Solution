class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int median = nums[sz / 2];
        int minMove = 0;
        for(int i=0; i<sz; i++) {
            minMove += abs(nums[i] - median);
        }
        return minMove;
    }
};
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int len = 0;
        int negCnt = 0;
        int firstNeg = -1;
        int start = -1;
        
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            if(val == 0) {
                negCnt = 0;
                firstNeg = -1;
                start = i;
            } else {
                if(val < 0) {
                    negCnt++;
                }
                if(negCnt == 1 && firstNeg == -1) {
                    firstNeg = i;
                }
                if(negCnt % 2 == 0) {
                    len = max(len, i - start);
                    //cout<<i<<" -- "<<start<<endl;
                } else {
                    len = max(len, i - firstNeg);
                }
            }
        }
        return len;
    }
};
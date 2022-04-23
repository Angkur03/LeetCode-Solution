class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int start = left; start<=right; start++) {
            if(isValid(start)) {
                //cout<<start<<endl;
                ans.push_back(start);
            }
        }
        return ans;
    }
    
    bool isValid(int num) {
        int tmp = num;
        while(tmp != 0) {
            int val = tmp%10;
            tmp/=10;
            //cout<<val<<" -- "<<tmp<<endl;
            if(val == 0) {
                return false;
            } else if(num%val != 0) {
                return false;
            }
        }
        return true;
    }
};
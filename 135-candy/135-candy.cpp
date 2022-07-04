class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>res;
        int sz = ratings.size();
        for(int i=0; i<sz; i++) {
            res.push_back(1);
        }
        
        for(int i=0; i<sz-1; i++) {
            if(ratings[i + 1] > ratings[i]) {
                res[i + 1] = res[i] + 1;
            }
        }
        
         for(int i=sz-1; i>0; i--) {
            if(ratings[i - 1] > ratings[i]) {
                if(res[i-1] <= res[i]) {
                    res[i-1] = res[i] + 1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<sz; i++) {
            ans+=res[i];
        }
        
        return ans;
    }
};
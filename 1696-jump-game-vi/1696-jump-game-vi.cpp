class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int sz = nums.size();
        int res[sz];
        priority_queue<pair<int,int> > pq;
        
        for(int i=sz-1; i>=0; i--) {
            while(pq.size() && pq.top().second > i + k) pq.pop();
            
            res[i] = nums[i];
            res[i]+=(pq.size() > 0 ? pq.top().first : 0);
            pq.push(make_pair(res[i], i));
        }
        
        return res[0];
    }
};
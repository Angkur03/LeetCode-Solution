class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& effi, int k) {
        vector<pair<int,int>> vec;
        
        for(int i=0;i<n;i++) vec.push_back({effi[i],speed[i]});
        
        sort(vec.begin(),vec.end());
        
        priority_queue<int, vector<int> , greater<int>> pq;
        
        long long ans=0;
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            if(pq.size()<k){
                pq.push(vec[i].second);
                sum+= vec[i].second;
            }
            else if(pq.top()<vec[i].second){
                sum-= pq.top(); pq.pop();
                sum+= vec[i].second;
                pq.push(vec[i].second);
            }
            ans= max((long long)vec[i].first*sum,ans);
        }
        
        return ans%1000000007;
    }
};
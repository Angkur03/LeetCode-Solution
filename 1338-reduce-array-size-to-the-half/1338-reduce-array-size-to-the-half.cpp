class Solution {
public:
    int minSetSize(vector<int>& arr) {
        set<int>st;
        map<int,int>mp;
        map<int,int>tmp;
        int sz = arr.size();
        for(int i=0; i<sz; i++) {
            mp[arr[i]]++;
        }
        
        vector<int>vec;
        
        for(int i=0; i<sz; i++) {
            if(mp[arr[i]] > 0) {
                vec.push_back(mp[arr[i]]);
                mp[arr[i]] = 0;
            }
        }
        
        sort(vec.begin(), vec.end());
        int cnt = 0;
        int ans = 0;
        if(sz%2) {
            sz++;
        }
        sz/=2;
        
        for(int i = vec.size() - 1; i>=0; i--) {
            ans++;
            cnt+=vec[i];
            if(cnt>=sz) {
                break;
            }
        }
        
        return ans;
    }
};
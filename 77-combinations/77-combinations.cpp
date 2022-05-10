class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>pattern;
        createCombination(n,k,pattern,ans,0,0);
        return ans;
    }
    
    void createCombination(int n,int k,vector<int>pattern, vector<vector<int>> &ans,int pos,int cnt) {
        if(cnt == k) {
            ans.push_back(pattern);
            return;
        }
        
        if(cnt>k) {
            return;
        }
        
        for(int i=pos+1; i<=n; i++) {
            pattern.push_back(i);
            createCombination(n,k,pattern,ans,i,cnt+1);
            pattern.pop_back();
        }
    }
};
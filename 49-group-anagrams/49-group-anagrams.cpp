class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto st: strs) {
            string ss = st;
            sort(ss.begin(),ss.end());
            mp[ss].push_back(st);
        }
        
        for(auto mm: mp) {
            ans.push_back(mm.second);
        }
        
        return ans;
    }
};
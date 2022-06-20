class Solution {
public:
    static bool cmp(string &s1, string &s2) {
        return s1.size() > s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        
        string ans = words[0] + "#";
        
        for(int i=1; i<words.size(); i++) {
            string curr = words[i] + "#";
            if(ans.find(curr) == -1) {
                ans += curr;
            }
        }
        return ans.size();
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        map<char,int>lastPos;
        for(char ch = 'a'; ch<='z'; ch++) {
            lastPos[ch] = -1;
        }
        
        //map<char,int>lastPos;
        int start = 0;
        int end = 0;
        int len = 1;
        int lastFound = 0;
        while(end < s.size()) {
            char ch = s[end];
            int last = lastPos[ch];
            if(lastPos.find(ch) != lastPos.end() && lastPos[ch] >= start) {
                int diff = end - start;
                len = max(diff,len);
                start = lastPos[ch] + 1;
                lastFound = end;
            }
            lastPos[ch] = end;
            end++;
        }
        if(lastFound != s.size() - 1) {
            len = max(len, end - start);
        }
        return len;
    }
};
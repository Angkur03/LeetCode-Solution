class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int n = s.size(), l, r;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) { ans.push_back(0); continue; }
            for (l = i - 1; l >= 0; --l) if (s[l] == c) break;
            for (r = i + 1; r < n; ++r) if (s[r] == c) break;
            ans.push_back(l == -1 ? (r - i) : (r == n ? (i - l) : min(i - l, r - i)));
        }
        return ans;
    }
};
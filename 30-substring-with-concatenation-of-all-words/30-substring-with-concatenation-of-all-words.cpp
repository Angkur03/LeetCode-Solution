class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int>mp,tmp;
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            mp[word]++;
        }
        
        vector<int>ans;
        int wordLen = words[0].size();
        int total = words.size() * words[0].size();
        int len = s.size();
        if(len < total) {
            return ans;
        }
        
        for(int i = 0; i <= len-total; i++) {
            tmp = mp;
            string str = s.substr(i, total);
            //cout<<"str "<<str<<endl;
            int j = 0;
            int cnt = 0;
            while(j<words.size()) {
                int start = j*wordLen;
                //cout<<"start "<<start<<endl;
                string val = str.substr(start, wordLen);
                j++;
                //cout<<"st "<<val<<endl;
                //cout<<val<<" -- "<<tmp[val]<<endl;
                if(tmp[val] > 0 ) {
                    //cout<<i<<" -- "<<val<<endl;
                    cnt++;
                    tmp[val]--;
                } else {
                    //cout<<"break "<<j<<endl;
                    break;
                }

            }
            //cout<<"last "<<j<<endl;
            if(cnt == words.size()) {
                //cout<<i<<endl;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
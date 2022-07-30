class Solution {
public:
    map<char,int>mp;
    
    void countMax(string st) {
        map<char,int>tmp;
        for(auto ch: st) {
            tmp[ch]++;
        }
        
        for(auto ch: st) {
            mp[ch]= max(mp[ch],tmp[ch]);
        }
    }
    
    bool isMatched(string st) {
        map<char,int>tmp;
        for(auto ch: st) {
            tmp[ch]++;
            //cout<<"ch "<<ch<<" "<<tmp[ch]<<endl;
        }
        
        for(char ch='a'; ch<='z'; ch++) {
            //cout<<"ch "<<ch<<" "<<tmp[ch]<<" "<<mp[ch]<<endl;
            if(tmp[ch] < mp[ch]) {
                //cout<<"gg "<<st<<" "<<ch<<" "<<mp[ch]<<" "<<tmp[ch]<<endl;
                return false;
            }
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        for(auto st: words2) {
            countMax(st);
        }
        
        for(char ch = 'a'; ch<= 'z'; ch++) {
           // cout<<"ch "<<ch<<" "<<mp[ch]<<endl;
        }
        vector<string>res;
        for(int i=0; i<words1.size(); i++) {
            string st = words1[i];
            if(isMatched(st) == true) {
                res.push_back(st);
            }
        }
        return res;
    }
};
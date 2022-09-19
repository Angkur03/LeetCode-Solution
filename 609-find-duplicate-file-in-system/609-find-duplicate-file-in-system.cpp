class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        // declare a map
        
        unordered_map<string, vector<string>> mp;
        
        // traverse over all the strings in paths
        
        for(auto str : paths)
        {
            int n = str.size();
            
            int i = 0;
            
            // find the path of file
            
            string path = "";
            
            while(i < n && str[i] != ' ')
            {
                path += str[i];
                
                i++;
            }
            
            // add to every path 
            
            path += '/';
            
            // skip space
            
            i++;
            
            while(i < n)
            {
                string file_name = "";
                
                string file_ext = "";
                
                // find extension name
                
                while(i < n && str[i] != '(')
                {
                    file_ext += str[i];
                    
                    i++;
                }
                
                // find file name
                
                while(i < n && str[i] != ' ')
                {
                    file_name += str[i];
                    
                    i++;
                }
                
                // insert the (path + file_ext) in map corresponding to file_name
                
                mp[file_name].push_back(path + file_ext);
                
                i++;
            }
        }
        
        // bulid the res
        
        vector<vector<string>> res;
        
        for(auto x : mp)
        {
            if(x.second.size() > 1)
            {
                res.push_back(x.second);
            }
        }
        
        return res;
    }
};
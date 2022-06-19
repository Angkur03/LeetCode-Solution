class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        int n = products.size();
        sort(begin(products), end(products));
        
        string prefix = "";
        int index = 0;
        for(char &ch : searchWord) {
            prefix.push_back(ch);
            
            int start = lower_bound(products.begin() + index, end(products), prefix) - begin(products);
            /*
                NOTE : lower bound returns element which is equal to or greater than the
                       search key(prefix here)
            */
            
            result.push_back({});
            
            for(int i = start; i<min(start+3, n); i++) {
                if(products[i].find(prefix) < n) {
                    result.back().push_back(products[i]);
                }
            }
            
            index = start;
        }
        
        return result;
    }
};
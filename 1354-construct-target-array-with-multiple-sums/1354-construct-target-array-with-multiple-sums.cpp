class Solution {
public:
    bool isPossible(vector<int>& target) {
        auto s = accumulate(begin(target), end(target), (long long)0);
        priority_queue<int> pq(begin(target), end(target));
        while(pq.top()!=1)
        {
            int x=pq.top();
            pq.pop();
            s-=x;
            if(s<=0 || s>=x)
            {
                return false;
            }
            x=x%s;
            s+=x;
            pq.push(x>0?x:s);
        }
        
        return true;
    }
};
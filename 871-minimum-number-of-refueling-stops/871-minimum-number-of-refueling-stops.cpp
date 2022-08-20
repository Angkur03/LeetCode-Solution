class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int i = 0;
        int n = stations.size();
        int ans = 0;
        while(startFuel < target) {
            while(i<n && stations[i][0] <= startFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.size() == 0 ) {
                return -1;
            }
            startFuel = startFuel + pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
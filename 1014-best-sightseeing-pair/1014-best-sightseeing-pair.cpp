class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxValue = values[0] + 0;
        for(int j = 1; j < values.size(); j++)
        {
            maxScore = max(maxScore, maxValue + values[j] - j);
            maxValue = max(maxValue, values[j] + j);
        }
        return maxScore;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++) {
            if(isFound(matrix,target,i)) {
                return true;
            }
        }
        return false;
    }
    
    bool isFound(vector<vector<int>>& matrix, int target, int row) {
        int high = matrix[row].size() - 1;
        int low = 0;
        while(high >= low) {
            int mid = low + high;
            mid = mid / 2;
            //cout<<row<<" -> "<<mid<<" -> "<<matrix[row][mid]<<endl;
            if(matrix[row][mid] == target) {
                return true;
            }
            if(matrix[row][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
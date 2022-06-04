class Solution {
public:

vector<vector<string>> res;                    

bool isSafe(vector<string> &board, int row, int col) {
	int n = board.size();
	
	for(int i = col; i >= 0; --i)
		if(board[row][i] == 'Q')
			return false;

	
	for(int i = row, j = col; i >= 0 && j >= 0 ; --i, --j)
		if(board[i][j] == 'Q')
			return false;

	
	for(int i = row, j = col; i < n && j >= 0; ++i, --j)
		if(board[i][j] == 'Q')
			return false;
	
	return true;
}
    
void dfs(vector<string> &board, int col){   
	int n = board.size();
	if(col >= n)                            
	res.push_back(board);

	for(int row = 0; row < n; ++row){       
		if(isSafe(board, row, col)){
			board[row][col] = 'Q';          
			dfs(board, col + 1);            
			board[row][col] = '.';         
		}
	}
}
    
vector<vector<string>> solveNQueens(int n) {
   vector<string> board(n, string(n, '.'));   
   dfs(board, 0);                            
   return res;
}
};
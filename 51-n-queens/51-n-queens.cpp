class Solution {
public:
    bool issafe(int rows,int cols,int n,vector<string> board){
        int nrow = rows;
        int ncol = cols;
        //left upper diagonal
        while(rows>=0 && cols>= 0){
            if(board[rows][cols] == 'Q') return false;
            rows--;
            cols--;
        }
        rows = nrow;
        cols = ncol;
        while(cols>=0){
            if(board[rows][cols] == 'Q') return false;
            cols--;        
        }
        rows = nrow;
        cols = ncol;
        while(rows<n && cols>=0){
            if(board[rows][cols] == 'Q') return false;
            rows++;
            cols--;
        }
        return true;
    }
    
    
    void solve(int cols,int n,vector<vector<string>> &ans,vector<string> &board){
        if(cols == n){
            ans.push_back(board);
            return;
        }
        
        for(int rows = 0; rows<n; rows++){
            if(issafe(rows,cols,n,board)){
                board[rows][cols] = 'Q';
                solve(cols+1,n,ans,board);
                
                board[rows][cols] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string st(n,'.');
        for(int i = 0;i < n;i++){
            board[i] = st;
        }
        solve(0,n,ans,board);
        
        return ans;
    }
};
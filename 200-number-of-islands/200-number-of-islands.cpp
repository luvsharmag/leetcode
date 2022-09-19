class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];    
            if((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && grid[nrow][ncol] == '1' && !vis[nrow][ncol] ){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
                        }
            }
                
        }
        
    }
        
    
    int numIslands(vector<vector<char>> &grid){
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(row,vector<int> (col,0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
            
        }
        return cnt;
    }
};
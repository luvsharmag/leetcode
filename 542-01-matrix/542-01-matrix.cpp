class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    vector<vector<int>> dis(n,vector<int> (m,0));
    queue<pair<pair<int,int>,int>> q;
        int z = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if(grid[row][col] == 0){
               vis[row][col] = 1; 
               q.push({{row,col},0});
            }else{
                vis[row][col] = 0;
            }
        }        
    }   
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dis[row][col] = step;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol] = 1;        
                }

            }

        }
        return dis;
    }
};
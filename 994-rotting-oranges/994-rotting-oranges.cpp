
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
   int orangesRotting(vector<vector<int>> &grid){
        int n = grid.size();// row size
        int m = grid[0].size();// col size
        //step 1 push the rotten orange into queue
        queue<pair<pair<int,int>,int>> q;//it's is row,col,time
        int vis[n][m];
        int cntfrsh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntfrsh++;
                }
            }        
        }
        //step 2
        int tm = 0;
        // to find neighbours
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;//row
            int c = q.front().first.second;//col
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }

        }
        if(cntfrsh != cnt){
            return -1;
        }
        return tm;
    }
};


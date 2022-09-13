class Solution {
public:
        void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>> &ans,int                initcol,int newcolor,int delrow[],int delcol[]){
        
        ans[row][col] = newcolor;
        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initcol               &&ans[nrow][ncol] != newcolor){
               dfs(nrow,ncol,image,ans,initcol,newcolor,delrow,delcol); 
            }
        }
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initcolor = image[sr][sc];
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,image,ans,initcolor,color,delrow,delcol);
        return ans;
    }

};
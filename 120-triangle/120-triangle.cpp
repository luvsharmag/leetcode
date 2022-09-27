class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp,vector<vector<int>>& a,int n){
        if(i == n-1)return a[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int d = a[i][j] + f(i+1,j,dp,a,n);
        int dg = a[i][j] + f(i+1,j+1,dp,a,n);
        return dp[i][j] = min(d,dg);    
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,0,dp,triangle,n);
    }
};
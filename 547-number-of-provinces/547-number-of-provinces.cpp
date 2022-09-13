class Solution {
public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
        
//     }
    void dfs(int node,vector<int> adjl[],vector<int> &vis){
        vis[node] = 1;
        for(auto it: adjl[node]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(it,adjl,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adjm){
        // adjancey matrix to adjancey list
        int n = adjm[0].size();
        vector<int> adjl[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adjm[i][j] == 1 && i!= j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }

        }
        vector<int> vis(n,0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                cnt++;
                dfs(i,adjl,vis);
            }
        }
        return cnt;

    }
};
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
class Solution {
public:
    void dfs(int node,int &timer,unordered_map<int,list<int>> &adj,vector<int> &disc,vector<int> &low,int parent,unordered_map<int,bool> &vis,vector<vector<int>> &result){
        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue;
            }
            if(!vis[nbr]){
                dfs(nbr,timer,adj,disc,low,node,vis,result);
                low[node] = min(low[node],low[nbr]);
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                low[node] = min(low[node],disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        unordered_map<int,list<int>> adj;
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        vector<int> disc(n);
        vector<int> low(n);
        int parent = -1;
        unordered_map<int,bool> vis;
        for (int i = 0; i < n; i++)
        {
            disc[i] = -1;
            low[i] = -1;
        }
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i,timer,adj,disc,low,parent,vis,result);
            }
        }
        return result;
    }
};
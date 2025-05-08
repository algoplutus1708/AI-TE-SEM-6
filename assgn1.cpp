#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    if(!vis[node]){
        ans.push_back(node);
        for(auto it:adj[node]) {
            if(!vis[it]) dfs(it,adj,vis,ans);
        }
    }
}
void bfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]) {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}


int main(){
    int n,m;cin>>n>>m;
    vector<int>adj[n];
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n),ans;
    dfs(0,adj,vis,ans);
    bfs(0,adj,vis,ans);
    
}
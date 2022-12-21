class Solution {
public:
    bool checkBipartite(int s,vector<vector<int>> &adj,vector<int> &color){
        
        color[s]=1;
        
        queue<int> q;
        
        q.push(s);
        
        while(!q.empty()){
            
            int k=q.size();
            while(k--){
                int u=q.front();
                q.pop();
                for(int i=0;i<adj[u].size();i++){
                    if(color[adj[u][i]]==-1 && color[adj[u][i]]!=color[u]){
                        color[adj[u][i]]=1-color[u];
                        q.push(adj[u][i]);
                    }
                    else if(color[adj[u][i]]==color[u]){
                        return 0;
                    }
                }
            }
        }
        
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(n+1,-1);
        bool res=1;
        
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                res=checkBipartite(i,adj,color);
                if(res==0){
                    return 0;
                }
            }
        }
        
        return res;
    }
};
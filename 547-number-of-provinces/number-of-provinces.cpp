class Solution {
public:
    void bfs(int start,vector<vector<int>> & isConnected,vector<int> &vis){
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int it=0;it<isConnected.size();it++){
                if(isConnected[node][it] == 1 && !vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count +=1;
                bfs(i,isConnected,vis);
            }
        }
        return count;
    }
};
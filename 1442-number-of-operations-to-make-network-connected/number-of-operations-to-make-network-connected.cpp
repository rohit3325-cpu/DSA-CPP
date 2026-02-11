class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void setunion(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py)return;

        if(rank[px]<rank[py])parent[px]=py;
        else if(rank[px]>rank[py])parent[py]=px;
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        
         rank.resize(n,0);
         parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &e : connections){
            setunion(e[0],e[1]);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                components++;
            }
        }
        return components-1;
    }
};
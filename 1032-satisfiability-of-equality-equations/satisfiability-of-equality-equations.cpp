class Solution {
public:
vector<int> parent;
vector<int> rank;
   int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
   }
     void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;

        if (rank[pa] < rank[pb])
            parent[pa] = pb;
        else if (rank[pb] < rank[pa])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
           rank.assign(26, 0);
        parent.resize(26);
        for (int i = 0; i < 26; i++) parent[i] = i;

      
        for (auto& s : equations) {
            if (s[1] == '=') unite(s[0] - 'a', s[3] - 'a');
        }

        
        for (auto& s : equations) {
            if (s[1] == '!') {
                if (find(s[0] - 'a') == find(s[3] - 'a')) return false;
            }
        }

        return true;
    }
};
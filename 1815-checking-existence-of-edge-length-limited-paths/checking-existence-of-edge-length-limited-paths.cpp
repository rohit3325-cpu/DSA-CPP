class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);
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

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries
    ) {
       
        sort(edgeList.begin(), edgeList.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

       
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i][0], queries[i][1], queries[i][2], i});

       
        sort(q.begin(), q.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<bool> ans(queries.size());

        
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        int i = 0; 

        
        for (auto &query : q) {
            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int idx = query[3];

            while (i < edgeList.size() && edgeList[i][2] < limit) {
                unite(edgeList[i][0], edgeList[i][1], parent, rank);
                i++;
            }

            ans[idx] = (find(u, parent) == find(v, parent));
        }

        return ans;
    }
};


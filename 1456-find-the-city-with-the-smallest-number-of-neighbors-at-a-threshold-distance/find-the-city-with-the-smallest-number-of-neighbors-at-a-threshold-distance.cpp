class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int answerCity = -1;
        int minReachable = INT_MAX;

       
        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            dist[src] = 0;

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (auto &[v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold)
                    count++;
            }

            // Step 4: Choose city with:
            // smallest reachable count, tie → largest index
            if (count <= minReachable) {
                minReachable = count;
                answerCity = src;
            }
        }

        return answerCity;
    }
};

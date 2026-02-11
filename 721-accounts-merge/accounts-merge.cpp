class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pb] = pa;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;

        int idx = 0;

        // Assign index to each email
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                if (!emailToIndex.count(acc[i])) {
                    emailToIndex[acc[i]] = idx++;
                    emailToName[acc[i]] = name;
                }
            }
        }

        parent.resize(idx);
        for (int i = 0; i < idx; i++) parent[i] = i;

        // Union emails in same account
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                unite(emailToIndex[acc[1]], emailToIndex[acc[i]]);
            }
        }

        // Group emails by parent
        unordered_map<int, vector<string>> groups;
        for (auto &p : emailToIndex) {
            int root = find(p.second);
            groups[root].push_back(p.first);
        }

        // Build answer
        vector<vector<string>> res;

        for (auto &g : groups) {
            auto &emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> merged;
            merged.push_back(emailToName[emails[0]]);
            merged.insert(merged.end(), emails.begin(), emails.end());

            res.push_back(merged);
        }

        return res;
    }
};

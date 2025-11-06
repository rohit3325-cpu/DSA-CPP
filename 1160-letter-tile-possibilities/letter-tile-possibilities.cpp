class Solution {
public:
    int n;

    void solve(string &tiles, vector<bool> &used, unordered_set<string> &result, string &curr) {
        if (!curr.empty()) {
            result.insert(curr);
        }
        for (int i = 0; i < n; i++) {  
            if (used[i]) 
                continue;
            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles, used, result, curr); // explore further

            used[i] = false;           // backtrack
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";
        solve(tiles, used, result, curr);
        return result.size();
    }
};

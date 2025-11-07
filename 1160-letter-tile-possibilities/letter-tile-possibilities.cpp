#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string &tiles, vector<bool> &used, int &count, string curr) {

        for (int i = 0; i < tiles.size(); i++) {
            if(used[i]){
                continue;
            }
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;
            
            used[i] = true;
            count++; 
            helper(tiles, used, count, curr + tiles[i]);
            used[i] = false; 
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); 
        vector<bool> used(tiles.size(), false);
        int count = 0;
        helper(tiles, used, count, "");
        return count;
    }
};

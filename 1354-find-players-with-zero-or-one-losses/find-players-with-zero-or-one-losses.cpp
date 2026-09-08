class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost;
        for(int i=0;i<matches.size();i++){
            int lose=matches[i][1];
            lost[lose]++;
        }

        vector<int>ol;
        vector<int>zl;

        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int looser=matches[i][1];

            if(lost.find(winner)==lost.end()){
                zl.push_back(winner);
                lost[winner]=2;
            }
            if(lost[looser]==1){
               ol.push_back(looser);
            }
        }
        sort(ol.begin(),ol.end());
        sort(zl.begin(),zl.end());
        return{zl,ol};
    }
};
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m= players.size();
        int n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0;int j=0;int count=0;
        while(i<m && j<n){
            if(trainers[j]>=players[i]){
                count+=1;
                j++;
                i++;
            }else{
                j++;
            }
        }
        return count;
    }
};
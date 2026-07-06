class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
    [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];   // right descending
        return a[0] < b[0];       // left ascending
    });
    
    int n=intervals.size();
    //for traverse
    int maxright=0;
    int count=0;

      for(int i=0;i<n;i++){
          int left=intervals[i][0];
          int right=intervals[i][1];

          if(right>maxright){
            count +=1;
            maxright = right;
          }      

      }
      return count;
    }
};
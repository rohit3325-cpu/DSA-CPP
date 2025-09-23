class Solution {
public:
   
    vector<int>  findNSE(vector<int> &height){
        stack<int>st;
        vector<int> nse(height.size());
        for(int i=height.size()-1;i>=0;i--){
           while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
           }
           nse[i] = st.empty()? height.size():st.top();
           st.push(i);
        }
        return nse;
    }

      vector<int> findPSE(vector<int> &height){
        stack<int>st;
        vector<int> pse(height.size());
        for(int i=0;i<height.size();i++){
           while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
           }
           pse[i] = st.empty()?-1:st.top();
           st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int maxmi=0;
       for(int i=0;i<heights.size();i++){
        maxmi = max(maxmi,(heights[i] * (nse[i]-pse[i]-1)));
       }
       return maxmi;
    }
};
class Solution {
    public int maxProfit(int[] prices) {
        int maxi=0;
        int mini=prices[0];

        for(int i=0;i<prices.length;i++){
            if(mini>prices[i]){
                mini=prices[i];
            }else{
                maxi= Math.max(maxi,prices[i]-mini);
            }
        }
        return maxi;
    }
}
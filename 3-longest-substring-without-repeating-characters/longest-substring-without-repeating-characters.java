class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxi=0;
        HashMap<Character,Integer> mpp = new HashMap<>();
        int i=0;
        for(int j=0;j<s.length();j++){
            if(!mpp.containsKey(s.charAt(j))|| mpp.get(s.charAt(j))<i){
                mpp.put(s.charAt(j),j);
                maxi=Math.max(maxi,j-i+1);
            }else{
                i=mpp.get(s.charAt(j))+1;
                mpp.put(s.charAt(j),j);
            }
        }
        return maxi;
    }
}
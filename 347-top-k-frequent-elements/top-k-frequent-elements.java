class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> mpp=new HashMap<>();

        for(int ele:nums){
            mpp.put(ele,mpp.getOrDefault(ele,0)+1);
        }
        ArrayList<Map.Entry<Integer,Integer>> arr=new ArrayList<>(mpp.entrySet());

        arr.sort((a,b)->b.getValue()-a.getValue());

        int [] last=new int[k];
        for(int i=0;i<k;i++){
            last[i]=arr.get(i).getKey();
        }
        return last;
    }
}
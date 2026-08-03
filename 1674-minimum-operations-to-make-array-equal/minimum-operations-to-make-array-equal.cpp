class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=(2*i)+1;
        }
        if(n%2==0){
            int mid=(arr[n/2]+arr[(n/2)-1])/2;
            int count =0;
            for(int i=0;i<(n/2);i++){
                count+=(mid-arr[i]);
            }
            return count;
        }
    else{
        int mid=arr[n/2];
        int count =0;
        for(int i=0;i<n/2;i++){
            count+=(mid-arr[i]);
        }
        return count;
    }
    return 0;
    }
};
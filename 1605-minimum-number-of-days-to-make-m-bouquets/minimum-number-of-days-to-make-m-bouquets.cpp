class Solution {
public:
    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {
        // Check if we can make m bouquets with k adjacent flowers within timeLimit
        
        int cntr = 0;
        int bouquetCntr = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= timeLimit) {
                cntr++;
                if (cntr == k) {
                    bouquetCntr++;
                    cntr = 0;
                }
            } else {
                cntr = 0;
            }
        }
        return bouquetCntr >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            //can i make m bouquets with k adjacent flowers in mid no of days??

            if (f(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;

                //you cannot make m bouquets in mid no of days
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
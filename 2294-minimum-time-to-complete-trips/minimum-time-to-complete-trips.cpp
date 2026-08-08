class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    // Initialize the search range for minimum completion time
    long long l = 1;
    long long r = *min_element(begin(time), end(time)) * static_cast<long>(totalTrips);

    // Binary search for minimum completion time
    while (l < r) {
      // Calculate the midpoint of the search range
      const long long m = (l + r) / 2;
      // Count the number of tasks that can be completed within m time
      if (numTrips(time, m) >= totalTrips)
        // If enough tasks can be completed within m time, search for smaller time
        r = m;
      else
        // If not enough tasks can be completed within m time, search for larger time
        l = m + 1;
    }

    // Return the minimum completion time
    return l;
  }

  // Helper function to count the number of tasks that can be completed within a given time
  long numTrips(const vector<int>& times, long m) {
    // Calculate the sum of the floor division of m by each task completion time
    return accumulate(begin(times), end(times), 0L,
                      [&](long subtotal, int t) { return subtotal + m / t; });
  }
};
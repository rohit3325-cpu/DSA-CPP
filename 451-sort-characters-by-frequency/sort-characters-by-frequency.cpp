class Solution {
public:
    static bool comparator(pair<char, int>& p1, pair<char, int>& p2) {
        if (p1.second != p2.second)
            return p1.second > p2.second;   // Higher frequency first
        return p1.first < p2.first;         // Lexicographical order if frequencies are equal
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        // Store in vector
        vector<pair<char, int>> arr(freq.begin(), freq.end());

        // Sort
        sort(arr.begin(), arr.end(), comparator);

        // Build answer
        string ans;

        for (auto &p : arr) {
            ans.append(p.second, p.first);   // Append character p.second times
        }

        return ans;
    }
};
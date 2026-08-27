class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string prefix = "";

        for (int i = 0; i < n; i++) {
            int cur = target[i] - 'a';

            // Try to continue with the same character
            if (freq[cur] > 0) {
                prefix += target[i];
                freq[cur]--;
                continue;
            }

            // Cannot continue exactly.
            // Backtrack to find the rightmost position
            // where we can put a slightly larger character.
            for (int j = i; j >= 0; j--) {

                if (j < i)
                    freq[target[j] - 'a']++;

                int x = target[j] - 'a' + 1;

                while (x < 26 && freq[x] == 0)
                    x++;

                if (x < 26) {
                    string ans = target.substr(0, j);
                    ans += char('a' + x);
                    freq[x]--;

                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }

            return "";
        }

        // target itself can be formed, but it is not strictly greater.
        // Backtrack from the last position.
        for (int j = n - 1; j >= 0; j--) {

            freq[target[j] - 'a']++;

            int x = target[j] - 'a' + 1;

            while (x < 26 && freq[x] == 0)
                x++;

            if (x < 26) {
                string ans = target.substr(0, j);
                ans += char('a' + x);
                freq[x]--;

                for (int c = 0; c < 26; c++) {
                    while (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};
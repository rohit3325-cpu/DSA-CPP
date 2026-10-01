class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int i = 0, j = 0;

        while (i < name.size()) {

            if (j >= typed.size() || name[i] != typed[j])
                return false;

            char ch = name[i];

            int nameCount = 0;
            while (i < name.size() && name[i] == ch) {
                nameCount++;
                i++;
            }

            int typedCount = 0;
            while (j < typed.size() && typed[j] == ch) {
                typedCount++;
                j++;
            }

            if (typedCount < nameCount)
                return false;
        }

        return j == typed.size();
    }
};
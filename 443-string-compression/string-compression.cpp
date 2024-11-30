class Solution {
public:
    int compress(vector<char>& chars) {
        string res = "";
        char current = chars[0];
        res += current;
        int count = 1;
        int pos = 1;

        while (pos < chars.size()) {
            if (chars[pos] != current) {
                if (count > 1) res += to_string(count);
                current = chars[pos];
                res += current;
                count = 1;
            } else {
                count++;
            }

            pos++;
        }

        if (count > 1) res += to_string(count);

        for (int i = 0; i < res.length(); i++) {
            chars[i] = res[i];
        }

        return res.length();
    }
};
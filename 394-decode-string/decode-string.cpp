class Solution {
public:
    string decodeString(string s) {
        stack<char> all;

        for (char c : s) {
            if (c == ']') {
                string vec = "";
                while (all.top() != '[') {
                    vec += all.top();
                    all.pop();
                }
                all.pop();
                reverse(vec.begin(), vec.end());

                // sekarang topnya angka
                string numStr = "";
                while (!all.empty() && isdigit(all.top())) {
                    numStr += all.top();
                    all.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int num = stoi(numStr);
                for (int i = 0; i < num; i++) {
                    for (char ch : vec) {
                        all.push(ch);
                    }
                }
            } else {
                all.push(c);
            }
        }

        string result = "";
        while (!all.empty()) {
            result += all.top();
            all.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
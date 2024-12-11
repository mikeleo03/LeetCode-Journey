class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        stack<char> q;

        for (char c : s) {
            if (!q.empty()) {
                if (c == ')' && q.top() == '(') {
                    q.pop();
                } else if (c == ']' && q.top() == '[') {
                    q.pop();
                } else if (c == '}' && q.top() == '{') {
                    q.pop();
                } else {
                    q.push(c);
                }
            } else {
                q.push(c);
            }
        }

        return q.empty();
    }
};
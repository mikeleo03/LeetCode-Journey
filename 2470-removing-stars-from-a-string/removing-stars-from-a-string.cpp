class Solution {
public:
    string removeStars(string s) {
        stack<char> q;
        string res;

        for (int i = 0; i < s.size(); i++) {
            s[i] == '*' ? q.pop() : q.push(s[i]);
        }

        while (!q.empty()) {
            res.insert(res.begin(), q.top());
            q.pop();
        }

        return res;
    }
};
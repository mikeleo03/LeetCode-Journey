class Solution {
public:
    string removeStars(string s) {
        stack<char> q;
        string res;

        for (int i = 0; i < s.size(); i++) {
            s[i] == '*' ? q.pop() : q.push(s[i]);
        }

        while (!q.empty()) {
            res += q.top();
            q.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
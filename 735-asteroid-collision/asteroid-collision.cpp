class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int ast : asteroids) {
            if (ast > 0) {
                s.push(ast);
            } else {
                while (!s.empty() && s.top() > 0 && s.top() < -ast) {
                    s.pop();
                }

                if (s.empty() || s.top() < 0) s.push(ast);
                if (!s.empty() && s.top() == -ast) s.pop();
            }
        }

        vector<int> res(s.size());
        int i = s.size() - 1;
        while (!s.empty()) {
            res[i--] = s.top();
            s.pop();
        }
        
        return res;
    }
};
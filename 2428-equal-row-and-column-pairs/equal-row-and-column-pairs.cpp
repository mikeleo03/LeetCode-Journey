class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> order;
        int count = 0;

        // traverse row and column to check
        for (int i = 0; i < grid.size(); i++) {
            order[grid[i]]++;
        }

        for (int i = 0; i < grid.size(); i++) {
            vector<int> arr(grid.size());
            for (int j = 0; j < grid.size(); j++) {
                arr[j] = grid[j][i];
            }
            count += order[arr];
        }
        
        return count;
    }
};
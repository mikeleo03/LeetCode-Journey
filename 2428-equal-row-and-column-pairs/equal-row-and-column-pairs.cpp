class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> order;
        map<vector<int>, int> order2;
        int count = 0;

        // traverse row
        for (int i = 0; i < grid.size(); i++) {
            order[grid[i]]++;
        }

        // traverse column to check
        for (int i = 0; i < grid.size(); i++) {
            vector<int> arr(grid.size());
            for (int j = 0; j < grid.size(); j++) {
                arr[j] = grid[j][i];
            }

            // check is it exist on set
            order2[arr]++;
        }

        /* for (const auto& pair : order) {
            cout << "[";
            for (int i = 0; i < pair.first.size(); i++) {
                cout << pair.first[i] << ", ";
            }
            cout << "] ";
            cout << pair.second << endl;
        } */

        /* for (const auto& pair : order2) {
            cout << "[";
            for (int i = 0; i < pair.first.size(); i++) {
                cout << pair.first[i] << ", ";
            }
            cout << "] ";
            cout << pair.second << endl;
        } */

        for (auto it : order) {
            if (order2.find(it.first) != order2.end()) {
                count += (it.second * order2[it.first]);
            }
        }

        // cout << order.size() << " " << grid.size() * 2 << " " << count << endl;

        return count;
    }
};
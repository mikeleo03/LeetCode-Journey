#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand()
using namespace std;

class RandomizedSet {
private:
    vector<int> nums; // Store elements
    unordered_map<int, int> indices; // Map value -> index in nums

public:
    RandomizedSet() {}

    // Inserts a value. Returns true if the value was not already present.
    bool insert(int val) {
        if (indices.find(val) != indices.end()) {
            return false; // Value already exists
        }
        nums.push_back(val);              // Add value to the vector
        indices[val] = nums.size() - 1;   // Store the index of the value
        return true;
    }

    // Removes a value. Returns true if the value was present.
    bool remove(int val) {
        if (indices.find(val) == indices.end()) {
            return false; // Value does not exist
        }
        int idx = indices[val];           // Index of the value to remove
        int last = nums.back();           // Last element in the vector
        nums[idx] = last;                 // Move the last element to the removed position
        indices[last] = idx;              // Update the index of the moved element
        nums.pop_back();                  // Remove the last element
        indices.erase(val);               // Erase the value from the map
        return true;
    }

    // Returns a random element.
    int getRandom() {
        int randomIndex = rand() % nums.size(); // Generate a random index
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

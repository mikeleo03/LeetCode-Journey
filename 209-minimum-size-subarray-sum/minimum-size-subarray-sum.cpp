class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // awalnya front back nya 0
        // init sum = 0
        // while front blom sampe ujung dan back blom sampe ujung
        // kalo pos front sama pos backnya sama, cek nilainya sama kek target ga, klo sama return 1 (udh pasti paling kecil)
        // kalo beda, mulai extend window, update state sum
        // 
        // cek state sum
        // a. kalo lebih besar ato sama, update state size, trus shrink window

        // State
        int front = 0; int back = 0;
        int sum = nums[front]; 
        int minSize = INT_MAX;
        bool shrinked = false;

        while (front < nums.size() && back < nums.size()) {
            if (sum < target) {
                front++;
                if (front == nums.size()) {
                    return minSize == INT_MAX ? 0 : minSize;
                }
                sum += nums[front];
            } else {
                minSize = min(minSize, front - back + 1);
                sum -= nums[back];
                back++;
                shrinked = true;
            }

            cout << back << " " << front << " " << minSize << endl; 
        }

        // Return
        return minSize;
    }
};
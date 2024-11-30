class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int back = height.size() - 1;
        int area = 0;

        while (front < back) {
            // compare area dulu
            int currentArea = 0;

            // compare tinggi
            if (height[front] > height[back]) {
                currentArea = height[back] * (back - front); 
                back--;
            } else {
                currentArea = height[front] * (back - front); 
                front++;
            }

            if (currentArea > area) area = currentArea;
        }

        return area;
    }
};
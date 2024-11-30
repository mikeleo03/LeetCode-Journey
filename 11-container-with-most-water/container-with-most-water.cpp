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
            currentArea = min(height[back], height[front]) * (back - front); 
            height[front] > height[back] ? back-- : front++;

            if (currentArea > area) area = currentArea;
        }

        return area;
    }
};
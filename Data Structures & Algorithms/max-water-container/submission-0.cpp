class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int i=0;
        int j =n-1;
        int maxArea = INT_MIN;
        while(i<j){
            int smallerPillar =0;
            if(heights[i] < heights[j]) {
                smallerPillar =i;
            }
            else smallerPillar =j;
            int width = j-i;
            int area = heights[smallerPillar]*width;
            maxArea = max(maxArea,area);
            if(smallerPillar == i){
                i++;
            }
            else j--;
        }
        return maxArea;
    }
};

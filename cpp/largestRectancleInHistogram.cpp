class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) {
            return 0;
        }
        
        stack<int> bars;
        int maxArea = -1, currentArea;
        int i=0;
        for(;i<heights.size();i++) {
            if(bars.empty() || (heights[bars.top()] < heights[i])) {
                bars.push(i);
            }
           else{ 
               while(!bars.empty()&&heights[bars.top()] > heights[i]) {
                    int top = bars.top();
                    bars.pop();
                    if(bars.empty()) {
                        currentArea = heights[top]*i;
                    } else {
                        currentArea = heights[top] * (i - bars.top() -1);
                    }
                    
                    if(currentArea > maxArea) {
                        // cout<<currentArea<<"***";
                        maxArea = currentArea;
                    }
                }
                bars.push(i);
               }
        }
        
        while(!bars.empty()) {
             int top = bars.top();
             bars.pop();
             if(bars.empty()) {
                currentArea = heights[top]*i;
             } else {
                currentArea = heights[top] * (i -  bars.top() -1);
             }
             
             if(currentArea > maxArea) {
                maxArea = currentArea;
             }
        }
        return maxArea;
    }
};

//https://leetcode.com/problems/largest-rectangle-in-histogram/
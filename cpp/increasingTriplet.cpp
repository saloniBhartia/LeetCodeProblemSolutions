class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLtoR(n);
        vector<int> maxRtoL(n);
        
        minLtoR[0] = nums[0];
        for (int i = 1; i< n; i++) {
            minLtoR[i] = min(minLtoR[i-1], nums[i]);
        }
        
        maxRtoL[n-1] = nums[n-1];
        for (int i = n-2; i>-1; i--) {
            maxRtoL[i] = max(maxRtoL[i+1], nums[i]);
        }
        
        for (int i=0; i < n; i++) {
            if (minLtoR[i] < maxRtoL[i] && nums[i] != minLtoR[i] && nums[i] != maxRtoL[i])
                return true;
        }
        return false;
    }
};
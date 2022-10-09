class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        bool isFound = false;
        int val;
        for(int i=0;i<nums1.size();i++) {
            isFound = false;
            val = nums1[i];
            int j=0;
            for(;j<nums2.size();j++) {
                  if(nums2[j] == nums1[i]) {
                    isFound = true;
                } 
                if(isFound && nums2[j]>nums1[i]) {
                    nums1[i] = nums2[j];
                    break;
                }
            }
            if(nums1[i] == val) {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};
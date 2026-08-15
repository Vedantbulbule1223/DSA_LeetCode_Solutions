class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool iszero = true;
        int x = nums[0];
        if(nums[0] != 0){
            iszero = false;
        }
        for (int i = 1; i < n; i++) {
            x = x ^ nums[i];
            if (nums[i] != 0) {
                iszero = false;
            }
        }
        if(iszero == true){
            return 0;
        }

        if(x == 0) return n-1;
        else return n;
        return 0;
    }
};
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIND = 0, maxIND = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIND])
                minIND = i;

            if (nums[i] > nums[maxIND])
                maxIND = i;
        }

        int l = min(minIND, maxIND);
        int r = max(minIND, maxIND);

        int left = r + 1;
        int right = n - l;
        int both = (l + 1) + (n - r);

        return min({left, right, both});
    }
};
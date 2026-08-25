class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int t = k;
        int x = 500;
        while(x--){
            if (std::find(nums.begin(), nums.end(), k) == nums.end()){
                return k;
            }
            k = k+t;
        }
        return 0;
    }
};
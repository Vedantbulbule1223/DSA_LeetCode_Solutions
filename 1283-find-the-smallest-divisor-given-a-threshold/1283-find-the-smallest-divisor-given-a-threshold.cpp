class Solution {
public:
    int sum = 0;
    bool divide(vector<int>& nums, int dev , int threshold){
        
        sum = 0;
        for(auto i: nums){
            sum += (i + dev -1)/dev;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(begin(nums) , end(nums));
       
        int mid ;
        while (low < high) {
             mid = low + (high - low) / 2;

            if (divide(nums, mid , threshold)) {
                high = mid;
            } else {
                low = mid +1 ;
            }
        }

        return low;
    }
};
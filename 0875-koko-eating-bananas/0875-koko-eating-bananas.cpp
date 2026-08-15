class Solution {
public:
    bool canMake(vector<int>& bloomDay, int h, int day) {
       long long hr = 0;
        // int bouquets = 0;

        for (int x : bloomDay) {
          
            hr += (x + day - 1) / day;
        }

        return h >= hr;
    }

    int minEatingSpeed(vector<int>& bloomDay, int h) {
        // long long required = 1LL * m * k;

        // if (required > bloomDay.size())
        //     return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
class Solution {
public:
    int countCommas(int n) {

        long long ans = 0;

        long long p = 1000;

        while (p <= n) {
            ans += n - p + 1;
            p *= 1000;
        }

        return ans;
    }
};
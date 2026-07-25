class Solution {
public:
    int maxProduct(int n) {
        int l = 0, s = 0;

        while (n > 0) {
            int d = n % 10;

            if (d >= l) {
                s = l;
                l = d;
            } else if (d > s) {
                s = d;
            }

            n /= 10;
        }

        return l * s;
    }
};
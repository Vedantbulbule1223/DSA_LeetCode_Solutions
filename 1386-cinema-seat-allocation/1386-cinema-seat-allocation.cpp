class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each row
        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            // Only seats 2 to 9 matter
            if (seat >= 2 && seat <= 9) {
                rows[row] |= (1 << (seat - 2));
            }
        }

        int ans = (n - rows.size()) * 2;

        // Masks for:
        // 2,3,4,5
        int left = 0b1111;

        // 4,5,6,7
        int middle = 0b00111100;

        // 6,7,8,9
        int right = 0b11110000;

        for (auto &[row, mask] : rows) {
            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                ans += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                ans += 1;
            }
        }

        return ans;
    }
};
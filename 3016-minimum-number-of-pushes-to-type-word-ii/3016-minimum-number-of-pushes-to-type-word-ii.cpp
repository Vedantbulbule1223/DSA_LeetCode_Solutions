class Solution {
public:
    int minimumPushes(std::string word) {
        std::vector<int> arr(26, 0);
        for (char i : word) {
            arr[i - 'a']++;
        }

        std::sort(arr.begin(), arr.end(), std::greater<int>());
        int i = 0;
        int count = 0;
        int start = 1;
        int ans = 0;

        while (i < 26 && arr[i] != 0) {
            ans += (start * arr[i]);
            count++;
            if (count == 8) {
                start++;
                count = 0;
            }
            i++;
        }
        return ans;
    }
};

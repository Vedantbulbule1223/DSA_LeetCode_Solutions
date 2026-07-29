#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MAXK = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                mid.push_back(char('a' + i));
                break;
            }
        }

        vector<int> half(26, 0);
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
        }

        string left;

        if (!build(half, k, left))
            return "";

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }

private:
    bool build(vector<int>& freq, long long k, string& ans) {
        int rem = 0;
        for (int x : freq)
            rem += x;

        if (rem == 0)
            return true;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            freq[i]--;

            long long ways = multinomial(freq);

            if (k <= ways) {
                ans.push_back(char('a' + i));
                return build(freq, k, ans);
            }

            k -= ways;
            freq[i]++;
        }

        return false;
    }

    long long multinomial(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long long res = 1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0)
                continue;

            long long c = binom(total, cnt[i]);

            if (res >= MAXK || c >= MAXK)
                return MAXK;

            if (res > MAXK / c)
                return MAXK;

            res *= c;

            if (res >= MAXK)
                return MAXK;

            total -= cnt[i];
        }

        return res;
    }

    long long binom(int n, int k) {
        if (k > n)
            return 0;

        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            long long num = n - k + i;

            if (res > MAXK)
                return MAXK;

            res = (res * num) / i;

            if (res >= MAXK)
                return MAXK;
        }

        return res;
    }
};
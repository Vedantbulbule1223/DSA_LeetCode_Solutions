class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int>ch(26,0);
        int maxlen= 0;
        int left = 0;
       // ch[s[0]] = 1; 
        for(int r = 0; r < n; r++){
            ch[s[r] - 'a']++;

            while(ch[s[r] - 'a'] > 2 ){
                ch[s[left] -'a']--;
                left++;
            }
        maxlen =  max(maxlen , r -left +1);
        }
        return maxlen;

        
    }
};
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int maxcnt=0;
        int index=0;
        for(int i=0;i<n;i++){
                    int cnt=0;

            for(int j=0;j<mat[0].size();j++){
                cnt+=mat[i][j];
                
            }
            if(cnt>maxcnt){
                    maxcnt=max(maxcnt,cnt);
                    index=i;
                }   
        }
        return {index,maxcnt};
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product  = 1;
        int t = n;
        while(n > 0){
            int temp = n % 10;
            n= n /10;
            sum +=temp;
            product *= temp;

        }
        sum +=product;
        return t % sum == 0; 
    }
};
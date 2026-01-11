class Solution {
public:
    int mySqrt(int n) {
        int low = 1, high = n;
        while(low <= high){
            long long mid = (1LL * low + high) / 2;
            long long val = (1LL * mid * mid);

            if(val <= n){
                low = mid + 1;
            }
            else{
                high = mid - 1; 
            }
        }
        return high;
    }
};
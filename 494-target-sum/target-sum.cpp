class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totalsum += nums[i];
        }
        if(abs(target) > totalsum){
            return 0;
        }
        if((target + totalsum) % 2 != 0){
            return 0;
        }
        int newtarget = (target + totalsum) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(newtarget + 1, 0));
        dp[0][0] =1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<= newtarget; j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i - 1] <= j){
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][newtarget];
    }
};
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> prefixgcd(n);

        for(int i=0; i<n; i++){
            maxi = max(nums[i], maxi);
            prefixgcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixgcd.begin(), prefixgcd.end());
        long ans = 0;

        for(int i=0; i<n / 2; i++){
            ans += gcd(prefixgcd[i], prefixgcd[n - 1 - i]);
        }
        return ans;

    }
};
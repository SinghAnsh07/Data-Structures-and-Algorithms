class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int count =0;
        int ans =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                count++;
            }
            while (count > k) { 
                if (nums[left] == 0){
                    count--;    
                } 
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
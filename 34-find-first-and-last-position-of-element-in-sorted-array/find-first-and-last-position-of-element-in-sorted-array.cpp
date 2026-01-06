class Solution {
public:
    int lowerbound(vector<int> arr, int n, int x){
        int low = 0, high = n -1;
        int ans =n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperbound(vector<int> arr, int n, int x){
        int low =0 , high = n -1;
        int ans =n ;
        while(low <= high){
            int mid = (low + high) /2;
            if(arr[mid] > x){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();               // needed

        int lb = lowerbound(nums, n, target);

        if(lb == n || nums[lb] != target)
            return {-1, -1};

        int ub = upperbound(nums, n, target);

        return {lb, ub - 1};
    }
};
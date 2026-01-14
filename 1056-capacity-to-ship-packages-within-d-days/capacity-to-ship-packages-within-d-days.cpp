class Solution {
public:
    bool canship(vector<int> & weights, int days, int cap){
        int curr = 0, d = 1;
        for(int w : weights){
            if(curr + w > cap ){
                d++;
                curr = 0;
            }
            curr += w;
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;

            if (canship(weights, days, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};